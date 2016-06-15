#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    colorDetect = new ColorDetectorController();
    connect(ui->CancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ChooseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Image", "C:\\", "Image Files(*.png *.jpg *.gif)");
    colorDetect->setInputImage(fileName.toStdString());
}

void Dialog::on_ProcessButton_clicked()
{
    QString red = ui->RedSpinBox->text();
    QString green = ui->GreenSpinBox->text();
    QString blue = ui->BlueSpinBox->text();

    if(red != "" && green != "" && blue != ""){
        colorDetect->setTarget(red.toInt(), green.toInt(), blue.toInt());
    }
    if(!colorDetect->getInputImage().data){
        QMessageBox::warning(this, "Error", "No Input Image Detected");
    }
    else{
        colorDetect->process();
        QMessageBox::information(this, "Success", "Image Processed Successfully");
    }

}

void Dialog::on_ShowProcessedButton_clicked()
{
    Mat res = colorDetect->getResult();
    if(!res.data){
        QMessageBox::warning(this, "Warning", "No Processing occurred!");

    }
    else{
        namedWindow("Processed Image", WINDOW_AUTOSIZE);
        imshow("Processed Image", res);
    }

}

void Dialog::on_ShowOriginalButton_clicked()
{
    Mat res = colorDetect->getInputImage();
    if(!res.data){
        QMessageBox::warning(this, "Warning", "No Data!");
    }
    cvtColor(res, res, CV_BGR2RGB);
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", res);


}
