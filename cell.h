#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "colors.h"

class Color {
	private:
		int r = 0;
		int g = 0;
		int b = 0;
	public:
		Color(int red, int green, int blue);
};

class Particles {
	private:
		double x = 0.;
		double y = 0.;
		Color color;
	public:
		Particles(Color& c, double new_x, double new_y);
};

class Cell {
	private:
		Particle particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;
	public:
		Cell(const Particle& p, Cell* new_next, Cell* new_prev);
};
