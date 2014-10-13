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
    vector<ofVec3f> targets;
//    vector<tail> tails;
    int particleListCount;
    ofEasyCam cam;
    
    bool displayTail = true;
    
//    ofxFloatSlider noiseSeedValue;
    float noiseSeedValue = 320;
    ofxFloatSlider noiseSeedValue2;
    ofxFloatSlider noiseVariable3;
    ofxFloatSlider noiseVariable4;
    ofxLabel OscillationValue;
    ofxPanel gui;
    

    
		
};
