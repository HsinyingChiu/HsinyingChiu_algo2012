/*
 *  Particle.h
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle {
public:
	Particle();
	
	ofPoint loc;
	ofPoint vel;
	ofPoint acc;
	float r;
	float timer;
	float maxspeed;
	float mass;
	
	
	void setInitialCondition(float px, float py, float vx, float vy);

	void update();
	void draw();
	
	void applyForce(ofPoint force);
	bool dead();
};

#endif