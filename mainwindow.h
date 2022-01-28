#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "personnel.h"
#include "affichagepersonnel.h"
#include "affichage.h"
#include "demande.h"
#include "evenement.h"
//#include "statistique.h"
#include "mainwindowvideo.h"
#include "videos.h"
#include "statchambre.h"
#include "materiaux.h"
#include "statevenement.h"
#include "animation.h"
#include "pdf.h"
#include "equipement.h"
#include "statistiq.h"
#include <QDialog>
#include"connexion.h"
#include "qcustomplot.h"
#include <QWidget>
//#include "statyoussef.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void makePolt();
    void makePolt1();
    void makePolt2();
    void makePlot_2();
    QMenu *criarMenu();
private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    //void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    //void on_pushButton_21_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    //void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    //void on_TYPE_DEMANDE_activated(const QString &arg1);

    void on_pushButton_33_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_tabpersonnel_activated(const QModelIndex &index);
    void on_tabdemande_activated(const QModelIndex &index);
    void on_tableView_2_activated(const QModelIndex &index);


    void on_pushButton_30_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_36_clicked();

    void on_supprimer_demande_clicked();

    void on_modifier_demande_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_35_clicked();

    void on_recherche_demande_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_34_clicked();


    //void on_comboBox_3_activated(const QString &arg1);

void on_tabhebergement_activated(const QModelIndex &index);
//void on_tableView_activated(const QModelIndex &index);
void on_tablefiras_activated(const QModelIndex &index);

    void on_pushButton_41_clicked();

    void on_Tri1_clicked();

    void on_pushButton_43_clicked();

    void on_update_clicked();

    void on_pdf_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_45_clicked();

    void on_delete_2_clicked();

    void on_update_2_clicked();

    void on_tri_clicked();

    void on_Csearch_clicked();

    void on_print_clicked();

    void on_pdf_2_clicked();

    void on_video_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_58_clicked();

void on_tableView_3_activated(const QModelIndex &index);

void on_pushButton_57_clicked();

void on_pb_ajouter_clicked();

void on_resaisir_clicked();

void on_pb_supprimer_5_clicked();

void on_Actualiser_3_clicked();

void on_imprimer_paie_clicked();

void on_expot_clicked();

void on_pdf_3_clicked();

void on_pb_modifier_clicked();

void on_trie_asc_clicked();

void on_Rechercher_2_clicked();

void on_trie_desc_clicked();
void on_tabanime_activated(const QModelIndex &index);

void on_pb_ajout_clicked();

void on_actualiser_3_clicked();

void on_pb_supprimer_3_clicked();

void on_Actualiser_2_clicked();

void on_pdf_4_clicked();

void on_exporter_clicked();

void on_pb_modifier_2_clicked();

void on_trie_asc_2_clicked();

void on_trie_desc_2_clicked();

void on_Rechercher_3_clicked();
 void on_tabequipement_activated(const QModelIndex &index);

 void on_statistique_clicked();

 void on_actualiser_amine_clicked();

 void on_excel1_clicked();

 void on_excel2_clicked();

private:
    Ui::MainWindow *ui;
    affichagepersonnel *secPage;
    Affichage *secPag;
    PERSONNEL tmppersonnel;
    demande tmpdemande;

    //Statistique *statistique ;

    MainWindowvideo *video;
    StatChambre *statCH;
    statistiq *statYO;
    //statyoussef *staty;
     materiaux tmpM ;
 evenement tmpE ;
 statevenement *secPa;
 Animation tmpanim;
 Animation tmpanime;
  pdf *go;

 Equipement tmpequip;
 Equipement tmpequipement;

  QSystemTrayIcon *trayIcon;


};
#endif // MAINWINDOW_H
