#include "testApp.h"

#include "ofxSimpleGuiToo.h"
float bgColor[4];
bool saveImgs;

//--------------------------------------------------------------
void testApp::setup() {
	grabber.initGrabber(640, 480);
	greenscreen.setCropLeft(.2);
	greenscreen.setCropRight(.2);

	//gui.addTitle("SETTINGS");
	gui.addToggle("detail mask", greenscreen.doDetailMask);
	gui.addToggle("base mask", greenscreen.doBaseMask);
	gui.addToggle("chroma mask", greenscreen.doChromaMask);
	gui.addToggle("greenspill", greenscreen.doGreenSpill);


//	gui.addColorPicker("key color", bgColor);
	gui.addSlider("base mask strength", greenscreen.strengthBaseMask, 0.0, 1.f);
	gui.addSlider("chroma mask strength", greenscreen.strengthChromaMask, 0.0, 1.f);
	gui.addSlider("green spill strength", greenscreen.strengthGreenSpill, 0.0, 1.f);


	//gui.addTitle("CLIPPING");
	gui.addSlider("base mask black", greenscreen.clipBlackBaseMask, 0.0, 1.f);
	gui.addSlider("base mask white", greenscreen.clipWhiteBaseMask, 0.0, 1.f);
	gui.addSlider("detail mask black", greenscreen.clipBlackDetailMask, 0.0, 1.f);
	gui.addSlider("detail mask white", greenscreen.clipWhiteDetailMask, 0.0, 1.f);
	gui.addSlider("end mask black", greenscreen.clipBlackEndMask, 0.0, 1.f);
	gui.addSlider("end mask white", greenscreen.clipWhiteEndMask, 0.0, 1.f);

	//gui.addTitle("OUTPUT");
	gui.addFPSCounter();
	gui.addButton("save images", saveImgs);
	gui.addContent("camera", grabber);
	gui.addContent("base mask", baseMask);
	gui.addContent("detail mask", detailMask);
	gui.addContent("chroma mask", chromaMask);
	gui.addContent("mask", mask);

	gui.addContent("red sub", redSub);
	gui.addContent("green sub", greenSub);
	gui.addContent("blue sub", blueSub);
	//gui.addContent("keyed", greenscreen);

	gui.loadFromXML();

}

//--------------------------------------------------------------
void testApp::update() {
	grabber.update();
	if(grabber.isFrameNew())
		greenscreen.setPixels(grabber.getPixels());

	if(gui.isOn()) {
		greenscreen.setBgColor(ofColor(bgColor[0]*255, bgColor[1]*255, bgColor[2]*255));
		if(grabber.isFrameNew()) {
			//THIS PART IS REALLY SLOW!!!
			mask.setFromPixels(greenscreen.getMask());
			detailMask.setFromPixels(greenscreen.getDetailMask());
			baseMask.setFromPixels(greenscreen.getBaseMask());
			chromaMask.setFromPixels(greenscreen.getChromaMask());

			redSub.setFromPixels(greenscreen.getRedSub());
			greenSub.setFromPixels(greenscreen.getGreenSub());
			blueSub.setFromPixels(greenscreen.getBlueSub());
		}

		if(saveImgs){
			mask.save("save/mask.jpg");
			detailMask.save("save/detailMask.jpg");
			baseMask.save("save/baseMask.png");
			redSub.save("save/redSub.png");
			greenSub.save("save/greenSub.png");
			blueSub.save("save/blueSub.png");
			greenscreen.save("save/composition.png");
			saveImgs = false;
		}
	}

}

//--------------------------------------------------------------
void testApp::draw() {
	ofEnableAlphaBlending();
	greenscreen.draw(0, 0, greenscreen.getWidth(), greenscreen.getHeight());
	//grabber.draw(0, 0, 214, 160);
	greenscreen.drawBgColor();
	ofSetColor(0);
	ofDrawBitmapString("FPS "+ofToString(ofGetFrameRate()), 5, greenscreen.getHeight()+20);

	gui.draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	/*if(key == OF_KEY_DOWN)
		greenscreen.clipBlackEndMask -= .01;
	if(key == OF_KEY_UP)
		greenscreen.clipBlackEndMask += .01;
	if(key == OF_KEY_LEFT)
		greenscreen.clipWhiteEndMask -= .01;
	if(key == OF_KEY_RIGHT)
		greenscreen.clipWhiteEndMask += .01;
	*/

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

	if(key == ' ')
		gui.toggleDraw();

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	/*
	if(x== dragStart.x || y==dragStart.y)
		return;
	greenscreen.learnBgColor(grabber.getPixelsRef(), dragStart.x, dragStart.y, x-dragStart.x, y-dragStart.y);
	*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

	if(!gui.isOn())

		greenscreen.setBgColor(grabber.getPixels().getColor(x, y));

	ofColor c = greenscreen.getBgColor();
	bgColor[0] = c.r/255.;
	bgColor[1] = c.g/255.;
	bgColor[2] = c.b/255.;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {

}
