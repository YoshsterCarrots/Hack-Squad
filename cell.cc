//This is a placeholder

Color::Color(int red, int green, int blue) {
	r = red;
	g = green;
	b = blue;
}

Particles::Particles(Color& c, double new_x, double new_y) {
	x = new_x;
	y = new_y;
	color = c;
}

Cell::Cell(const Particle& p, Cell* new_next, Cell* new_prev) {
	particle = p;
	next = new_next;
	prev = new_prev;
}
