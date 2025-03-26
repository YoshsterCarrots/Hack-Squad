#include <iostream>
#include <csignal>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "nicolas_project.h"
#include "/public/colors.h"
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"

using namespace std;
using namespace chrono;

double delta_t = 0.01;
int click_row = -1, click_col = -1;
bool mouse_down = false;

void bailout() {
	set_mouse_mode(false);
	set_raw_mode(false);
	show_cursor(true);
	clearscreen();
	setbgcolor(0, 0, 0);
	setcolor(255, 255, 255);
	int booya = system("clear");
}

void interrupt_handler(int x) {
	exit(0);
}

void mouse_handler(int row, int col) {
	click_row = row;
	click_col = col;
	mouse_down = true;
}

void mouse_handler2(int row, int col) {
	click_row = row;
	click_col = col;
	mouse_down = false;
}

void wait(int seconds) {
	this_thread::sleep_for(chrono::seconds(seconds));
}

void die() {
	cout << "BAD INPUT!" << endl;
	exit(EXIT_FAILURE);
}

class Bombs {
	private:
		int amount = 0;
		int radius = 0;
	public:
		int get_amount() const {
			return amount;
		}
		void set_amount(int num) {
			amount = num;
			if (amount < 0 || amount > 5) die();
		}
		int get_radius() const {
			return radius;
		}
		void set_radius(int num) {
			radius = num;
			if (radius < 1 || radius > 10) die();
		}
};

void nicolas_project() {
	srand(time(0));
	Bombs bomb;
	clearscreen();

	while (true) {
		cout << "How many paintballs would you like? (Max: 5)" << endl;
		cout << "Amount: ";
		int number = 0;
		cin >> number;
		if (!cin) die();
		else bomb.set_amount(number);

		cout << "Amount of bombs: " << bomb.get_amount() << endl;

		cout << "How big do you want the paintballs to be? (Max radius: 10)" << endl;
		cout << "Radius: ";
		cin >> number;
		if (!cin) die();
		else bomb.set_radius(number);

		clearscreen();
		char answer = 'N';
		cout << "Amount of paintballs: " << bomb.get_amount() << endl << "Radius of paintballs: " << bomb.get_radius() << endl;
		cout << "Is this your desired amount and radius? (Y/N)" << endl;
		cin >> answer;
		if (!cin) die();
		else if (answer == 'N') {
			clearscreen();
			continue;
		} else if (answer == 'Y') break;
		else die();
	}
//	ParticleSystem system;
	ParticleGraphics rand_colors(rand() % 255, rand() % 255, rand() % 255);
	vector<vector<char>> world; //Holds an 'X' if the spot is solid, ' ' otherwise
	const char SOLID = 'X';
	const char OPEN = ' ';
	int ROWS = 10, COLS = 10;

	//Set up colorslib
	atexit(bailout); //Call this function when we quit
	signal(SIGINT, interrupt_handler); //If the user hits ctrl-c call this function
	show_cursor(false); //Turn off the cursor
	set_raw_mode(true); //Turn on raw mode for immediate key presses
	set_mouse_mode(true); //Accept mouse input
	on_mousedown(mouse_handler); //When the mouse is clicked call this
	on_mouseup(mouse_handler2); //When they release the mouse call this function
	setbgcolor(100, 100, 100); //Set the background color to medium grey
	clearscreen(); //Wipe the screen

	//C++17 Feature called a structured binding, which allows you to split apart a struct returned by a function into reg variables
	auto [rows, cols] = get_terminal_size();
	ROWS = rows - 1;
	COLS = cols;
	world.resize(rows);
	for (vector<char> &row : world) row.resize(COLS, OPEN);

//	system.set_row(rows);
//	system.set_columns(cols);

	//This is how you can get the time in C++
	auto last_time = high_resolution_clock::now();

	while (true) {
		//FPS Calculation
		auto cur_time = high_resolution_clock::now();
		duration<double> diff = cur_time - last_time;
		delta_t = diff.count();
		movecursor(ROWS, 0);
		setbgcolor(0, 0, 0);
		cout << "FPS: " << 1 / delta_t << "                  " << endl;
		cout << "Q to quit" << endl;
		last_time = cur_time;

		//Non-blocking I/O read, so it can read a keypress immediately
		//Does not need the user to hit enter, since we turned on raw mode above
		if (bomb.get_amount() == 0) {
			break;
		}

		int ch = quick_read();
		if (ch == ERR) { //ERR means "no keypress read"
						 //Do nothing
		}
		// Exit if user presses 'q'
		if (ch == 'q') {
			continue;
		}
		if (mouse_down) {
			mouse_down = false;
			if (click_row >= ROWS or click_col >= COLS or click_row < 0 or click_col < 0) continue;
			if (world.at(click_row).at(click_col) == OPEN) {
				world.at(click_row).at(click_row) = SOLID;
			}
			//			movecursor(click_row, click_col);
			if (bomb.get_amount() != 0) {
				rand_colors.drawCircle(click_row, click_col, bomb.get_radius(), rand() % 255, rand() % 255, rand() % 255);
//				Particle p(click_row, click_col, (rand() % 10) + 1, (rand() % 10) + 1, 250, Particle::FIREWORK);
//				system.push_back(p);
				bomb.set_amount(bomb.get_amount() - 1);
			}
			//			setbgcolor(120, 60, 120);
			//			cout << " ";
		}
//		system.move_particle();
//		clearscreen();
//		system.draw_particle(rand_colors);
		usleep(100'000);
	}
	wait(3);
}

