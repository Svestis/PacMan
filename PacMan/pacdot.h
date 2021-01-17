/**
* FILE: pacdot.h
* TITLE: pacdot
*
* PURPOSE:
*
* This is the class for the pacdots of the pacman.
*
* CLASS:
* Pacdot
*
*	FUNCTIONS:
*
*	draw
*		drawing the pacdot
*
*	getBig
*		returning boolean on if the pacdot is a superdot
*
*	getCollisionHull
*		returning the collisionarea

* INCLUDED FILES:
*
* graphics.h
* config.h
* maze.h
* gameelement.h
*
* @file pacdot.h
**/

#pragma once

#include "config.h"
#include "graphics.h"
#include "maze.h"
#include "gameelement.h"

class Pacdot: public CollidableD
{
	graphics::Brush brush; // the brush used for drawing
	Disk disk; // disk indicating the collision area
	Position pos; // the position (x,y) of the pacdot
	bool modern, // indicating if we are playing on modern mode or not
		 big; // indicating if this pacdot is big (superdot)
protected:
	const class Menu& menu; // running instance of menu
public:
	void draw(); // drawing the pacdots
	bool getBig() { return big; }; // returining if the pacdot is a superdot
	Disk getCollisionHull() const; // returning collision area as disk
	Pacdot(const class Menu& ingame, int x, int y, bool is_big); // constructor
	~Pacdot(); // destructor
};