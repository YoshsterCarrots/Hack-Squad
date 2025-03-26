#include <iostream>
#include <unistd.h>
#include "colors.h"
#include "Particle_System.h"
#include <climits>
using namespace std;

void runYoshster() {
	show_cursor(false);

	ParticleSystem system;
	ParticleGraphics graphics(255, 255, 255);

	auto [rows, columns] = get_terminal_size();
	system.set_row(rows);
	system.set_columns(columns);

	//Particle ball = new Particle(system.get_row() + 10, 0, 1, 1);
	//system.push_back(*ball);

	system.push_back(Particle(system.get_columns() - 20, 0, 1, 1, INT_MAX));
	Cell* ball = system.getHead();

	while (true) {
		clearscreen();
		system.move_particle();
		system.draw_particle(graphics);
		usleep(50'000);

		if (ball->particle.getX() == 0 || ball->particle.getX() == columns) {
			ball->particle.setXVel(ball->particle.getXVel() * -1);
			system.push_back(Particle(ball->particle.getX(), ball->particle.getY(), 0, 0, 0, Particle::FIREWORK));
		}
		if (ball->particle.getY() == 0 || ball->particle.getY() == rows) {
			ball->particle.setYVel(ball->particle.getYVel() * -1);
			system.push_back(Particle(ball->particle.getX(), ball->particle.getY(), 0, 0, 0, Particle::FIREWORK));
		}

	}

}
