#include <iostream>
#include "nicolas_project.h"
#include "wasserman_pj.h"
#include "cell.h"
#include "Particle.h"
#include "Particle_System.h"
#include "particle_graphics.h"
using namespace std;

int main() {
	int choice;

	cout << "Choose an option: \n";
	cout << "1. Levi's Project\n";
	cout << "2. Wei's Project\n";
	cout << "3. Nicolas's Project\n";
	cout << "4. Jacob's Project\n";

	cin >> choice;

	if (choice == 1) {
		nicolas_project();
		clearscreen();
	} else if (choice == 2) {
		//placeholder
	} else if (choice == 3) {
		//placeholder
	} else if (choice == 4) {
		wasserman_project();
		clearscreen();
	}



}
