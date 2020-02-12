#include "requester.h"
#include "QTextCodec"

Requester::Requester(QObject *parent)
    : QObject(parent),
      manager(new QNetworkAccessManager)
{
    parser = std::make_shared<Parser>();

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    QUrl url("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto");
    request = std::make_shared<QNetworkRequest>(url);

    qDebug() << "Requester luotu";
}

Requester::~Requester()
{
    delete manager;
    qDebug() << "Requester poistettu";
}

QString Requester::DoRequest(QMap<QString, QString> config)
{
    parameters_ = config;

    try {
        requestData();
    }  catch (QString msg) {
            qDebug() << msg;
            std::move(msg);
    }

    return "";
}

void Requester::replyFinished(QNetworkReply *reply)
{
    qDebug() << "Reply saatu";
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString()<<"response";
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    }


    QString DataAsString = QTextCodec::codecForMib(106)->toUnicode(reply->readAll());

    /*
    QFile file2("../../Application/Data/DataString.txt");
    if(file2.open(QIODevice::WriteOnly)){
        QTextStream stream(&file2);
        stream<<DataAsString;
    }

    QFile *file = new QFile("../../Application/Data/data.txt");
    if(file->open(QIODevice::ReadWrite)){
        file->write(reply->readAll());
        file->close();
    }

    */

    reply->deleteLater();

    QMap<QString,QString> example = {{"fileToRead", "false"}, //false = "älä lue mitää"
                                     {"fileToWrite", "false"},//false = "älä kirjota mitää"
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","</td>"}};

    parser->fullParse(example,DataAsString);

    qDebug() << DataAsString;
    qDebug() << "Parsing completed";
}

