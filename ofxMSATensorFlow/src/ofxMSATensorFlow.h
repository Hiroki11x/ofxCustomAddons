/*
 this is simple wrapper for a single session and graph, should suffice for most cases
 you can access the internal variables directly if you need more advanced setup
 I didn't wrap it too much as I think it's important to understand how TensorFlow works,
 in case you need to switch to raw tensorflow project etc.

 There's also a bunch of helper functions for various functions (eg vector <--> tensor <--> image conversions)

*/

#pragma once

#include "ofxMSATFIncludes.h"
#include "ofxMSATFUtils.h"
#include "ofxMSATFImageClassifier.h"
#include "ofxMSATFLayerVisualizer.h"

namespace msa {
namespace tf {


// Not using this class anymore, taking functional approach. see ofxMSATFUtils


//class ofxMSATensorFlow {
//public:

//    ~ofxMSATensorFlow();

//    // initialize session, return true if successfull
//    bool setup(const tensorflow::SessionOptions & session_options = tensorflow::SessionOptions());


//    // load a binary graph file and add to sessoin, return true if successfull
//    bool loadGraph(const string path, tensorflow::Env* env = tensorflow::Env::Default(), const string device="/cpu:0");   // use "/gpu:0" for GPU


//    // create session with graph
//    // called automatically by loadGraph,
//    // you can also call it manually if you want to create or modify your own graph
//    bool createSessionWithGraph(const string device="/cpu:0");    // use "/gpu:0" for GPU

//    // run the graph with given inputs and outputs, return true if successfull
//    // (more: https://www.tensorflow.org/versions/master/api_docs/cc/ClassSession.html#virtual_Status_tensorflow_Session_Run )
//    bool run(const std::vector<std::pair<string, tensorflow::Tensor> >& inputs,
//             const std::vector<string>& output_tensor_names,
//             const std::vector<string>& target_node_names,
//             std::vector<tensorflow::Tensor>* outputs);

//    // get status of last action (more: https://www.tensorflow.org/versions/master/api_docs/cc/ClassStatus.html )
//    const tensorflow::Status& status() const { return status_; }

//    // get session (more: https://www.tensorflow.org/versions/master/api_docs/cc/ClassSession.html )
//    tensorflow::Session* session() { return session_; }
//    const tensorflow::Session* session() const { return session_; }

//    // get graph. you can manipulate this, and then call createSessionWithGraph
//    tensorflow::GraphDef& graph() { return graph_def_; }
//    const tensorflow::GraphDef& graph() const { return graph_def_; }

//    // get is ready or not (i.e. graph and session have been created successfully)
//    bool isReady() const { return initialized_; }

//protected:
//    tensorflow::Session* session_ = NULL;
//    tensorflow::GraphDef graph_def_;
//    tensorflow::Status status_;
//    bool initialized_ = false;

//    void closeSession();
//    void logError();
//};

}   // namespace tf
}   // namespace msa
