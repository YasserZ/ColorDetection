#include "colordetector.h"

ColorDetector::ColorDetector(){
    minDist = 100;
    target[2] = target[1] = target[0] = 0;
}

int ColorDetector::getMinDist(){
    return minDist;
}
Vec3b ColorDetector::getTarget(){
    return target;
}
void ColorDetector::setMinDist(int minDist){
    this->minDist = minDist;
}
void ColorDetector::setTarget(unsigned char red, unsigned char green, unsigned char blue){
    target[0] = blue;
    target[1] = green;
    target[2] = red;
}
void ColorDetector::setTarget(Vec3b target){
    this->target = target;
}
int ColorDetector::getDistance(const Vec3b& color){
    return abs(color[0] - target[0]) + abs(color[1] - target[1]) + abs(color[2] - target[2]);
}
Mat ColorDetector::process(const Mat& img){
    result.create(img.rows, img.cols, CV_8U);
    Mat_<Vec3b>::const_iterator it = img.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator itend = img.end<Vec3b>();
    Mat_<uchar>::iterator itout = result.begin<uchar>();
    for(; it != itend; ++it,++itout){
        if(getDistance(*it) < minDist){
            *itout = 255;
        }
        else{
            *itout = 0;
        }

    }
    return result;
}
