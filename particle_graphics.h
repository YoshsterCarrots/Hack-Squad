#pragma once
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
	
	ParticleGraphics(int red = 0, int green = 0, int blue = 0);

	int getColor(char c) const;
	void setColor(int red, int green, int blue);
	void drawCircle(int x, int y, int radius, int red, int green, int blue);
	void drawPoint(int row, int col, int red, int green, int blue);
	void drawRectangle(int min_x, int min_y, int max_x, int max_y, int red, int green, int blue);
	void drawLine(int x1, int y1, int x2, int y2, int red, int green, int blue);

}; 
