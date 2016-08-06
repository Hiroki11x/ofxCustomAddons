//
//  AutoLoadShader.cpp
//  example-shader
//
//  Created by HirokiNaganuma on 2016/04/16.
//
//

#include "AutoLoadShader.hpp"

void AutoLoadShader::watch(string vertName, string fragName)
{
    vertShader.open(vertName);
    fragShader.open(fragName);
    
    ofAddListener(ofEvents().update, this, &AutoLoadShader::onUpdate);
}

void AutoLoadShader::reload()
{
    load(vertShader.path(), fragShader.path());
}

void AutoLoadShader::onUpdate(ofEventArgs &e)
{
    //エラー出る
//    if (lastVertTimestamp != vertShader.getPocoFile().getLastModified()
//        || lastFragTimestamp != fragShader.getPocoFile().getLastModified())
//    {
        reload();
//    }
}