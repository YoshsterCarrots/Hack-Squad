#include "cell.h"
#include "Particle.h"

using namespace std;

//calls a three point parameter of Cell
Cell::Cell(Particle p, Cell* new_next, Cell* new_prev) {
	particle = p;
	next = new_next;
	prev = new_prev;
}

//calls a one point parameter of Cell
Cell::Cell(Particle p) {
	particle = p;
}
