#ifndef DIALOG_H
#define DIALOG_H
#include "colordetectorcontroller.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_ChooseButton_clicked();

    void on_ProcessButton_clicked();

    void on_ShowProcessedButton_clicked();

    void on_ShowOriginalButton_clicked();

    void on_SelectColorButton_clicked();

    void on_MinDistSlider_sliderMoved(int position);

private:
    ColorDetectorController* colorDetect;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
