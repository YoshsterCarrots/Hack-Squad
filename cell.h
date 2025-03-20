#pragma once

#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "colors.h"
#include "Particle.h"

class Cell {
	private:
		Particle particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;
	public:
		Cell(const Particle& p, Cell* new_next, Cell* new_prev);
};
