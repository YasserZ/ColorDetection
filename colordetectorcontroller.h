#ifndef COLORDETECTORCONTROLLER_H
#define COLORDETECTORCONTROLLER_H
#include "colordetector.h"

class ColorDetectorController
{
private:
    ColorDetector* cDetect;
    Mat image;
    Mat result;
public:
    ColorDetectorController();
    void setMinDist(int minDist);
    int getMinDist();
    void setTarget(unsigned char red, unsigned char green, unsigned char blue);
    void getTarget(unsigned char red, unsigned char green, unsigned char blue);
    bool setInputImage(std::string fileName);
    const Mat getInputImage();
    void process();
    const Mat getResult();
    ~ColorDetectorController();
};

#endif // COLORDETECTORCONTROLLER_H
