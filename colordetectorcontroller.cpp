#include "colordetectorcontroller.h"
#include <QMessageBox>
ColorDetectorController::ColorDetectorController()
{
    cDetect = new ColorDetector();
}

int ColorDetectorController::getMinDist(){
   return cDetect->getMinDist();
}
void ColorDetectorController::getTarget(unsigned char red, unsigned char green, unsigned char blue){
    Vec3b color = cDetect->getTarget();
    red = color[2];
    green = color[1];
    blue = color[0];
}
void ColorDetectorController::setMinDist(int minDist){
    cDetect->setMinDist(minDist);
}
void ColorDetectorController::setTarget(unsigned char red, unsigned char green, unsigned char blue){
    cDetect->setTarget(red, green, blue);
}
bool ColorDetectorController::setInputImage(std::string fileName){
    image = imread(fileName);
    if(!image.data){
        return false;
    }
    return true;
}
const Mat ColorDetectorController::getInputImage(){
    return image;
}
void ColorDetectorController::process(){
    result = cDetect->process(image);
}
const Mat ColorDetectorController::getResult(){
    return result;
}
ColorDetectorController::~ColorDetectorController(){
    delete cDetect;
}
