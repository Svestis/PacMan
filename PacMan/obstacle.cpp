/**
* FILE: obstacle.cpp
* TITLE: obstalce class cpp file
*
* PURPOSE:
*
* This is the implementation file of the obstacle class (the walls of the maze)

* FUNCTIONS:
*
* getCollisionHull
*	returning the collision area for the obstacles
*
* INCLUDED FILES:
*
* obstacle.h
*
* @file obstacle.cpp
**/

#include "obstacle.h"

/**
* Returns the collision space of the obstacle
*
* NAME: getCollisionHull
*
* @param none
* @return a rectangle shape indicating the rectangle area of collision of the obstacle
* @rtype Rectangle
*
**/
Rectangle Obstacle::getCollisionHull() const
{
	Rectangle rect;
	rect.cx = pos.x;
	rect.cy = pos.y;
	rect.w = w_h.x;
	rect.h = w_h.y;
	return rect;
}

/**
* Construcctor for the pong racket
*
* NAME: Obstacle
*
* @param ingame
* @param_type Menu reference
* @return an instance of the obstacle class initialized with a reference to the Menu running instance
* @rtype obstacle instance
*
**/
Obstacle::Obstacle(const Menu& ingame, float x, float y, float w, float h)
	:menu(ingame)
{
	pos.x = x;
	pos.y = y;
	w_h.x = w;
	w_h.y = h;
}

/**
* Destructor for the obstacle
*
* NAME: ~Obstacle
*
* @param none
* @return none
*
**/
Obstacle::~Obstacle()
{
}
