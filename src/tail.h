//
//  tail.h
//  particleSystem_VectorField
//
//  Created by Yang Wang on 10/12/14.
//
//

#ifndef __particleSystem_VectorField__tail__
#define __particleSystem_VectorField__tail__

#include <iostream>
#include "ofMain.h"

class tail {
public:
    ofVec3f location;
    ofColor c;
    tail (ofVec3f _location ){
        location = _location;
    };
};

#endif /* defined(__particleSystem_VectorField__tail__) */
