#ifndef VIDEOS_H
#define VIDEOS_H

#include <QDialog>

namespace Ui {
class videos;
}

class videos : public QDialog
{
    Q_OBJECT

public:
    explicit videos(QWidget *parent = nullptr);
    ~videos();

private:
    Ui::videos *ui;
};

#endif // VIDEOS_H
