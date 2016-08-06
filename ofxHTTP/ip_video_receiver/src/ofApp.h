

#pragma once

#define CAM_WIDTH 960
#define CROP_HEIGHT 720

//#include "ofxOpenCv.h"
#include <opencv2/opencv.hpp>
#include "ofMain.h"
//#include "ofxHTTP.h"
//#include "ofxCv.h"


class ofApp: public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    cv::VideoCapture cap;
    cv::Mat frame;

    cv::VideoCapture cap2;
    cv::Mat frame2;

    cv::VideoCapture cap3;
    cv::Mat frame3;
    
//    ofVideoPlayer player;
    ofImage img;
    ofImage img2;
    ofImage img3;
};
