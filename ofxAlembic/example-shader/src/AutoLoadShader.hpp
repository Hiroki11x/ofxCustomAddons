//
//  AutoLoadShader.hpp
//  example-shader
//
//  Created by HirokiNaganuma on 2016/04/16.
//
//


#ifndef AutoLoadShader_hpp
#define AutoLoadShader_hpp

#include "ofMain.h"
#include "ofxAlembic.h"

class AutoLoadShader : public ofShader{
private:
    Poco::Timestamp lastFragTimestamp, lastVertTimestamp;
    ofFile vertShader, fragShader;
public:
    void watch(string vertName, string fragName);
    void reload();
    void onUpdate(ofEventArgs &e);
};

#endif /* AutoLoadShader_hpp */
