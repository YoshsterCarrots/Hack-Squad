#include "particle_graphics.h"
#include <iostream>
#include <cassert>
using namespace std;

ParticleGraphics::ParticleGraphics(int red, int green, int blue) : r(red), g(green), b(blue) {}

int ParticleGraphics::getColor(char c) const {
    if (c == 'r') return r;
    else if (c == 'g') return g;
    else return b;
}

void ParticleGraphics::setColor(int red, int green, int blue) {
    r = red;
    g = green;
    b = blue;
}

void ParticleGraphics::drawCircle(int x, int y, int radius, int red, int green, int blue) {
    if (radius <= 0) return;
    setbgcolor(red, green, blue);
    setcolor(0, 0, 0);
    for (int row = x - radius; row <= x + radius; row++) {
        for (int col = y - radius; col <= y + radius; col++) {
            int dx = row - x;
            int dy = col - y;
            if (dx * dx + dy * dy <= radius * radius) {
                movecursor(row, col);
                cout << " ";
            }
        }
    }
    cout.flush();
    resetcolor();
}

void ParticleGraphics::drawRectangle(int min_x, int min_y, int max_x, int max_y, int red, int green, int blue) {
    if (min_x >= max_x || min_y >= max_y) return;
    setbgcolor(red, green, blue);
    for (int row = min_x; row <= max_x; row++) {
        for (int col = min_y; col <= max_y; col++) {
            movecursor(row, col);
            cout << " ";
        }
    }
    cout.flush();
    resetcolor();
}

void ParticleGraphics::drawLine(int x1, int y1, int x2, int y2, int red, int green, int blue) {
    //assert(x1 >= 0 && x2 >= 0 or y1 >= 0 && y2 >= 0);
    //assert((x1 == x2) || (y1 == y2)); // Ensure the line is either vertical or horizontal
    setbgcolor(red, green, blue);

    if (x1 == x2) { // Vertical Line
        int y_start = (y1 < y2) ? y1 : y2;
        int y_end = (y1 > y2) ? y1 : y2;
        for (int y = y_start; y <= y_end; y++) {
            movecursor(x1, y);
            std::cout << " ";
        }
    } else if (y1 == y2) { // Horizontal Line
        int x_start = (x1 < x2) ? x1 : x2;
        int x_end = (x1 > x2) ? x1 : x2;
        for (int x = x_start; x <= x_end; x++) {
            movecursor(x, y1);
            cout << " ";
        }
    }

    cout.flush();
    resetcolor();
}

void ParticleGraphics::drawPoint(int row, int col, int red, int green, int blue) {
    setbgcolor(red, green, blue);
    movecursor(row, col);
    cout << " ";
    cout.flush();
    resetcolor();
}









