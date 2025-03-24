#include <iostream>
#include <csignal>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "/public/colors.h"
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"

using namespace std;

int click_row = 0;
int click_col = 0;
bool mousedown = false;

void die() {
	cout << "BAD INPUT!" << endl;
	exit(EXIT_FAILURE);
}

void click(int row, int column) {
	click_row = row;
	click_col = column;
	mousedown = true;
}

void release(int row, int column) {
	click_row = row;
	click_col = column;
	mousedown = false;
}

void stop() {
	set_mouse_mode(false);
	set_raw_mode(false);
	show_cursor(true);
	clearscreen();
	setbgcolor(0, 0, 0);
	setcolor(255, 255, 255);
	int alice = system("clear");
}

void interrupt(int x) {
	exit(0);
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
			if (amount < 1 || amount > 5) die();
		}
		int get_radius() const {
			return radius;
		}
		void set_radius(int num) {
			radius = num;
			if (radius < 1 || radius > 10) die();
		}
};

int main() {
	srand(time(0));
	Bombs bomb;
	vector<vector<char>> pain;
	int ROW = 0;
	int COL = 0;
	const char SOLID = 'X';
	const char OPEN = ' ';

	while(true) {
		cout << "How many bombs would you like? (Max: 5)" << endl;
		cout << "Amount: ";
		int number = 0;
		cin >> number;
		if (!cin) die();
		else bomb.set_amount(number);

		cout << "Amount of bombs: " << bomb.get_amount() << endl;

		cout << "How big do you want the bombs to be? (Max radius: 10)" << endl;
		cout << "Radius: ";
		cin >> number;
		if (!cin) die();
		else bomb.set_radius(number);

		clearscreen();
		char answer = 'N';
		cout << "Amount of bombs: " << bomb.get_amount() << endl << "Radius of bombs: " << bomb.get_radius() << endl;
		cout << "Is this your desired amount and radius? (Y/N)" << endl;
		cin >> answer;
		if (!cin) die();
		else if (answer == 'N') {
			clearscreen();
			continue;
		}
		else if(answer == 'Y') break;
		else die();
	}

	auto [rows, cols] = get_terminal_size();
	ROW = rows - 1;
	COL = cols;
	pain.resize(rows);
	for (vector<char> &row : pain) row.resize(COL, OPEN);
	
	ParticleGraphics rand_colors(rand() % 255, rand() % 255, rand() % 255);
	signal(SIGINT, interrupt);
	show_cursor(false);
	set_raw_mode(true);
	set_mouse_mode(true);
	on_mousedown(click);
	on_mouseup(release);
	atexit(stop);
	clearscreen();
	
	while(true) {
		movecursor(ROW, 0);
		cout << "Q to quit" << endl;
		
		char c = quick_read();
		if (c == ERR);
		else if (c == 'q') break;
		else if (c == mousedown) {
			mousedown = false;
			if (click_row >= ROW || click_col >= COL || click_row < 0 || click_col < 0) continue;
			if (pain.at(click_row).at(click_col) == OPEN) {
				pain.at(click_row).at(click_row) = SOLID;
			}
			movecursor(click_row, click_col);
			rand_colors.drawCircle(click_row, click_col, bomb.get_radius(), rand() % 255, rand() % 255, rand() % 255);
			bomb.set_amount(bomb.get_amount() - 1);
		}
		usleep(100'000);
	}
}
