#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    
    cam.enableMouseInput();
    cam.enableMouseMiddleButton();
    
    particleListCount = 10000;
    
    for (int i=0; i<particleListCount; i++) {
        particleList.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),0));
        targets.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
   // cam.setPosition(ofGetWidth()/2, ofGetHeight()/2, 300);
    
    float counter = 0;
    ofVec3f mousePos = ofVec3f(mouseX,mouseY,0);
    for(int i=0;i<particleList.size();i++){
        
        ofVec3f target;
        
      
        
        
        target = ofVec3f(
                         particleList[i].location.x + 8*(ofNoise(1000/9+particleList[i].location.y/80+counter)-0.5),
                         particleList[i].location.y + 8*(ofNoise(1000/9+particleList[i].location.x/80+counter)-0.5),0);
        
        float isolationR = 180;
        
        if( particleList[i].location.distance(mousePos) < isolationR ){
        
            ofVec3f go = mousePos - particleList[i].location;
            go.normalize();
            go *= ofMap(particleList[i].location.distance(mousePos), 0, isolationR, -20, -1);
            target += go;
            
        }
        
        
        particleList[i].update(target);
      
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    


    
    ofFill();
    ofSetColor(9,12,107,7);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    ofMesh mesh;
    ofNoFill();
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i=0; i<particleList.size(); i++) {
        mesh.addVertex(particleList[i].location);
        ofColor c(243,240,138);
        mesh.addColor(c);
    }
    mesh.draw();
  

    
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
