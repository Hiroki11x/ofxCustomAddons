#pragma once

#include "ofMain.h"
#include "ofxHTTP.h"

<<<<<<< HEAD
class ofApp: public ofBaseApp{
=======
#define M_WIDTH 200
#define M_HEIGHT 150

class ofApp: public ofBaseApp
{
>>>>>>> 7fa5b946ff0fc95eac04cb7cb657d3e19111e5c1
public:
    void setup();
    void update();
    void draw();

    ofx::HTTP::SimpleIPVideoServer server;
    ofVideoGrabber mVideoGrabber;
};
