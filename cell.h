#pragma once

#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "colors.h"
#include "Particle.h"
/*
class Color {
	private:
		int red;
		int green;
		int blue;
	public:
		Color(int r, int g, int b);
};

class Particle {
	private:
		Color color;
		double x;
		double y;
	public:
		Particle(const Color& c, double new_x, double new_y);
};
*/
class Cell {
	private:
		Particle particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;
	public:
		Cell(const Particle& p, Cell* new_next, Cell* new_prev);
};
