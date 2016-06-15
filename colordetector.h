#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

using namespace cv;
class ColorDetector{
private:
    int minDist;
    Vec3b target;
    Mat result;
public:
    ColorDetector();
    void setMinDist(int minDist);
    int getMinDist();
    void setTarget(Vec3b target);
    void setTarget(unsigned char red, unsigned char green, unsigned char blue);
    Vec3b getTarget();
    Mat process(const Mat &img);
    int getDistance(const Vec3b &color);

};


#endif // COLORDETECTOR_H
