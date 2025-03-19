#include "cell.h"

using namespace std;

Cell::Cell(const Particle& p, Cell* new_next, Cell* new_prev) {
	particle = p;
	next = new_next;
	prev = new_prev;
}
