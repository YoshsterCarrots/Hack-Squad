#include <string>
#include <iostream>
#include <sys/ioctl.h>
#include <utility>
#include "cell.h"
#include "Particle.h"
#include "particle_graphics.h"

using namespace std;



class ParticleSystem{

	int rows = 0;
	int columns = 0;
	int particleNum = 0;
	Cell* head = nullptr;
	Cell* tail = nullptr;

	void push_back(Particle p) {
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
	~Particle {
		Cell* copy = head;
		for (Cell* temp = head; temp != nullptr;) {
			copy = temp->next;
			delete temp;
			temp = copy;
		}
	}

	int get_row() const{
		return rows;
	}

	int get_columns() const{
		return columns;
	}

	int numParticles(){
		return particleNum;
	}

	void move_particle(){
		Cell* copy = head;
		for(Cell* temp = head; temp != nullptr;){
			copy = temp->next;
			temp->Particle.setX(temp->Particle.getXVel() + temp->Particle.getX());
			temp->Particle.setY(temp->Particle.getYVel() + temp->Particle.getY());

			temp = copy;
		}
	}

	void draw_particle(ParticleGraphics g){
		Cell* copy = head;
		for(Cell* temp = head; temp!= nullptr;){
			copy = temp->next;
			int x = temp->Particle.getX();
			int y = temp->Particle.getY();
			if(ParticleLoc <= rows && ParticleLoc <= columns){
				int r = g.getColor();
				int b = g.getColor();
				int g = g.getColor();
				drawPoint(x, r, b, g);
			}
			temp = copy;
		}
	}
};
