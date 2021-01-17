/**
* FILE: pongball.h
* TITLE: pongball
*
* PURPOSE:
*
* This is the class for the ball of the pong side game
*
* CLASS:
* PongBall
*
*	FUNCTIONS:
*
*	getX
*		returing position on x axis
*
*	getY
*		returning position on y axis
*
*	getDir
*		returning direction (left-right)
*
*	update
*		update function
*
*	draw
*		drawing the maze
*
*	getCollsionHull
*		returning the collision area
*
*	isActive
*		returning bool indicating if the ball is active
*
*	changeDirection
*		chaning ball direction
*	
*	setAngle
*		changing ball angle
*
* INCLUDED FILES:
*
* graphics.h
* config.h
* gameelement.h
* random
* 
* @file pongball.h
**/

#pragma once

#include "config.h"
#include "graphics.h"
#include "gameelement.h"
#include <random>

class PongBall : public CollidableD
{
	Position pos{ CANVAS_WIDTH / 2, 10.f + (std::rand() % (CANVAS_HEIGHT -10 + 1)) }; // ball position
	Disk disk; // disk area for collision
	bool active = true; // boolean indicating if the ball is active
	float dir = 1.f, // direction (left-right)
		angleY = 1.f, // angle on y axis
		angleX = 1.f; // angle on x axis
	graphics::Brush brush; // brush for drawing
	const class Menu& menu; // running instance of class
public:
	float getX() { return pos.x; }; // returing ball position on x axis
	float getY() { return pos.y; }; //returning ball position on y axis
	float getDir() { return dir; }; // returning direction
	void update(); // update function
	void draw(); // drawing function
	Disk getCollisionHull() const override; // returnin a disk indicating the collision area
	bool isActive() { return active; }; // returning a bool indicating if the ball is active
	void changeDirection(); // changing direction
	void setAngle(Rectangle& rect); // chaning angle
	PongBall(const class Menu& ingame); // constructor
	~PongBall(); // destructor
};
