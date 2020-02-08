#include "backend.h"
#include <QDebug>

void Backend::searchButtonClicked()
{
    //Call the requester maybe??
    qDebug()<<"UI Search button clicked";
}

Backend::Backend(QObject *parent) : QObject(parent)
{

}

const QString Backend::text(){
    return mText;
}

void Backend::setText(const QString &text){
    if(text == mText)
        return;
    mText = text;
    emit textChanged(mText);
    qDebug()<<"Text input field value has been modified via UI";
}
