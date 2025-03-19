#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "colors.h"

class Color {
	public:
		int r = 0;
		int g = 0;
		int b = 0;
		Color(int red, int green, int blue);
};

class Particles {
	public:
		double x = 0.;
		double y = 0.;
		Color color;
		Particles(Color& c, double new_x, double new_y);
};

class Cell {
	public:
	Particle particle;
	Cell* next = nullptr;
	Cell* prev = nullptr;
	Cell(const Particle& p, Cell* new_next, Cell* new_prev);
};
