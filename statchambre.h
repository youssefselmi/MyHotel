#ifndef STATCHAMBRE_H
#define STATCHAMBRE_H

#include <QDialog>

namespace Ui {
class StatChambre;
}

class StatChambre : public QDialog
{
    Q_OBJECT

public:
    explicit StatChambre(QWidget *parent = nullptr);
    ~StatChambre();
void makePolt();
private:
    Ui::StatChambre *ui;
};

#endif // STATCHAMBRE_H
