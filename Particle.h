#pragma once

class Particle {
	private:
		int xPos = 0;
		int yPos = 0;
		double velocity = 0;
		int lifetime = 0;
		moveType type = 0;

	public:
		enum moveType {
			STREAMER, BALLISTIC, FIREWORK
		};
		
		Particle(int x = 0, int y = 0, double vel = 0, int life = 0, moveType movementType = 0);

		int getX() const {return xPos;}
		int getY() const {return yPos;}
		double getVelocity() const {return velocity;}
		int getLifetime() const {return lifetime;}
		movetype getType() const {return type;}

		void setX(int value);
		void setY(int value);
		void setVelocity(double value);
		void setLifetime(int value);
		void setType(moveType value);

		void physics();

		void draw();

};
