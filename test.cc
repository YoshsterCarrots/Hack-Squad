#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"
#include "particle_graphics.h"
#include "colors.h"

using namespace std;

srand(time(0));

int main() {
	Particle p(0, 0, 1, 3, 100, STREAMER);
	ParticleGraphics pg(rand() % 255, rand() % 255, rand() % 255);
}
