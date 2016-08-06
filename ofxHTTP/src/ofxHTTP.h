// =============================================================================
//
// Copyright (c) 2013-2015 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include "ofSSLManager.h"
#include "ofxIO.h"
#include "ofxMediaType.h"
#include "ofxNetworkUtils.h"
#include "ofxTaskQueue.h"
#include "ofx/HTTP/AbstractClientTypes.h"
#include "ofx/HTTP/AbstractServerTypes.h"
#include "ofx/HTTP/BaseClient.h"
#include "ofx/HTTP/BaseResponse.h"
#include "ofx/HTTP/BaseRequest.h"
#include "ofx/HTTP/ClientEvents.h"
#include "ofx/HTTP/Context.h"
#include "ofx/HTTP/DefaultClientSessionProvider.h"
#include "ofx/HTTP/DefaultProxyProcessor.h"
#include "ofx/HTTP/DefaultRedirectProcessor.h"
#include "ofx/HTTP/DefaultClientHeaders.h"
#include "ofx/HTTP/DefaultCookieProcessor.h"
#include "ofx/HTTP/DefaultResponseStreamFilter.h"
#include "ofx/HTTP/DefaultClient.h"
#include "ofx/HTTP/DefaultClientTaskQueue.h"
#include "ofx/HTTP/DefaultClientTask.h"
#include "ofx/HTTP/GetRequest.h"
#include "ofx/HTTP/HTTPUtils.h"
#include "ofx/HTTP/PostRequest.h"
#include "ofx/HTTP/PutRequest.h"
#include "ofx/HTTP/Session.h"
#include "ofx/HTTP/SessionStore.h"
#include "ofx/HTTP/SimpleFileServer.h"
#include "ofx/HTTP/SimpleIPVideoServer.h"
#include "ofx/HTTP/SimplePostServer.h"
#include "ofx/HTTP/SimpleWebSocketServer.h"
#include "ofx/HTTP/URIBuilder.h"
#include "ofx/HTTP/WebSocketEvents.h"
#include "ofx/HTTP/WebSocketRoute.h"
#include "ofx/HTTP/WebSocketFrame.h"
#include "ofx/HTTP/WebSocketConnection.h"


namespace ofxHTTP = ofx::HTTP;
