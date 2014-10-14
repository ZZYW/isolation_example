#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<Particle> particleList;
    int particleListCount;
    ofEasyCam cam;
    

    float noiseSeedValue = 200;
    ofxFloatSlider noiseSeedValue2;
    ofxFloatSlider noiseVariable3;
    ofxFloatSlider noiseVariable4;
    ofxFloatSlider colorNoiseV1;
    ofxFloatSlider colorNoiseV2;
    ofxFloatSlider colorNoiseV3;
    ofxFloatSlider colorNoiseV4;
    ofParameter<string> frameRate;
    ofxLabel OscillationValue;
    ofxPanel gui;
    
    vector<ofVec3f> bodyParticles;
    ofMesh virtualBody;
    
};
