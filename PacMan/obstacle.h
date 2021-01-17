/**
* FILE: obstacle.h
* TITLE: obstacle 
*
* PURPOSE:
*
* This is the class for the obstacles which do not permit pacman/ghosts to move freely
*
* CLASS:
* Obstacle
*
*	FUNCTIONS:
*
*	getCollisionHull
*		returning the collision area
*
* INCLUDED FILES:
*
* graphics.h 
* config.h
* maze.h
* gameelement.h
*
* @file obstacle.h
**/

#pragma once

#include "config.h"
#include "graphics.h"
#include "maze.h"
#include "gameelement.h"

class Obstacle : public CollidableR
{
	Position pos, w_h; // position (x,y) of the obstacle and width/height
protected:
	const class Menu& menu; // the running instance of the menu
public:
	Rectangle getCollisionHull() const; // returning the collision areas of the obstacle
	Obstacle(const class Menu& ingame, float x, float y, float w, float h); // constructor
	~Obstacle(); // destructor
};