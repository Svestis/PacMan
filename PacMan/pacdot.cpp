/**
* FILE: pacdot.cpp
* TITLE: pacdot class cpp file
*
* PURPOSE:
*
* This is the implementation file of the pacdot class (the pills that pacman eats)
*
* FUNCTIONS:
*
* draw
*   drawing the pacdots
*
* getCollisionHull
*	returning the collision area for the pacdots
*
* INCLUDED FILES:
*
* pacdot.h
* config.h
* menu.h
*
* @file pacdot.cpp
**/

#include "pacdot.h"
#include "config.h"
#include "menu.h"

/**
* Draws the pacdot
*
* NAME: draw
*
* @param none
* @return none
*
**/
void Pacdot::draw()
{
	brush.outline_opacity = 0.f;
	if (modern) // modern case
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_M);
		if (!big)
		{
			graphics::drawRect(pos.x, pos.y, 25, 25, brush);
		}
		else
		{
			graphics::drawRect(pos.x, pos.y, 35, 35, brush);
		}
	}
	else // non modern case
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_C);
		if (!big)
		{
			graphics::drawRect(pos.x, pos.y, 15, 15, brush);
		}
		else
		{
			graphics::drawRect(pos.x, pos.y, 25, 25, brush);
		}
	}
}

/**
* Construcctor for the pacdot
*
* NAME: Pacdot
*
* @param ingame
* @param_type Menu reference
* @param x indicating the position of the pacdot
* @param_type int
* @param y indicating the position of the pacdot
* @param_type int
* @param is_big indicating if the pacdot is big
* @param_type bool
* @return an instance of the pacdot class initialized with a reference to the Menu running instance, two values indicating the position of x,y axiss a value indicating if the pacdot is big
* @rtype Pacdot instance
*
**/
Pacdot::Pacdot(const Menu& ingame, int x, int y, bool is_big)
	:menu(ingame)
{
	modern = menu.getModern();
	pos.x = x;
	pos.y = y;
	big = is_big;
}

/**
* Destructor for the pacdot
*
* NAME: ~Pacdot
*
* @param none
* @return none
*
**/
Pacdot::~Pacdot()
{
}

/**
* Returns the collision space of the pacdot
*
* NAME: getCollisionHull
*
* @param none
* @return a disk shape indicating the disk area of collision of the pacdot
* @rtype disk
*
**/
Disk Pacdot::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	if (!big) disk.radius = 8.f;
	else disk.radius = 10.5f;
	return disk;
}