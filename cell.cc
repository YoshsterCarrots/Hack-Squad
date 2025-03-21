#include "cell.h"
#include "Particle.h"

using namespace std;

Cell::Cell(Particle& p, Cell* new_next, Cell* new_prev) {
	particle = p;
	next = new_next;
	prev = new_prev;
}

Cell::Cell(Particle& p) {
	particle = p;
}
