#include <iostream>
#include <cstdlib>
#include <ctime>
#include "/public/colors.h"
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"

using namespace std;

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
	
	ParticalGraphics rand_colors(rand() % 255, rand() % 255, rand() % 255);
	set_raw_mode(true);
	set_mouse_mode(true);

	set_raw_mode(false);
	set_mouse_mode(false);
}
