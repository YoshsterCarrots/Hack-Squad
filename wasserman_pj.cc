//#include "Particle_System.h"
//#include "particle_graphics.h"
//#include "colors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void wasserman_project() {

	auto [rows, columns] = get_terminal_size();
	columns *= 4;
	rows *= 4;
	
	ParticleSystem.set_row(rows);
	ParticleSystem.set_columns(columns);

	if (ParticleSystem.get_row() == 0 or ParticleSystem.get_columns() == 0) die();

	clearscreen();
	ParticleGraphics.drawRectangle(0, 0, ParticleSystem.get_row(), ParticleSystem.get_columns(), 0, 0, 0);

	for (int frame = 0; frame <= 100; ++frame) {
		for (int i = 0; i < 10; ++i) {
			int x = rand() % ParticleSystem.get_columns();
			int y = rand() % ParticleSystem.get_row();
			int dx = (rand() % 15) - 7;
			int dy = (rand() % 15) -7;
			int life = 3;
			int r = rand() % 256;
			int g = rand() % 256;
			int b = rand() % 256;
			
			Particle p(x, y, dx, dy, life, Particle::BALLISTIC);
			ParticleSystem.push_back(p);
			ParticleGraphics.setColor(r, g, b);

		}

		ParticleSystem.move_particle();
		ParticleSystem.draw_particle(ParticleGraphics);

		usleep(100000);
	}
}
