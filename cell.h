#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "/public/color.h"

class Color {
	public:
		int r = 0;
		int g = 0;
		int b = 0;
		Color(int red, int green, int blue) {
			r = red;
			g = green;
			b = blue;
		}
};

class Particles {
	public:
		double x = 0.;
		double y = 0.;
		Color color;
		Particles(Color& c, double new_x, double new_y) {
			x = new_x;
			y = new_y;
			color = c;
		}
};

class Cell {
	public:
	Particle particle;
	Cell* next = nullptr;
	Cell* prev = nullptr;
	Cell(const Particle& p, Cell* new_next, Cell* new_prev) {
		particle = p;
		next = new_next;
		prev = new_prev;
	}
};
