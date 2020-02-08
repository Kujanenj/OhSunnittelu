#ifndef BACKEND_H
#define BACKEND_H
#include <QString>
#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    //QML Accessible methods:
    Q_INVOKABLE void searchButtonClicked();

    const QString text();
    void setText(const QString &text);

signals:
    void textChanged(const QString & text);

public slots:

private:
    QString mText;
    //void setFieldText(QString value);

    QString fieldText;
};

#endif // BACKEND_H
