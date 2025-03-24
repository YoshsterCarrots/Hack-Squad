#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"
#include "particle_graphics.h"
#include "colors.h"

using namespace std;

int error_count = 0;

void die(string s) {
	cout << s << endl;
	error_count++;
}

void particle_test() {
	Particle p;
	ParticleGraphics pg;

	if (p.getX() || p.getY() || p.getXVel() != 1 || p.getYVel() != 1 || p.getLifetime() != 100 || p.getType() != Particle::STREAMER) die("Particle default constructor ain't working");
	if (pg.getColor('r') || pg.getColor('g') || pg.getColor('b')) die("Particle Graphics default constructor ain't working");
	pg.setColor(25, 15, 245);
	if (pg.getColor('r') != 25 || pg.getColor('g') != 15 || pg.getColor('b') != 245) die("Changing color in Particle Graphics ain't working");
	p.setX(4);
	if (p.getX() != 4) die("Setting X ain't working");
	p.setY(10);
	if (p.getY() != 10) die("Setting Y ain't working");
	p.setXVel(2);
	if (p.getXVel() != 2) die("Setting X Velocity ain't working");
	p.setYVel(5);
	if (p.getYVel() != 5) die("Setting Y Velocity ain't working");
	p.setLifetime(400);
	if (p.getLifetime() != 400) die("Setting Lifetime ain't working");
	p.setType(Particle::FIREWORK);
	if (p.getType() != Particle::FIREWORK) die("Setting Type ain't working");
	p.doPhysics(1, 1);
	if (p.getX() != 7 || p.getY() != 16 || p.getXVel() != 3 || p.getYVel() != 6 || p.getLifetime() != 399) die("Physics ain't working");
	p.setType(Particle::BALLISTIC);
	if (p.getType() != Particle::BALLISTIC) die("Setting Type ain't working");
	p.doPhysics(2, 7);
	if (p.getX() != 12 || p.getY() != 30 || p.getXVel() != 5 || p.getYVel() != 14 || p.getLifetime() != 398) die("Ballistic Physics ain't working");
	
//	pg.drawPoint(p.getX(), p.getY(), pg.getColor('r'), pg.getColor('g'), pg.getColor('b')); 							Works!

	Particle l(2, 4, 1, 5, 350, Particle::FIREWORK);
	ParticleGraphics cool(42, 69, 255);
	if (l.getX() != 2 || l.getY() != 4 || l.getXVel() != 1 || l.getYVel() != 5 || l.getLifetime() != 350 || l.getType() != Particle::FIREWORK) die("Particle constructor ain't working");
	if (cool.getColor('r') != 42 || cool.getColor('g') != 69 || cool.getColor('b') != 255) die ("Particle Graphic constructor ain't working");

//	cool.drawPoint(l.getX(), l.getY(), cool.getColor('r'), cool.getColor('g'), cool.getColor('b')); 					Works!

	ParticleSystem ps;
	
	if (ps.numParticles() != 0) die("Partical System ain't setting number to 0 when created");

	Particle* a = new Particle(1, 1, 1, 1, 500);
	Particle* b = new Particle(2, 4, 2, 1, 750, Particle::BALLISTIC);
	Particle* c = new Particle(53, 29, 2, 2, 90, Particle::FIREWORK);

	ps.push_back(a);

	delete a;
	delete b;
	delete c;
}

int main() {
	particle_test();
	if (error_count > 0) {
		cout << "Errors: " << error_count << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << "All good!" << endl;
		exit(EXIT_SUCCESS);
	}
}
