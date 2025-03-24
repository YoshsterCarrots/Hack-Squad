#include <iostream>
//#include "Particle.h"
//#include "cell.h"
#include "Particle_System.h"
//#include "particle_graphics.h"
#include <unistd.h>
#include "colors.h"
using namespace std;

int main() {
	show_cursor(false);

	ParticleSystem system;
	ParticleGraphics graphics(255, 255, 255);

	Particle aaa(40, 80, 0, -1, 30, Particle::FIREWORK);
	system.push_back(aaa);

	Particle bbb(20, 0, 1, 0, 30, Particle::BALLISTIC);
	system.push_back(bbb);

	Particle ccc(0, 20, 1, 0, 50, Particle::STREAMER);
	system.push_back(ccc);

	auto [rows, columns] = get_terminal_size();
	system.set_row(rows);
	system.set_columns(columns);

	for (int i = 0; i < 100; i++) {
		clearscreen();
		system.draw_particle(graphics);
		system.move_particle();
		usleep(100'000);
	}


	return 0;
}
