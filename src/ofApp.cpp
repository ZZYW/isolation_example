#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    
    gui.setup();
    gui.add(noiseSeedValue2.setup("noise Seed", 9, 0.1, 10));
    gui.add(noiseVariable3.setup("noise variable 3", 688,400,2000));
    gui.add(noiseVariable4.setup("noise variable 4", 8,0.1,15)); //no obvious influence...
    
    gui.add(colorNoiseV1.setup("color noise variable 1", 593, 0.1, 100));
    gui.add(colorNoiseV2.setup("color noise variable 2", 43.7, 0.1, 100));
    gui.add(colorNoiseV3.setup("color noise variable 3", 0.001, 0.0001, 0.1));
    gui.add(colorNoiseV4.setup("Color noise timing", 4, 1, 20));
    gui.add(frameRate.set("frame rate", ""));
    
    particleListCount = 50000;
    
    for (int i=0; i<particleListCount; i++) {
        particleList.push_back(ofVec3f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()),0));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    frameRate = ofToString(ofGetFrameRate());
    
    //change noise seed over time, make it more alive
    float Oscillation = 1.5;
    noiseSeedValue += ofRandom(-Oscillation,Oscillation);
    
    
    ofVec3f mousePos = ofVec3f(mouseX,mouseY,0);
    for(int i=0;i<particleList.size();i++){
        float backUpZ = particleList[i].location.z; //save its z position, so we can do some 2d stuff without interference on z.
        particleList[i].location.z = 0;
        ofVec3f target; //targets trigger all of the movement
        
        //calcuate the particle's target based on perlin noise
        target = ofVec3f(
                         particleList[i].location.x + noiseVariable4*(ofNoise(noiseVariable3/noiseSeedValue2+particleList[i].location.y/noiseSeedValue)-0.5),
                         particleList[i].location.y + noiseVariable4*(ofNoise(noiseVariable3/noiseSeedValue2+particleList[i].location.x/noiseSeedValue)-0.5),
                         0);
        
        float isolationR = 200;
        float margin = 100;
        if( particleList[i].location.distance(mousePos) < isolationR ){
            particleList[i].escaping = true;
            ofVec3f go = mousePos - particleList[i].location;
            go.normalize();
            go *= ofMap(particleList[i].location.distance(mousePos), 0, isolationR + ofRandom(0,20), -10, 0);
            float mappedAlpha = ofMap(particleList[i].location.distance(mousePos), 0, isolationR+60,255 , particleList[i].c.a);
            float mappedB = ofMap(particleList[i].location.distance(mousePos), 0, isolationR+60, 255 , 200);
            particleList[i].c = ofColor(255,255,mappedB,mappedAlpha);
            target += go;
        }else if(particleList[i].location.distance(mousePos) >= isolationR && particleList[i].location.distance(mousePos) < isolationR + margin) {
            particleList[i].escaping = false;
            float mappedAlpha = ofMap(particleList[i].location.distance(mousePos), isolationR, isolationR+margin,255 , particleList[i].minA);
            float mappedB = ofMap(particleList[i].location.distance(mousePos), isolationR, isolationR+margin,255 , 230);
            particleList[i].c = ofColor(255,255,255,mappedAlpha);
        }else{
            particleList[i].escaping = false;
            particleList[i].dim();
        }
        
        
        //if particles are out of the canvas, re-allocate them
        if(particleList[i].location.x > ofGetWidth()){
            particleList[i].location.x = 0;
        }else if(particleList[i].location.x < 0){
            particleList[i].location.x = ofGetWidth();
        }else if(particleList[i].location.y > ofGetHeight()){
            particleList[i].location.y = 0;
        }else if(particleList[i].location.y < 0){
            particleList[i].location.y = ofGetHeight();
        }
        particleList[i].update(target);
        particleList[i].location.z = backUpZ; //apply back the z value and get ready for the next step - z-wave.
    }
    
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    
    gui.draw();
    
    ofSetColor(0, 30, 182, 70);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
//    cam.begin();
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    ofEnableAlphaBlending();
    
    for (int i=0; i<particleList.size(); i++) {
        mesh.addVertex(particleList[i].location);
        mesh.addColor(particleList[i].c);
        
    }
    
    mesh.draw();
//    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
		case 'f':
			ofToggleFullscreen();
			break;
		default:
			break;
	}
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
