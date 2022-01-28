#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>

class notification
{
private:
    int num;
    QString text,titre;
public:
    notification();
    notification(QString,QString);
    void afficher();
};

#endif // NOTIFICATION_H
