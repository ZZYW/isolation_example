//
//  Particle.cpp
//  particleSystem_VectorField
//
//  Created by Yang Wang on 10/9/14.
//
//

#include "Particle.h"

Particle::Particle(ofVec3f _location){
    
    acceleration = ofVec3f(0,0,0);
    velocity = ofVec3f(0,0,0);
    location = _location;
    maxspeed = ofRandom(0.1,2);
    maxforce = ofRandom(0.01,0.06);
    target = ofVec3f(0,0,0);
    c = ofColor(255,255,255,minA);
}

void Particle::update(ofVec3f _target){
    
    target = _target;
    ofVec3f desired = target - location;
    desired.normalize();
    desired *= maxspeed;
    ofVec3f steer = desired - velocity;
    steer.limit(maxforce);
    acceleration += steer;
    
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration = acceleration * 0;
    
}

void Particle::dim(){
    
    ofColor currentColor = c;
    
    if(currentColor.a > minA){
        currentColor.set(currentColor.r, currentColor.g, currentColor.b, currentColor.a -1);
        c = currentColor;
    }
    
}




