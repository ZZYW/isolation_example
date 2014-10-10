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
    maxspeed = ofRandom(0.1,1.5);
    maxforce = ofRandom(0.1);
    radius = 2;
    target = ofVec3f(0,0,0);
    
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



