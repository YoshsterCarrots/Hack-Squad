#include "Particle_System.h"
#include "Particle.h"

using namespace std;

//pushes a particle back into the doubly linked list cell
void ParticleSystem::push_back(Particle p){
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

//deletes all new cell pointers at the end of the program
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

void ParticleSystem::set_row(int r) {
	rows = r;
}

int ParticleSystem::get_columns() const{
	return columns;
}

void ParticleSystem::set_columns(int c) {
	columns = c;
}

int ParticleSystem::numParticles(){
	return particleNum;
}

void ParticleSystem::move_particle(){
	Cell* copy = head;
	for(Cell* temp = head; temp != nullptr;){
		//Setting values;
		copy = temp->next;
		int x = temp->particle.getX();
		int y = temp->particle.getY();
		//WALL
		if (temp->particle.getLifetime() == 0 && temp->particle.getType() == Particle::FIREWORK) {
			//int x = temp->particle.getX();
			//int y = temp->particle.getY();
			push_back(Particle(x, y, 0, -1, 10));
			push_back(Particle(x, y, 1, -1, 10));
			push_back(Particle(x, y, 1, 0, 10));
			push_back(Particle(x, y, 1, 1, 10));
			push_back(Particle(x, y, 0, 1, 10));
			push_back(Particle(x, y, -1, 1, 10));
			push_back(Particle(x, y, -1, 0, 10));
			push_back(Particle(x, y, -1, -1, 10));
		}
		//WALL
		//if temp's x or y is out of the screen then it will be deleted or if its lifetime is 0.
		if(x > rows || x < 0 || y > columns || y < 0 || temp->particle.getLifetime() <= 0){
			if(temp->prev == nullptr){
			Cell* copy = temp;
			temp = temp->next;
			delete copy;
			particleNum--;
			}
			else if(temp->next == nullptr){
			delete temp;
			particleNum--;
			}else{
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			particleNum--;
			}
		}
		else{
		temp->particle.setX(temp->particle.getXVel() + x);
		temp->particle.setY(temp->particle.getYVel() + y);
		}
		
		//Moving to next Cell.
		temp = copy;
	}
}

void ParticleSystem::draw_particle(ParticleGraphics t){
	Cell* copy = head;
	for(Cell* temp = head; temp!= nullptr;){
		copy = temp->next;
		//Get x and y of particle.
		int x = temp->particle.getX();
		int y = temp->particle.getY();
		//Checks that the particle is within the screen then draws it.
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
