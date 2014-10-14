//
//  Particle.cpp
//  particleSystem_VectorField
//
//  Created by Yang Wang on 10/9/14.
//
//

#include "Particle.h"

Particle::Particle(ofVec3f _location){
    minA = ofRandom(0,255);
    acceleration = ofVec3f(0,0,0);
    velocity = ofVec3f(0,0,0);
    location = _location;
    maxspeed = ofRandom(0.1,0.9);
    repelMaxspeed = ofRandom(1, 4);
    maxforce = ofRandom(0.01,0.2);
    target = ofVec3f(0,0,0);
    c = ofColor(255,255,255-minA*0.4,minA);
}


void Particle::update(ofVec3f _target){
    
    target = _target;
    ofVec3f desired = target - location;
    desired.normalize();
    
    if(!escaping){
        desired *= maxspeed;
    }else{
        desired *= repelMaxspeed;
    }
    
    ofVec3f steer = desired - velocity;
    steer.limit(maxforce);
    acceleration += steer;
    
    velocity += acceleration;
    if(!escaping){
        velocity.limit(maxspeed);
    }else{
        velocity.limit(repelMaxspeed);
    }
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

void Particle::dimSpeed(){
    velocity.limit(maxspeed);
}