#include <iostream>
using namespace std;


class ParticleGraphics {


	private:

	int r;
	int g;
	int b;

	public:
	
	ParticleGraphics() : r() g() b() {}

	void getColor() const {

	}

	void setColor(int red, int green, int blue) {

		r = red;
		g = green;
		b = blue;

	}


