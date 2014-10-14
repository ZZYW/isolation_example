//
//  Particle.h
//  particleSystem_VectorField
//
//  Created by Yang Wang on 10/9/14.
//
//

#ifndef __particleSystem_VectorField__Particle__
#define __particleSystem_VectorField__Particle__

#include <iostream>
#include "ofMain.h"

class Particle {
public:
    
    Particle(ofVec3f _location);
    
    ofVec3f acceleration;
    ofVec3f velocity;
    ofVec3f location;
    ofVec3f target;
    float radius;
    float maxforce;
    float maxspeed;
    ofColor c;
    float minA = 78;
    bool lightUp = false;
   
    int tailCounter = 0;
    int tailLength = 5;
    ofVec3f tail[5];
    
    void update(ofVec3f _target);
    void render();
    void updateTail(ofVec3f _location);
    void dim();
};

#endif /* defined(__particleSystem_VectorField__Particle__) */
