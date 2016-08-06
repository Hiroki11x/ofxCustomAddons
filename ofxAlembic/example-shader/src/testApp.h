#pragma once

#include "ofMain.h"
#include "ofxAlembic.h"
#include "AutoLoadShader.hpp"
class testApp : public ofBaseApp{
private:
    ofEasyCam cam;
    ofxAlembic::Reader abc;
    AutoLoadShader shader;
public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};