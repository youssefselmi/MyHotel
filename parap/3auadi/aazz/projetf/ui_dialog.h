/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>


QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QLineEdit *recherche_grade;
    QLineEdit *recherche_presence;
    QPushButton *pushButton_3;
    QLineEdit *recherche_salaire;
    QLineEdit *recherche_cin;
    QPushButton *pushButton_2;
    QLineEdit *recherche_date;
    QTableView *tabpersonnel;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QDoubleSpinBox *bx_x;
    QDoubleSpinBox *bx_y;
    QPushButton *btn_add;
    QPushButton *btn_clear;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(908, 606);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 260, 81, 23));
        recherche_grade = new QLineEdit(Dialog);
        recherche_grade->setObjectName(QString::fromUtf8("recherche_grade"));
        recherche_grade->setGeometry(QRect(720, 90, 171, 20));
        recherche_presence = new QLineEdit(Dialog);
        recherche_presence->setObjectName(QString::fromUtf8("recherche_presence"));
        recherche_presence->setGeometry(QRect(720, 130, 171, 20));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 110, 75, 23));
        recherche_salaire = new QLineEdit(Dialog);
        recherche_salaire->setObjectName(QString::fromUtf8("recherche_salaire"));
        recherche_salaire->setGeometry(QRect(720, 170, 171, 20));
        recherche_cin = new QLineEdit(Dialog);
        recherche_cin->setObjectName(QString::fromUtf8("recherche_cin"));
        recherche_cin->setGeometry(QRect(720, 50, 171, 20));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(720, 260, 81, 23));
        recherche_date = new QLineEdit(Dialog);
        recherche_date->setObjectName(QString::fromUtf8("recherche_date"));
        recherche_date->setGeometry(QRect(720, 210, 171, 20));
        tabpersonnel = new QTableView(Dialog);
        tabpersonnel->setObjectName(QString::fromUtf8("tabpersonnel"));
        tabpersonnel->setGeometry(QRect(10, 50, 531, 201));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 170, 75, 23));
        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(600, 140, 75, 23));
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(360, 260, 62, 22));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(430, 260, 113, 20));
        pushButton_6 = new QPushButton(Dialog);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(610, 260, 75, 23));
        pushButton_7 = new QPushButton(Dialog);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(600, 80, 75, 23));
        pushButton_8 = new QPushButton(Dialog);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(600, 50, 75, 23));
            bx_x = new QDoubleSpinBox(Dialog);
        bx_x->setObjectName(QString::fromUtf8("bx_x"));
        bx_x->setGeometry(QRect(60, 570, 62, 22));
        bx_y = new QDoubleSpinBox(Dialog);
        bx_y->setObjectName(QString::fromUtf8("bx_y"));
        bx_y->setGeometry(QRect(180, 570, 62, 22));
        btn_add = new QPushButton(Dialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(270, 570, 75, 23));
        btn_clear = new QPushButton(Dialog);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(370, 570, 75, 23));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 570, 47, 14));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 570, 47, 14));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "modifier", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "Afficher", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "supprimer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "Print", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dialog", "PDF", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Dialog", "CIN", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Dialog", "GRADE", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Dialog", "PRESENCE", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Dialog", "SALAIRE", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Dialog", "DATE CONTRAT", nullptr));

        pushButton_6->setText(QCoreApplication::translate("Dialog", "recherche", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dialog", "Trier Presence", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dialog", "Trier CIN", nullptr));
        btn_add->setText(QCoreApplication::translate("Dialog", "ajouter", nullptr));
        btn_clear->setText(QCoreApplication::translate("Dialog", "supprimer", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "X", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
