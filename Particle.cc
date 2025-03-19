#include "Particle.h"
using namespace std;

Particle::Particle(int x, int y, int dx, int dy, int life, moveType movementType) {
	//TODO
}

void Particle::setX(int value) {
	//TODO
}

void Particle::setY(int value) {
	//TODO
}

void Particle::setXVel(int value) {
	//TODO
}

void Particle::setYVel(int value) {
	//TODO
}

void Particle::setLifetime(int value) {
	//TODO
}

void Particle::setType(moveType value) {
	//TODO
}

void Particle::doPhysics(int xAccel, int yAccel) {
	xPos += xVel;
	yPos += yVel;
	xVel += xAccel;
	yVel += yAccel;
}

void Particle::drawPoint() {
	//TODO
}
