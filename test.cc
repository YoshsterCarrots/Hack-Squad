#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"
#include "particle_graphics.h"
#include "colors.h"

using namespace std;

void die() {
	cout << "BAD INPUT" << endl;
	exit(EXIT_FAILURE);
}

void particle_test() {
	Particle p;
	if (p.getX() || p.getY() || p.getXVel() != 1 || p.getYVel() != 1 || p.getLifetime() != 100 || p.getType() != STREAMER) die();
}
