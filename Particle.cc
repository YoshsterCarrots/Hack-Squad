#include "Particle.h"
using namespace std;

Particle::Particle(int x, int y, int dx, int dy, int life, enum moveType movementType) {
	setX(x);
	setY(y);
	xVel = dx;
	yVel = dy;
	setLifetime(life);
	type = movementType;
}

void Particle::setX(int value) {
	if (value < 0) {
		xPos = 0;
	}
	else {
		xPos = value;
	}
}

void Particle::setY(int value) {
	if (value < 0) {
		yPos = 0;
	}
	else {
		yPos = value;
	}
}

void Particle::setXVel(int value) {
	xVel = value;
}

void Particle::setYVel(int value) {
	yVel = value;
}

void Particle::setLifetime(int value) {
	if (value < 0) {
		lifetime = 0;
	}
	else {
		lifetime = value;
	}
}

void Particle::setType(enum moveType value) {
	type = value;
}

void Particle::doPhysics(int xAccel, int yAccel) {
	if (type == BALLISTIC) {
		yVel += 1;
	}
	xVel += xAccel;
	yVel += yAccel;
	xPos += xVel;
	yPos += yVel;
	lifetime--;
}

//I don't remember if this one is actually necessary
void Particle::drawPoint() {
	//TODO
}
