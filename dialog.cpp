#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>

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
    if(fileName == ""){
        return;
    }
    colorDetect->setInputImage(fileName.toStdString());
    Mat img = colorDetect->getInputImage();
    cvtColor(img, img, CV_BGR2RGB);
    ui->ImageLabel->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}

void Dialog::on_ProcessButton_clicked()
{


    if(!colorDetect->getInputImage().data){
        QMessageBox::warning(this, "Error", "No Input Image Detected");

    }
    else{
        colorDetect->process();
        QMessageBox::information(this, "Success", "Image Processed Successfully");
        Mat img = colorDetect->getResult();
        ui->ImageLabel->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_Grayscale8)));
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

void Dialog::on_SelectColorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::green, this);
    if(color.isValid()){
        colorDetect->setTarget(color.red(), color.green(), color.blue());
    }
}

void Dialog::on_MinDistSlider_sliderMoved(int position)
{
    colorDetect->setMinDist(position);
}
