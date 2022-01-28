#include "stat.h"
#include "ui_stat.h"

stat::stat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stat::~stat()
{
    delete ui;
}
