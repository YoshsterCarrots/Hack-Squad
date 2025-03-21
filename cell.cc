#include "cell.h"
#include "Particle.h"

using namespace std;
/*
Color::Color(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;
}

Particle::Particle(const Color& c, double new_x, double new_y) {
	color = c;
	x = new_x;
	y = new_y;
}
*/
Cell::Cell(const Particle& p, Cell* new_next, Cell* new_prev) {
	particle = p;
	next = new_next;
	prev = new_prev;
}
