#include <iostream>
#include <cassert>
#include <algorithm>
#include "colors.h"
using namespace std;


class ParticleGraphics {


	private:

	int r = 0;
	int g = 0;
	int b = 0;

	public:
	
	ParticleGraphics(int red = 0, int green = 0, int blue = 0) : r(red), g(green), b(blue) {}

	int getColor(char c) const {
		if (c == 'r') return r;
		else if (c == 'g') return g;
		else return b;
	}
	void setColor(int red, int green, int blue) {

		r = red;
		g = green;
		b = blue;

	}
	void drawCircle(int x, int y, int radius, int red, int green, int blue) {
		assert(radius > 0);
		setbgcolor(red, green, blue);
		for (int row = x - radius; row <= x + radius; row++) {
			for (int col = y - radius; col <= y + radius; col++) {
				int dx = row - x;
				int dy = col - y;
				if (dx * dx + dy * dy <= radius * radius) {
					movecursor(row,col);
					cout << " ";
				}
			}
		}
		cout.flush();
		resetcolor();
	}
	void drawPoint(int row, int col, int red, int green, int blue) {
		assert( row >= 0 and col >= 0);
		setbgcolor(red, green, blue);
		movecursor(row, col);
		cout << " ";
		cout.flush();
		resetcolor();
	}
	void drawRectangle(int min_x, int min_y, int max_x, int max_y, int red, int green, int blue) {
		assert(min_x < max_x);
		assert(min_y < max_y);
		setbgcolor(red, green, blue);
		for (int row = min_x; row <= max_x; row++) {
			for (int col = min_y; col <= max_y; col++) {
				movecursor(row,col);
				cout << " ";
			}
		}
		cout.flush();
		resetcolor();
	}

	void drawLine(int x1, int y1, int x2, int y2, int red, int green, int blue) {
		assert(x1 >= 0 and x2 >= 0 and y1 >= 0 and y2 >= 0);
		assert((x1 == x2) or (y1 == y2));
		setbgcolor(red, green, blue);
		if (x1 == x2) { //Verticle Line
			int y_start = (y1 < y2) ? y1 : y2;
			int y_end = (y1 > y2) ? y1 : y2;
			for (int y = y_start; y <= y_end; y++) {
				movecursor(x1, y);
				cout << " ";
			}

		}
		else if (y1 == y2) { //Horizontal Line
			int x_start = (x1 < x2) ? x1 : x2;
			int x_end = (x1 > x2) ? x1 : x2;
			resetcolor();
			setbgcolor(red, green, blue);
			for (int x = x_start; x <= x_end; x++) {
				movecursor(x, y1);
				cout << " ";
			}
		}

		cout.flush();
		resetcolor();
	} 



}; 
