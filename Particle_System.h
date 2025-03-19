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
	public:
		void push_back(Particle p);

		~Particle;

		int get_row() const;

		int get_columns() const;

		int numParticles();

		void move_particle();

		void draw_particle(ParticleGraphics g);

		void delete_particle(Cell* c);
};
