#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    cam.enableMouseInput();
    cam.enableMouseMiddleButton();
    
    particleListCount = 40000;
    
    for (int i=0; i<particleListCount; i++) {
        particleList.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),0));
        targets.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    for(int i=0;i<particleListCount;i++){
        
        ofVec3f target;
        target = ofVec3f(
                        particleList[i].location.x + 8*(ofNoise(400/9+particleList[i].location.y/80)-0.5),
                    particleList[i].location.y + 8*(ofNoise(400/9+particleList[i].location.x/80)-0.5),
                         0
        
        );
        particleList[i].update(
                        target
        );
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
