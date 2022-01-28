#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include "connexion.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    login l;
    w.setWindowTitle("MY HOTEL");
    l.setWindowTitle("MY HOTEL");
    bool test=c.ouvrirconnexion();
    if(test)
    {l.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}



    return a.exec();
}
