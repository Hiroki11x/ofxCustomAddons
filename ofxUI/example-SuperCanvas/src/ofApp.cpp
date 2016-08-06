#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{    
	ofSetVerticalSync(true); 
	ofEnableSmoothing();
    
    //set some sketch parameters
    //Background Color 
    red = 233; 
    blue = 240; 
    green = 52; 
    alpha = 200; 
    radius = 150;
    drawFill = true;     
    backgroundColor = ofColor(233, 52, 27); 
    resolution = 30;
    position = ofPoint(ofGetWidth()*.5, ofGetHeight()*.5); 
    ofSetCircleResolution(resolution);
    
    gui = new ofxUISuperCanvas("SUPER COMPACT", OFX_UI_FONT_MEDIUM);
    gui->addSpacer(); 
    gui->addTextArea("TEXT AREA", "Double tap the title above to toggle minified mode. Draw the title above to move the canvas around. All these settings are saved upon exiting. This is super indeed.");
    gui->addSpacer();
    gui->addSlider("RADIUS", 0.0, 255.0, &radius);
    gui->addSlider("RED", 0.0, 255.0, &red);
    gui->addSlider("GREEN", 0.0, 255.0, &green);
    gui->addSlider("BLUE", 0.0, 255.0, &blue);
    gui->addSlider("ALPHA", 0.0, 255.0, &alpha);
    gui->addSpacer();
    gui->add2DPad("CENTER", ofPoint(0,ofGetWidth()), ofPoint(0, ofGetHeight()), &position);
    gui->addLabelToggle("DRAWFILL", &drawFill);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
    
    gui->loadSettings("guiSettings.xml");
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(backgroundColor);
	ofPushStyle(); 
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(red, green, blue, alpha);
    if(drawFill) { ofFill(); } else { ofNoFill(); }
    ofDrawCircle(position.x, position.y, radius);
	ofPopStyle(); 
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{
//	string name = e.widget->getName(); 
//	int kind = e.widget->getKind(); 
}
//--------------------------------------------------------------
void ofApp::exit()
{
    gui->saveSettings("guiSettings.xml");
    delete gui; 
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) 
    {            
        case 'g':
        {
            gui->toggleVisible(); 
        }
            break; 

        case 'p':
        {
            gui->setDrawWidgetPadding(true);
        }
            break;

        case 'P':
        {
            gui->setDrawWidgetPadding(false);
        }
            break;

        case 't':
            gui->toggleMinified(); 
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
 
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
 

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}