#include "Particle_System.h"
#include "particle_graphics.h"
#include "colors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void wasserman_project() {
	
	ParticleSystem ps;
	ParticleGraphics pg(0, 0, 0);


	auto [rows, columns] = get_terminal_size();
	columns *= 4;
	rows *= 4;
	
	ps.set_row(rows);
	ps.set_columns(columns);

	if (ps.get_row() == 0 or ps.get_columns() == 0) return;

	clearscreen();
	pg.drawRectangle(0, 0, ps.get_row(), ps.get_columns(), 0, 0, 0);

	for (int frame = 0; frame <= 100; ++frame) {
		for (int i = 0; i < 10; ++i) {
			int x = rand() % ps.get_columns();
			int y = rand() % ps.get_row();
			int dx = (rand() % 15) - 7;
			int dy = (rand() % 15) -7;
			int life = 3;
			int r = rand() % 256;
			int g = rand() % 256;
			int b = rand() % 256;
			
			Particle p(x, y, dx, dy, life, Particle::BALLISTIC);
			ps.push_back(p);
			pg.setColor(r, g, b);

		}

		ps.move_particle();
		ps.draw_particle(pg);

		usleep(100000);
	}
}
