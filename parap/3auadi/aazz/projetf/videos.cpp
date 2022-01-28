#include "videos.h"
#include "ui_videos.h"

videos::videos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::videos)
{
    ui->setupUi(this);
}

videos::~videos()
{
    delete ui;
}