void Requester::requestData()
{
    // Korvaa http pyynnöt https
    manager->setStrictTransportSecurityEnabled(true);

    multiPart = std::make_shared<QHttpMultiPart>();

    // Asettaa multipartin käyttämään form-dataa
    multiPart->setContentType(QHttpMultiPart::FormDataType);

    // Response headers
    QHttpPart referer;
    referer.setRawHeader("Referer", " https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto");
    QHttpPart origin;
    origin.setRawHeader("Origin", " https://www.finlandiahiihto.fi");
    QHttpPart connection;
    connection.setRawHeader("Connection", "keep-alive");
    QHttpPart upgrade;
    upgrade.setRawHeader("Upgrade-Insecude-Requests", "1");

    // Response parameters
    QHttpPart param1;
    param1.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"__EVENTTARGET\"");
    param1.setBody("dnn$ctr1025$Etusivu$cmdHaeTulokset");
    QHttpPart param2;
    param2.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"__VIEWSTATE\"");
    param2.setBody("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");
    QHttpPart param3;
    param3.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"__VIEWSTATEGENERATOR\"");
    param3.setBody("CA0B0334");
    QHttpPart param4;
    param4.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"__EVENTVALIDATION\"");
    param4.setBody("BSA7OzHk+TFahmfqr2OquSc4UXzPCqonI3auJtfiE4a0xIB2Zjo+jmH8rOKnrBd3apm7W1makouTZJH6kAJrWsRgWTX2jOTigoweRv9Gb0C9SFH5EKKJOgINUhD5EccXqSrYDQnlyz9heDJ8ayzx/OH4jsnhypM0+El2H9gZXupkbhcWSDyyCFBgd9rg/P6ASienV5CIH6RlItnyPb8HW/2Vl4haZqRDLXJ7yAzWkOo34bwGjVnl3XAZQ0wwLrjKy94zAVSy1S3iPWdHG0nM2ZydozxO2lCyHKNplwPw5IyB+TuhlHuLG8G0TwyxSY/h4Q0Dkrw8OgX9ezFb0J5HyA1pLHw/HL18Epga7Kxz57j0BHoh6K9AdaIv+NynGBHBlcJ/En5YbLi37YEUDgkDWachs3kLJqfQCZXxdK+QqAIA5jcuRxKlGpAafAkt7mvv5SNVdG4YbMSneYT93QFlAn/TZGek0OwEXPo2CJtJwaxZFxuI/m1uvafeofiHIeOSvcyuj0Xu2zwX7WcsojpBHp0b5395i8/7KG8lbjXcwWcdKNAMJDzlcGA4uXAKNa0oK0EMbau7HrcRhFyJskvT9x/8RTuVKT8HIOHeOzV1Qb2GFOM4UFEAuhXV6uaEAWKywCHhqaTcKbcLhlXwFSAVK+CeAGkkRfXvvK0YCGdcIt3/1Dp4HLVTbo11FDBIqIOLdlK3QOAx0e2VWu+EiI5Xes4bdAldQbrkoEZMkd8+CecdV8J/YuxJCZk/l+huqxMM32GQ2E9GaXaNERsd3vWr4Z6CwplhGlwqp4STcWchVP7M45dRGOD1QGAoN+fgLj5x63Gus7Fj1cWQb6OpA2i3GyjvDOsl0op7Y8MFqtAabKcVM33haDLvDAYCIMxqMUZDmIbns50sbNjeo4HxqwogL6xjebBOl0Zmd+Z2moiOR22li/yQom8Blpuijt2YTtfl8JBqSE08XUL87gY8/zFG8Vv+IO1wFrBvUydGh+41JlCATr4zPibFw+PtHuAbQXyHr8Puhoj2ngr7Ir1T54D0NKHAc1bOPJhDQJ+9XMcRwly2YqBsGwCRsqP+AJA5l/eGLKlkJvfqHytm1ETGkCltQfhy83W3uFtluopu0lqdsQ6+c8OOo4jDmvIGeGyYRxlYqhjtsiNHwJjAWkcTiHockAafQn6CVs8H0R2RHEUd2SqFV248dQ755MNdIRaTlTMxFq082ZOjR7lZkAqCg+P1vXEaFrvll3YXzTQiPcrOT2k+hgVvSV5Y1s9zdbMirCKIJhSoYUTNizgfi7VbR82D8U4yd5rLKYXOdEAsrMj6pMCAk94IfkVJ3UZH9PplxpLlUB8gxKmdoBfXaCGxfpvO3x0qhX15ejBGhpYDZB+XcDxrwv7sdZvF0KuRb6TXieF431X5ZVQO/W+qZ1R3Q86moMWtyJolrvVMGZ/DRCPySxeGtCQvihki5nqOPD/E74hlWgyRtnvteULXEnM/4Osq1v1ZFmHq4o1q5Zbxw0FEBWnTOcpnyjLw3OjCouvIBRh0HDfY+dku6Ys9eNtg/j+UhzjodFEk5uihiL2/a0W2tOMhJ6ze+dboIcSuhAo9F5l+O0ojdW/UOxfMJgcyAIuFLkD/OpCKLwEb8c4b5nU2IEFcPgscSx208TCg/DZCiUaQUAl0IfCaHCNeanrp0SKKnH4Pm7uPfXH0eWGTbZIiIh6U7Lyq7fV25aBixvBpeqAVjQLe+0dH46lxQ4vcLI1Gj3zKPzgzq7Qo/kQwfqhyMmT+yFD3nIEIXORNEJz9oWrIOBYjYiZldF4Oz5x9EEnmSWDOxcYnx7el2yAOlscQc5g0Rqqadg/2ZoI2GrMZm8a1t+/YE80JCIA98y5HuH+sdud4UpK8A/TM3Kev0PWmj5HmOr+VWC2Rqi4AmO8UAkFyNv1p6ARhK0kR8+TeWfZGGLqHjol2EKU3dCvFK9mfsJ7Nv+hLU+2Mi1qrfyhVu+yjQzFIvOrBdpFHGqVod8zZMiyiBtglzAWXcMOU81bWbwSdcAD9RkiYvgSu/uKd29qxESNtx9Xh9j1+/fps5WAsX3hAxs1V8y2/J8RjXQbh+If/fO+MCTxfhbjK1tOBi2Z4pLh4BLPl59hDY1mzp5e59/xOq3dogl5o8kIFCNQoqfZeAILi0rn4tkCbvIJp1/ropr31v2UQr/p3SK4PYBzsHTGd1gAX1u6Kc3tLvegE4ltxo/t/ys2Yiprey9WJi8X7bIlVj9XyFX+rexhwNJaUHcEwGVfZvCbWe+kcmiLwhLUB7iSIdDKd+oKX1qEHVW2Ejfn32mxH9MvWxQaxwTgjN7Lq7ZQc2UTTFLgXvdNy4cWV+DXn5AwcQ9hMB68tzf+GpgOuxmn0l+U14agVsaeKv6bR7WrwHPXLRyzAAiShcMCqCRIOWnECayWZJ4dWZgsXDJrEGIH0VcxBxA3gd9CytFIXc0kf2WnBgl5v08D4UU3yBezam14vi83Rt65xtyjiT3FrX8HOfsV9z9D4+Ro7wTd+EtANFdgSGJEEeOsLOweDdae006Sar5cfkGpx6mVPqlvbSwN+b/FFR9t9l6hPd9mkv2u1NyGxYI4ggCPBvcf8fuur0ygcxam5vuZZP3zuAsPEVR0zLprH2phF9hDKs1XUw4q6Q+6zg2jeePR3+dAtEg/uCO5fNOzECZObiVpT32aWjj0hd++gXPZIgnHYhUtu4KWDyZ0QRxNepoOGB/kebxsB9EM/N7pNgeHKEBTdIkZKd5DwRV7USHZtYnRgRzUpXsRsgzVw+e9bEuVX4oGAmxWzU5oaC4NwZpMjRI7UUipJTSGmTV0B6/VDPJJqvvffkGfpkZPk6BHFL4EZiR+dWAicHnNpMTMqiV8KRBx+LclPzPvZmLr5bVeUpbgD0ot0URbjhlRkOCL+/ETWNyuWvCLlCuTh81DeAR9e7gDiaLUGUB5y/6kKguGhkvMceKIvNp/0DuczBIUuwMVw6ggz8gcQAv0OqbWMG9061DGb7BoMv9p9k4tca6V+hlpCx/q8xyBFkQ8Mz3+bSS7vXF5HsuwHPXv/+NR9mH7xSCxHH9Eg/g+5WeGjKtBIcOeUmCPaTKV5UsuzJEJJpqScEvNll6onVuukFdlmQHUjMWwAKTmau3r7svVjqDTHw0cvokhNF0SnSNfCAoV6A9RftMsyxRXBWE1q1wEfeBhaI114EvzurpeUeZDeuJMXGt+m32WknHhJ4MJZ6SxjMU/+u1Voy2dowpAdov06QJBhtnYd/r9v3AKR+kFRCs6Nge/4THzz59pfAbh5tCj6Sgl4mze/FA+M/FbMczYhU+Lw7+HU5LnVNfqsF02pDYhDAkLU3YP6CMYpdQnysOtWH/F1ip45xu6bW2sPP/ESY0h2cySjwtAzXsiMiNXGGOiXcEaBAhc8+dTjgirvRSNE+qEcRx/KzFOpyR5Ay9+1OxgVdi1mM/vg+4HbrToOiqhTeA+gmVWSO5v4aUSyaLf/lydxbLWYgaTaRe+T/tuJPx1Qty4ElaiO6g9zLUqg7xU0oxx/IaY76FoMQwpumSzgNq17MXYr5y8kLpUnjiDaNJSD6ARRM4TPFc4oPAL1i3GaLzFez4GwlYbBTU56gA81ueQGN1PayTK+t6IvTQLcYbVYFmmmACkxW8QZJJk5I0cp45VuF5Ow5YSauxQUPpW7yJs8DzQqSM0/muGo8ph2JGQR2gt7m9X1BpybqU7tNBO7JEYrRADqvMvVHvEsLrfumUQ0N+FyKqn4+Sglp/hvkHMNqVOXtAU23HVveEoYV4jOHQC6ZnOVE6IPbwlxERtKmGpe1mqKkI2aNfhGOX37LabMgYRv3eoMgGXjxVXC2OsXYoqZY23AsXB65lTa6VUE3C1Hu7+Ob8QQgbKNtWNUOV4mjYAhDHqpHHS81eg8vjfY8Gn4qm1kleWMhmQ8H2i8h79aWXk/ENrXXt6lXDY6oHGMC1YBsrtzism3ced0hc1Tj6/cXWithICcj9325HaMKy59Finp8zBo4CnIjBgQMMO6avMJ7h43IyeKFqDQcsPQbOPD44H7GhrEQg1+a4QOHsJ6pxOSYkULgpnu4ncJruyy4d3AtWSKS7pJkrLP2pjjVJNc/zGqtd48WILTby97YQZOK2lIB8UUYDPkgrT0J5aD4bCqmWZliKCN9oniYvxDtDmqsKp0aoOOuX92/wkcTYqUgxFlZh2qRmP78pFuNtuINQhuiGF9+a0ZQ6eaYr5TdZf64JpZGbPJjqxjhZXXHYB4RnoyZM33EcyFfb1RX2apCblLyGJHce6Y56gUrpJOmlgZ4ce57ut+l6P1lRgp9VTagaB1PBq32B/n4ShIjb/jZ//PRrsm0ZnyMDedGC0ZscXUrPECDHykpF95aGLNFW37xMGCBhJjSGj2fn76Ojvma8ol3+pP3T4xR5H4CK3Y1BllHnp0zeuEENJpzbRezVIXkIqz7T7zLbKt7HtRUiqBloUgGDspyLRbkrhnd/3M12sJHJmEZcJfSfOwwqdkK/yx0sh1IAakq1cjvb5tMfvQCrDdwTTnSXUhOiNWKGcytmD61L70n4+EdYmQQyyrw+Vl1ZlOvIJsbyIYC4DcYf61pesUCa/utSCV9b+c1OU2Poi75AEgs+zSQnEFwA0ufZhWE5qFiWbodRKKCsm4QCJ60wV+gp1tW84YeK+QNf4y0xTjETr5cY97YZfrZ2Y2WdW5d14iC5y1YeGCvYocShIpoR+2cyv9YFgtgU9w4oejD5KKped0+5D3UhHF25PufV5X4QWDGWyEeMBu0/PN81RmxkbFs7XRlS5qaFB1ro5BwjXxgPh6JQc3ftFZBmQlOqfzpQ8fJQ0mp7/+BXd2gs3WOsyXBYfJoN/vgD9jq4kgG8gWl5/5VH6K97N9PYALSA4H1wsbw8DMhvbvUYiM9q421U04S6Q0Hz1iPY8EqyC4DWOGl4wFyBnj2cBdHWm6oNkYXZ44fUvfL25ASx0rioknJQcjcGR902dJ7gDi2nTuogvsRj6DK95uEnnQMuDrz40CfZQVttsmwl0S4yJ3doDv7U9g8i8w/zFZoqduoYZtLrdeBqI8qf2z99tU3VZE9okvyPnhgFejxS7cTPwQZlyQMBNlpq+8E60FfBS0TRqGu53cVjnL/P8D+JNqNb6ZBPc0kycCbLTr/qcsR8Z4Dtr7LXGzQj4xb02TBqm/nUtP5B9h0JEYTz1BrRBR/z9ne+t+iuh9hFgRWb+9n7s63iDNvWJG1Pfrj8PfS7Aa5HuaXr1tQbnZ7Ce2OLTHzZlUMC5ccTH6TKC4yIBgJLCHGldBVrrn1MjK2NF+jUP2ToTA2SJz8o1bOVn2eSpSeSAS72swV/GrD3s+lvxN40mWzMf8qyxbsInBg4hTYrZRGm0SQisJySj0DJq2wzU7WFW/4dR6mUUVpFbcfIyFxYUHz3BuzZ7wtbj1TbPAhrPmbDbhXYGHiNrxWKS3bB0F7s/hsdxmqzgzEcJIC5/n3mjbEsSv0y8LeEl2sbAmN3h9U8dNpFHAgToUUvnpy071SEbN8N2SgT+92NGbc53OvvtSVPRpBSnsqyOndg8e/qlDURS+H3WIX3WwbzFmr3NcKU+b4SJyR6X2tJEeQjAJYtwtuSJlNG8dbIBQ3W5A+rDRHQBuSIoILzns/ZLx0yRYhNmBhPufbZC+OLwLc+I/1B0+ytvYJgE6J4StZoM2kHPHBC89sIOVaNxhcF+YJX2dfXSEcUkmzWsWaT0mwrs15Ci338KQqP5kIsstP5A/AMqTUj5fVLLszd4J8GtPC6Ob4hZG9c2Hy1eYPm7CQZXgv+7/F2fPIWpU8j2yh3FNPbBSnOeo0QfnBG4tmqAoORvv6xOcQ8CpzVTLN7IhSlpncGtq79qaY3hKmIclcIiiO1PbxpyoEyF9xVcg/Z9HoZunISZmaaqlJSJb7U7M/gGDM41K5YSMAQ9mbOHKH1Ohym7tu82H2x1eh348ImMDOdZUkx6uOJnNnTZCnYfFeHja4cuhsqb46xeBxX8YfBSi8ZQubBEoFr1V8GH16eUTYCRhONU1iaXgU1YYbEIQZ3JxFzz40O8/d5NS+u2UEeM1sf6XSJjMch2Neei0+WV46VEaasw7cKv4U4LzGKa/DHnLANuVGpYzDhYw1+g/Eu2wDXvw8zPPpP2FdMp0SygaTf77sSWb3PTjiktNBCeidla1P+kzg/92LNgymA2tCR7pDlSD3rGvKXzST8XC/4meG7D6Z79wRijc5KLjLdk0g7M8Uf5GA6kmef5lJ3S5HLOQfn+AIE1q1MOu7IVPRCboWaSajDzCpLMQbTzIVcW04uZOiEq4KVog1YxdyEj32wgcJEHqW0gMH9I1vBztBkivbd9QgHSoDq1s10i3A8BpNsuLVFkjAUa3i4MtSK3KJXuETwMCgh9LH6BvMQCEcUEp6iABixMk6zJr5ShL0XdK8WFagXpcJNAWZ3F1V0MI+VBEKQISjVwLPRONRKDTH0QNbW2uJtP/JEEA5islfyoKKNOZExc4MyKP1kbcu5YZc3TA/cnAlgxzi9G2q7K4LMlFfB3Et+1vDP6N255T07ebQIREuyUonhdVjfphm2GfVoI7Znx1hNB7LWHTj6TpeY6+uR9BclKIrmxlPI8adJ5A6iBhJ2zwc2LPUODsucJGy6y3xi83Q9eP1WUOUgBcUHAUdK147P6uTxImK9tebhQ6e/zTU3MTYOyiDIlrAAMeP6SvuBBmiYR8+cNq+0FplvIfN3rSTsBIF0zK9lHPDmxgdWzFvIsTh8JzPIFdANop1EycbgTxjuk8jGedclMHIsFbspv0+YhHZPQX/1P716Hc072gc1qOSRYyRjeTpUJb6ZTsW0Vc+j3oGeRl1w24VA8qL1YU8xLMjdh7vIQ92D0lNLMKqlF1xT0zq5EpTQGhoP9gx00r8pRuXj5DEvT27FWsbOOgH8lLMUK1AdeJgP7BQ1rwgapYC9yo0fH4vBPmFATmGyXWbC0Yq5WMThr1NCDDK3T26mbCHg1fGQ5cC9IPE6myRi+EUssn9K3HCv4Ai3a7nD4OHpL+x12AZ8SRlGQoy+A+iI9o/JCc8JKUzWFAawC5M4YnNDmg5C6YSq+L6VUF1F7XDaPvpgzRoWIc2b8Q/ks69MgX+yAavy15CFjlQmnophf+eIMMXOP6AnK/hHbht519xOhaEbj+2PiZ05FZJ7zCXI5fadhdHaOYFN5bADnlkpyqeIJFn3qr8lf2AWDeX9w4+3lh4BXGViLmIbnsUkKgM6K/4kgFd0V8+/LnvF6UXpwK7yjeEnaoMIzR3wi2gLxsBdOb0Z5YE8NIQz39CUyCoMGH0bR+NwBcfr/kv7XnUYBeKA6paWMF1ipi91Nz6N7Ka9tJVWAaARoNHSI=");
    QHttpPart param5;
    param5.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$ddlVuosi2x\"");
    param5.setBody(parameters_.value("Vuosi").toUtf8());
    QHttpPart param6;
    param6.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$ddlMatka2x\"");
    param6.setBody(parameters_.value("Matka").toUtf8());
    QHttpPart param7;
    param7.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$chkLstSukupuoli2\"");
    param7.setBody(parameters_.value("Sukupuoli").toUtf8());
    QHttpPart param8;
    param8.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$ddlIkaluokka2\"");
    param8.setBody(parameters_.value("Ikaluokka").toUtf8());
    QHttpPart param9;
    param9.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$txtHakuEtunimi2\"");
    param9.setBody(parameters_.value("Etunimi").toUtf8());
    QHttpPart param10;
    param10.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$txtHakuSukunimi2\"");
    param10.setBody(parameters_.value("Sukunimi").toUtf8());
    QHttpPart param11;
    param11.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$txtHakuPaikkakunta2\"");
    param11.setBody(parameters_.value("Paikkakunta").toUtf8());
    QHttpPart param12;
    param12.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$ddlKansalaisuus2x\"");
    param12.setBody(parameters_.value("Kansalaisuus").toUtf8());
    QHttpPart param13;
    param13.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"dnn$ctr1025$Etusivu$txtHakuJoukkue2\"");
    param13.setBody(parameters_.value("Joukkue").toUtf8());

    // Parametrien lisäys multiparttiin
    multiPart->append(referer);
    multiPart->append(origin);
    multiPart->append(connection);
    multiPart->append(upgrade);
    multiPart->append(param1);
    multiPart->append(param2);
    multiPart->append(param3);
    multiPart->append(param4);
    multiPart->append(param5);
    multiPart->append(param6);
    multiPart->append(param7);
    multiPart->append(param8);
    multiPart->append(param9);
    multiPart->append(param10);
    multiPart->append(param11);
    multiPart->append(param12);
    multiPart->append(param13);

    // Post request
    manager->post(*request, multiPart.get());

    qDebug() << "Post request suoritettu";
}

