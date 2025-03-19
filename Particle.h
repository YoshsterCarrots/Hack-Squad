#pragma once

class Particle {
	public:
		enum moveType {
			STREAMER, BALLISTIC, FIREWORK
		};

	private:
		int xPos = 0;
		int yPos = 0;
		int xVel = 0;
		int yVel = 0;
		int lifetime = 0;
		enum moveType type = STREAMER;

	public:
		
		Particle(int x = 0, int y = 0, int dx = 0, int dy = 0, int life = 0, enum moveType movementType = STREAMER);

		int getX() const {return xPos;}
		int getY() const {return yPos;}
		int getXVel() const {return xVel;}
		int getYVel() const {return yVel;}
		int getLifetime() const {return lifetime;}
		enum moveType getType() const {return type;}

		void setX(int value);
		void setY(int value);
		void setXVel(int value);
		void setYVel(int value);
		void setLifetime(int value);
		void setType(moveType value);

		//Updates particle position depending on velocity
		//Can take parameters to add acceleration
		void doPhysics(int xAcceleration = 0, int yAcceleration = 0);

		void drawPoint();

};
