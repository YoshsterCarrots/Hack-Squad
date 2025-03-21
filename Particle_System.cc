#include "Particle_System.h"

using namespace std;

void ParticleSystem::push_back(Particle& p) {
	Cell* x  = new Cell(p);
	if (tail == nullptr) {
		tail = head = x;
	}
	else {
		tail->next = x;
		x->prev = tail;
		tail = x;
	}
	particleNum++;
}

ParticleSystem::~ParticleSystem() {
	Cell* copy = head;
	while(copy != nullptr) {
		Cell* temp = copy->next;
		delete copy;
		copy = temp;
	}
}
int ParticleSystem::get_row() const{
	return rows;
}

int ParticleSystem::get_columns() const{
	return columns;
}

int ParticleSystem::numParticles(){
	return particleNum;
}

void ParticleSystem::move_particle(){
	Cell* copy = head;
	for(Cell* temp = head; temp != nullptr;){
		copy = temp->next;
		temp->particle.setX(temp->particle.getXVel() + temp->particle.getX());
		temp->particle.setY(temp->particle.getYVel() + temp->particle.getY());

		temp = copy;
	}
}

void ParticleSystem::draw_particle(ParticleGraphics t){
	Cell* copy = head;
	for(Cell* temp = head; temp!= nullptr;){
		copy = temp->next;
		int x = temp->particle.getX();
		int y = temp->particle.getY();
		if(x <= rows && y <= columns && x >= 0 && y >= 0){
			int r = t.getColor(r);
			int b = t.getColor(b);
			int g = t.getColor(g);
			t.drawPoint(x, y, r, g, b);
		}
		temp = copy;
	}
}

//Firework code; Place this accordingly when you can, feel free to tell me if it doesn't work
//Also feel free to change variable names accordingly if needed
/*
	if (temp->particle.getLifetime() == 0 && temp->particle.getType() == FIREWORK) {
		int x = temp->particle.getX();
		int y = temp->particle.getY();
		Particle* currPtr = new Particle(x, y, 0, -1, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, 1, -1, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, 1, 0, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, 1, 1, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, 0, 1, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, -1, 1, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, -1, 0, 10);
		push_back(currPtr);
		Particle* currPtr = new Particle(x, y, -1, -1, 10);
		push_back(currPtr);
	}
*/
