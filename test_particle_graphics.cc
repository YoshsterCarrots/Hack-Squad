#include "particle_graphics.h"
#include <iostream>

using namespace std;



int main() {
    clearscreen();

    ParticleGraphics pg(255, 255, 255); // Initial color for particles

    // Test draw point
    pg.drawPoint(5, 5, 255, 0, 0);

    // Test draw rectangle
    pg.drawRectangle(7, 10, 12, 20, 0, 255, 0);

    // Test draw vertical line
    pg.drawLine(17, 5, 17, 25, 255, 255, 0);

    // Test draw horizontal line
    pg.drawLine(25, 15, 30, 15, 255, 255, 0);

    // Test draw circle
    pg.drawCircle(10, 50, 5, 255, 0, 255);

    movecursor(25, 0);
    resetcolor();
    cout << endl;

    return 0;
}
