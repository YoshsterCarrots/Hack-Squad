#include "particle_graphics.h"
#include "colors.h"
//#include <uistd.h>

int main() {

	clearscreen();

	ParticleGraphics pg;

	//auto [rows, cols] = get_terminal_size();
    //cout << "Terminal size: " << rows << " rows x " << cols << " cols\n";
	//test draw point
	pg.drawPoint(5, 5, 255, 0, 0);

	//test draw rect
	pg.drawRectangle(7,10,12,20,0,255,0);

	//test draw line
	pg.drawLine(17, 5, 25, 5, 255, 255, 0);

	//test draw line horizontal
	pg.drawLine(25, 15, 25, 20, 255, 255, 0);

	// test circle
	pg.drawCircle(10,50,5,255,0,255);

	movecursor(25,0);
	resetcolor();
	cout << endl;

	return 0;

}
