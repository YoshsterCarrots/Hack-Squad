#pragma once

#include <string>
#include <iostream>
#include <sys/ioctl.h>
#include <utility>
#include "cell.h"
#include "Particle.h"
#include "particle_graphics.h"

using namespace std;



class ParticleSystem{
	private:
		int rows = 0;
		int columns = 0;
		int particleNum = 0;
		Cell* head = nullptr;
		Cell* tail = nullptr;
		void delete_particle(Cell* c) {
			auto [rows, columns] = get_terminal_size();
			rows--;
			columns--;
			if (c->particle.getX() > rows || c->particle.getX() < 0 || c->particle.getY() > rows || c->particle.getY() < 0) {
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
	public:
		void push_back(Particle& p) const;

		~ParticleSystem();

		int get_row() const;

		int get_columns() const;

		int numParticles();

		void move_particle();

		void draw_particle(ParticleGraphics g);

};
