#include "Particle_System.h"

using namespace std;

ParticleSystem::push_back(Particle p) {
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

ParticleSystem::~Particle {
	Cell* copy = head;
	while(copy != nullptr) {
		Cell* temp = copy->next;
		delete copy;
		copy = temp;
	}
}
ParticleSystem::get_row() const{
	return rows;
}

ParticleSystem::get_columns() const{
	return columns;
}

ParticleSystem::numParticles(){
	return particleNum;
}

ParticleSystem::move_particle(){
	Cell* copy = head;
	for(Cell* temp = head; temp != nullptr;){
		copy = temp->next;
		temp->Particle.setX(temp->Particle.getXVel() + temp->Particle.getX());
		temp->Particle.setY(temp->Particle.getYVel() + temp->Particle.getY());

		temp = copy;
	}
}

ParticleSystem::draw_particle(ParticleGraphics g){
	Cell* copy = head;
	for(Cell* temp = head; temp!= nullptr;){
		copy = temp->next;
		int x = temp->Particle.getX();
		int y = temp->Particle.getY();
		if(x <= rows && y <= columns && x >= 0 && y >= 0){
			int r = g.getColor();
			int b = g.getColor();
			int g = g.getColor();
			drawPoint(x, r, b, g);
		}
		temp = copy;
	}
}

ParticleSystem::delete_particle(Cell* c) {
	auto [rows, columns] = get_terminal_size();
	rows--;
	columns--;
	if (c->Particle.getX() > rows || c->Particle.getX() < 0 || c->Particle.getY() > rows || c->Particle.getY() < 0) {
		if (particleNum == 0) return;
		else if (particleNum == 1) {
			delete c;
			particleNum--;
			exit(EXIT_SUCCESS);
		}
		else {
			delete c;
			particleNum--;
		}
	}
}
