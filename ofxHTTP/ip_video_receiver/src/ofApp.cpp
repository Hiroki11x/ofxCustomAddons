

#include "ofApp.h"


void ofApp::setup(){
    ofSetFrameRate(0);

    //岩瀬 192.168.145.238
    cap = cv::VideoCapture("http://192.168.145.238:7890/ipvideo.mjpg");
    img.allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);

    //長田 192.168.157.5
    cap2 = cv::VideoCapture("http://192.168.157.5:7890/ipvideo.mjpg");
    img2.allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);

    //奥村 192.168.145.27 (KeiのPCの設定的に、きつい)
    cap3 = cv::VideoCapture("http://192.168.145.27:7890/ipvideo.mjpg");
    img3.allocate(CAM_WIDTH, CROP_HEIGHT, OF_IMAGE_COLOR);
}


void ofApp::update(){
    if ( cap.isOpened() ){
        cap >> frame;
        if(frame.empty()){
            cout << "empty" << endl;
            exit();
        }else{
            img.setFromPixels(frame.ptr(), frame.cols, frame.rows, OF_IMAGE_COLOR,FALSE);
        }
        if(cv::waitKey(30) >= 0) exit();
    }


    if ( cap2.isOpened() ){
        cap2 >> frame2;
        if(frame2.empty()){
            cout << "empty" << endl;
            exit();
        }else{
            img2.setFromPixels(frame2.ptr(), frame2.cols, frame2.rows, OF_IMAGE_COLOR,FALSE);
        }
        if(cv::waitKey(30) >= 0) exit();
    }

    if (cap3.isOpened() ){
        cap3 >> frame3;
        if(frame3.empty()){
            cout << "empty" << endl;
            exit();
        }else{
            img3.setFromPixels(frame3.ptr(), frame3.cols, frame3.rows, OF_IMAGE_COLOR,FALSE);
        }
        if(cv::waitKey(30) >= 0) exit();
    }
}


void ofApp::draw(){
    if(img.isAllocated()){
        img.draw(0,0,ofGetWidth()/2,ofGetHeight());
    }

    if(img2.isAllocated()){
        img2.draw(ofGetWidth()/2,0,ofGetWidth()/2,ofGetHeight()/2);
    }

    if(img3.isAllocated()){
        img3.draw(ofGetWidth()/2,ofGetHeight()/2,ofGetWidth()/2,ofGetHeight()/2);
    }

    ofSetWindowTitle("FPS: "+ofToString(ofGetFrameRate()));
}
