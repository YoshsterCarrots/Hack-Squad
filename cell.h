#pragma once

#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "colors.h"
#include "Particle.h"

class Cell {
	public:
		Particle particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;

		Cell(Particle p, Cell* new_next, Cell* new_prev); 
		Cell(Particle p);
};
