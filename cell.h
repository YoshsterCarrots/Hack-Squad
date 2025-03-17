#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "/public/color.h"

struct Color {
	int r = 0;
	int g = 0;
	int b = 0;
	Color(int red, int green, int blue) {
		r = red;
		g = green;
		b = blue;
	}
};

struct Particles {
	double x = 0.;
	double y = 0.;
	Color color;
	Particles(Color& c, double new_x, double new_y) {
		x = new_x;
		y = new_y;
		color = c;
};

struct Cell {
	Particle particle;
	Cell* next = nullptr;
	Cell* prev = nullptr;
	Cell(Particle& p, Cell* new_next, Cell* new_prev) {
		particle = p;
		next = new_next;
		prev= new_prev;
	}
};

Cell head;
