#include <iostream>
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
	void drawOval(int x, int y,int width,int height) {
	
	}
	void drawPoint(int row, int col, red, green, blue) {
		assert( row >= 0 and col >= 0);
		resetcolor();
		setbgcolor(red, green, blue);
		movecursor(row, col);
		cout << " ";
		cout.flush();
		resetcolor();
	}
	void drawRectangle(int x, int y,int width,int height) {

	}
	void drawPolygon(int numPoints) {

	}
	void drawLine(int x1, int y1, int x2, int y2) {

	} 



}; 
