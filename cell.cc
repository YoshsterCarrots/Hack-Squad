<<<<<<< HEAD
#include "cell.h"
||||||| 5447c5d
//This is a placeholder
=======
#include "cell.h"

using namespace std;
>>>>>>> fb93f4731f596d64d5beb37b60291599d81c0073

Color::Color(int red, int green, int blue) {
	r = red;
	g = green;
	b = blue;
}

Particles::Particles(Color& c, double new_x, double new_y) {
	x = new_x;
	y = new_y;
	color = c;
}

Cell::Cell(const Particle& p, Cell* new_next, Cell* new_prev) {
	particle = p;
	next = new_next;
	prev = new_prev;
}
