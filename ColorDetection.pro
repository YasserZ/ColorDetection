#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T03:39:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorDetection
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    colordetector.cpp \
    colordetectorcontroller.cpp

HEADERS  += dialog.h \
    colordetector.h \
    colordetectorcontroller.h

FORMS    += dialog.ui

INCLUDEPATH += C:\\OpenCV-2.3.1\\install\\include
LIBS += -LC:\\OpenCV-2.3.1\\bin \
    libopencv_calib3d231d \
    libopencv_contrib231d \
    libopencv_core231d\
    libopencv_features2d231d\
    libopencv_flann231d\
    libopencv_gpu231d   \
    libopencv_highgui231d\
    libopencv_imgproc231d\
    libopencv_legacy231d\
    libopencv_ml231d\
    libopencv_objdetect231d\
    libopencv_video231d
