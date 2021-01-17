/**
* FILE: pong.h
* TITLE: pong class header file
*
* PURPOSE:
*
* This is the header file of the pong class (the rackets for the pong game)

* FUNCTIONS: 
*
* update
*   updating the rackets
*
* draw
*   drawing the rackets
*
* INCLUDED FILES:
*
* random
* config.h
* graphics.h
* gameelement.h
* pongball.h
*
* @file pong.h
**/

#pragma once

#include <random>
#include "config.h"
#include "graphics.h"
#include "gameelement.h"
#include "pongball.h"

class Pong: public CollidableR
{
	Position pos{100, CANVAS_HEIGHT / 2 }; // Starting position of the rackets
	bool ai; // Boolean indicating if computer or player is playing
	float move = 0.f, // the moving distance
		  time_counter = 0.f; // a time counter
	int error = std::rand() % (5 + 1) ; // an error for the ai component
	graphics::Brush brush; // a general brush
	const class Menu& menu; // a menu variable
public:
	void update(); // Update function
	void draw(); // Draw function
	Rectangle getCollisionHull() const override; // Calculating the rectangle for the collision
	Pong(const class Menu& ingame, bool is_ai); // Constructor
	~Pong(); // Destructor
};
