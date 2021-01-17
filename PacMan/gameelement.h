/**
* FILE: gameelement.h
* TITLE: gameelement
*
* PURPOSE:
*
* This is the base class for multiple elements of the project, including but not limited to the pacman, the phantoms, the pong and others, as well as the Rectangle and Disk collision classes
* It also includes some typedefs for the rotation of the game elements, the direction as well as the structs of the position, the rectangle and the Disk serving the collision purposes
*
* CLASS: 
* CollidableR / collidableD

*	FUNCTIONS:
*
*	getCollisionHull
*		Returning the collision points depending on the class that calls the function
*
* CLASS:
* GameElement
*	
*	FUNCTIONS:
*
*	update
*		virtual
*
*	draw
*		virtual
*
*	init
*		virtual
*
*	updateLeftC
*		virtual
*
*	updateRightC
*		virtual
*
*	updateUpC
*		virtual
*	
*	updateDownC
*		virtual
*
*	updateLeftM
*		virtual
*
*	updateRightM
*		virtual
*
*	updateDownM
*		virtual
*
*	updateUpM
*		virtual
*
*	updateC
*		virtual
*
*	updateM
*		virtual
*
* INCLUDED FILES:
*
* None
*
* @file gameelement.h
**/

#pragma once

typedef enum { UP1, UP2, UP3, DOWN1, DOWN2, DOWN3, LEFT1, LEFT2, LEFT3, RIGHT1, RIGHT2, RIGHT3, CENTER } rotation; // defining the position enum values

typedef enum {UP, DOWN, LEFT, RIGHT} direction; // defining the direction enum values

struct Position
{
	float x, y;
}; // defining the position type

struct Rectangle
{
	float cx, cy, w, h;
}; // defining the rectangle type

struct Disk
{
	float cx, cy;
	float radius;
}; // defining the disk type

class CollidableR
{
public:
	virtual Rectangle getCollisionHull() const = 0;
}; // defining the rectangle Collidable virtual class

class CollidableD
{
public:
	virtual Disk getCollisionHull() const = 0;
}; // defining the disk collidable virtual class

class GameElement
{
protected:
	const class Menu& menu; // the running instance of the menu
public:
	GameElement(const class Menu& ingame); // constructor
	virtual void update() = 0; // update virtual function
	virtual void draw() = 0; // draw virtual function
	virtual void init() = 0; // init virtual function
	virtual void updateLeftC() = 0; // updateLeftC virtual function
	virtual void updateRightC() = 0; // updateRightC virtual function
	virtual void updateUpC() = 0; // updateUpC virtual function
	virtual void updateDownC() = 0; // updateDownC virtual function
	virtual void updateLeftM() = 0; // updateLeftM virtual function
	virtual void updateRightM() = 0; // updateRightM virtual function
	virtual void updateUpM() = 0; // updateUpM virtual function
	virtual void updateDownM() = 0; // updateDoWnM virtual function
	virtual void updateC() = 0; // updateC virtual function
	virtual void updateM() = 0; // updateM virtual function
};
