#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "/public/color.h"

struct Color {
	int r = 0;
	int g = 0;
	int b = 0;
};

struct Particles {
	double x = 0;
	double y = 0;
	Color color;
};

struct Cell {
	Particle particle;
	Cell* next;
	Cell* prev;
};

Cell head;
