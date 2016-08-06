#include "ofApp.h"
#include "ofxInkSim.h"
#include "ofxInkSim.h"

void ofApp::setup()
{
    inkSim.setup();
    gui.setup(inkSim.getUniformInfo());
    moodmachine.setSpeed(1.0);
    
    pdf.load("terminator.pdf");
    
}

void ofApp::update()
{
    inkSim.update();
}

void ofApp::draw()
{
    inkSim.draw();
    gui.draw();
    
    drawArt();
    
    ofDrawBitmapStringHighlight("drag mouse to stroke", 10, ofGetHeight() - 40);
    ofDrawBitmapStringHighlight("press ' ' to hide gui", 10, ofGetHeight() - 20);
}

void ofApp::mouseDragged(int x, int y, int button)
{
    ofColor c = moodmachine;
    inkSim.stroke(&brush, x, y, getInkColor(c.getHueAngle(), 255, 10));
}

void ofApp::mouseReleased(int x, int y, int button)
{
    inkSim.stopStroke(&brush);
}

void ofApp::keyPressed(int key)
{
    if (key == '1')
    {
        inkSim.setDrawMode(ofxInkSim::INKFIX);
    }
    else if (key == '2')
    {
        inkSim.setDrawMode(ofxInkSim::INKSURF);
    }
    else if (key == '3')
    {
        inkSim.setDrawMode(ofxInkSim::INKFLOW);
    }
    else if (key == '4')
    {
        inkSim.setDrawMode(ofxInkSim::WATERFLOW);
    }
    else if (key == 'd')
    {
        inkSim.toggleDebug();
    }
    else if (key == ' ')
    {
        gui.toggleVisible();
    }
    else if (key == 'r')
    {
        gui.resetToDefault();
    }
    else if (key == 'c')
    {
        inkSim.clear();
    }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}


void ofApp::drawArt(){
    float app_time = ofGetElapsedTimef();
    float animation_time = fmodf(app_time, 5) / 5;
    
    cout << "app_time: = " << app_time << ", animation_time: " << animation_time << endl;
    
    ofSetColor(255);
    
    // PDFのパスを順番に取り出して ofPolyline で描画する
    //pdf.getNumPath()
    for (int i = 0; i < 1; i++){
        ofPath& path = pdf.getPathAt(i);
        
        vector<ofPolyline>& polys = path.getOutline();
        
        for (int k = 0; k < polys.size(); k++){
            ofPolyline poly = polys[k];
            
            poly = poly.getResampledByCount(100);//滑らかに描画
            
            int target_size = poly.size() * animation_time;//
            poly.resize(target_size);//更新
            
            cout << ofToString(poly.getVertices()) <<endl;
            
            vector<ofPoint> vec = poly.getVertices();
            for(int i=0 ;i<vec.size();i++){
//                ofCircle(vec.at(i).x,vec.at(i).y, 2);
                ofColor c = moodmachine;
                inkSim.stroke(&brush, vec.at(i).x, vec.at(i).y, getInkColor(c.getHueAngle(), 255, 10));
            }
        }
    }
}