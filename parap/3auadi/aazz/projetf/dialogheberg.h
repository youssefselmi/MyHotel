#ifndef DIALOGHEBERG_H
#define DIALOGHEBERG_H

#include <QDialog>

namespace Ui {
class DialogHeberg;
}

class DialogHeberg : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHeberg(QWidget *parent = nullptr);
    ~DialogHeberg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView1_activated(const QModelIndex &index);

    void on_Tri1_clicked();

    void on_pushButton_4_clicked();

    void on_update_clicked();

    void on_search_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pdf_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::DialogHeberg *ui;
};

#endif // DIALOGHEBERG_H
