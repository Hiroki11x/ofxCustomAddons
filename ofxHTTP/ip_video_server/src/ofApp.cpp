

#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(30);

    mVideoGrabber.setVerbose(true);
    mVideoGrabber.initGrabber(M_WIDTH, M_HEIGHT,OF_IMAGE_COLOR);

    ofx::HTTP::SimpleIPVideoServerSettings settings;

    // Many other settings are available.
    settings.setPort(7890);
<<<<<<< HEAD
    settings.setHost("192.168.149.229");//このPCのIPアドレス
=======
    settings.setHost("192.168.12.41");//このPCのIPアドレス
>>>>>>> 7fa5b946ff0fc95eac04cb7cb657d3e19111e5c1

    // The default maximum number of client connections is 5.
    settings.ipVideoRouteSettings.setMaxClientConnections(3);

    // Apply the settings.
    server.setup(settings);

    // Start the server.
    server.start();

#if !defined(TARGET_LINUX_ARM)
    // Launch a browser with the address of the server.
    ofLaunchBrowser(server.getURL());
#endif

}


void ofApp::update(){
    // Update the video player.
    mVideoGrabber.update();

    if(mVideoGrabber.isFrameNew()){
        server.send(mVideoGrabber.getPixels());
    }
}


<<<<<<< HEAD
void ofApp::draw(){
    mVideoGrabber.draw(0,0);
=======
void ofApp::draw()
{
    // Draw the video on the server screen.
//    player.draw(0,0);
    mVideoGrabber.draw(0,0,ofGetWidth(),ofGetHeight());
>>>>>>> 7fa5b946ff0fc95eac04cb7cb657d3e19111e5c1

    // Display the number of connected clients for reference.
    std::stringstream ss;

    ss << "Num clients connected: ";
    ss << server.getNumConnections();

    ofDrawBitmapStringHighlight(ss.str(), 20, 20);
}
