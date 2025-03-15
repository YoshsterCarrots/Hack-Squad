#include <iostream>
using namespace std;


class ParticleGraphics {


	private:

	int r;
	int g;
	int b;

	public:
	
	ParticleGraphics(int red = 0, int green = 0, int blue = 0) : r(red) g(green) b(blue) {}

	void getColor() const {

	}
	void setColor(int red, int green, int blue) {

		r = red;
		g = green;
		b = blue;

	}
	void drawOval(int x, int y,int width,int height) {
	
	}
	void drawPoint(int x, int y) {

	}
	void drawRectangle(int x, int y,int width,int height) {

	}
	void drawPolygon(int numPoints) {

	}
	void drawLine(int x1, int y1, int x2, int y2) {

	} 



}; 
