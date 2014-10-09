#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    cam.enableMouseInput();
    cam.enableMouseMiddleButton();
    
    particleListCount = 10000;
    
    for (int i=0; i<particleListCount; i++) {
        particleList.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),ofRandom(-200,200)));
        targets.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),ofRandom(-200,200)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if(ofGetFrameNum()%1000==0){
        for (int i=0; i<particleListCount; i++) {
            targets[i] = ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),ofRandom(-200,200));
        }
    }
    
    for(int i=0;i<particleListCount;i++){
        particleList[i].update(targets[i]);
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofBackground(0);
    ofMesh mesh;
    ofNoFill();
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i=0; i<particleList.size(); i++) {
        mesh.addVertex(particleList[i].location);
        mesh.addColor(255);
    }
    mesh.drawWireframe();
    
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
