/*
    Copyright (C) 2015 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once
#include "ofxDatGuiComponent.h"

class ofxDatGui2dPad : public ofxDatGuiComponent {

    public:
    
        ofxDatGui2dPad(string label) : ofxDatGuiComponent(label)
        {
            reset();
            mScaleOnResize = true;
            mBounds = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
            mType = ofxDatGuiType::PAD2D;
            setTheme(ofxDatGuiComponent::theme.get());
        }
    
        ofxDatGui2dPad(string label, ofRectangle bounds) : ofxDatGuiComponent(label)
        {
            reset();
            mBounds = bounds;
            mScaleOnResize = false;
            mType = ofxDatGuiType::PAD2D;
            setTheme(ofxDatGuiComponent::theme.get());
        }
    
        void setTheme(ofxDatGuiTheme* theme)
        {
            setComponentStyle(theme);
            mStyle.height = theme->layout.pad2d.height;
            mStyle.stripe.color = theme->stripe.pad2d;
            mColors.line = theme->color.pad2d.line;
            mColors.ball = theme->color.pad2d.ball;
            mColors.fill = theme->color.inputAreaBackground;
            mBallSize = theme->layout.pad2d.ballSize;
            mLineWeight = theme->layout.pad2d.lineWeight;
            mPad = ofRectangle(0, 0, mStyle.width - mStyle.padding - mLabel.width, mStyle.height - (mStyle.padding * 2));
        }
    
        void setBounds(ofRectangle bounds)
        {
            mBounds = bounds;
            reset();
            mScaleOnResize = false;
        }
    
        void setPosition(int x, int y)
        {
            ofxDatGuiComponent::setPosition(x, y);
            if (mScaleOnResize){
        // scale the bounds to the resized window //
                mBounds.width *= (ofGetWidth()/mBounds.width);
                mBounds.height *= (ofGetHeight()/mBounds.height);
            }
        }
    
        ofPoint getPosition()
        {
            return pWorld;
        }
    
        void reset()
        {
            mx = 0.5f;
            my = 0.5f;
            pWorld.x = mBounds.x + (mBounds.width*mx);
            pWorld.y = mBounds.y + (mBounds.height*my);
        }
    
        void draw()
        {
            if (!mVisible) return;
            ofPushStyle();
                mPad.x = x + mLabel.width;
                mPad.y = y + mStyle.padding;
                mPad.width = mStyle.width - mStyle.padding - mLabel.width;
                pLocal.x = mPad.x + mPad.width * mx;
                pLocal.y = mPad.y + mPad.height * my;
                ofxDatGuiComponent::draw();
                ofSetColor(mColors.fill);
                ofDrawRectangle(mPad);
                ofSetLineWidth(mLineWeight);
                ofSetColor(mColors.line);
                ofDrawLine(mPad.x, pLocal.y, mPad.x + mPad.width, pLocal.y);
                ofDrawLine(pLocal.x, mPad.y, pLocal.x, mPad.y + mPad.height);
                ofSetColor(mColors.ball);
                ofDrawCircle(pLocal, mBallSize);
            ofPopStyle();
        }
    
        static ofxDatGui2dPad* getInstance() { return new ofxDatGui2dPad("X"); }
    
    protected:
    
        void onMouseDrag(ofPoint m)
        {
            if (mPad.inside(m)){
                mx = (m.x-mPad.x)/mPad.width;
                my = (m.y-mPad.y)/mPad.height;
                pWorld.x = mBounds.x + (mBounds.width*mx);
                pWorld.y = mBounds.y + (mBounds.height*my);
            // dispatch event out to main application //
                if (pad2dEventCallback != nullptr) {
                    ofxDatGui2dPadEvent e(this, pWorld.x, pWorld.y);
                    pad2dEventCallback(e);
                }   else{
                    ofxDatGuiLog::write(ofxDatGuiMsg::EVENT_HANDLER_NULL);
                }
            }
        }
    
    private:
        float mx;
        float my;
        bool mScaleOnResize;
        ofPoint pLocal;
        ofPoint pWorld;
        ofRectangle mPad;
        ofRectangle mBounds;
        int mBallSize;
        int mLineWeight;
        struct{
            ofColor fill;
            ofColor line;
            ofColor ball;
        } mColors;
    
};
    