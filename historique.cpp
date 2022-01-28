#include "historique.h"
//#include "equipement.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include "qcustomplot.h"



historique::historique()
{
mFilename="F:/projet Qt xteam integration/projetv0/historique.txt";
}
QString historique::read()
{
QFile mFile(mFilename);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}
void historique::write(QString text)
{
    QString aux=read();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
QFile mFile(mFilename);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream out (&mFile);


aux+=text;
out << aux << "\n";
mFile.flush();
mFile.close();

}
