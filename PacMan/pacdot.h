#pragma once

#include "config.h"
#include "graphics.h"
#include "maze.h"
#include "gameelement.h"

class Pacdot: public CollidableD
{
	graphics::Brush brush;
	Disk disk;
	Position pos;
	bool modern, big;
	void init();
protected:
	const class Menu& menu;
public:
	void update();
	void draw();
	bool getBig() { return big; };
	Disk getCollisionHull() const;
	Pacdot(const class Menu& ingame, int x, int y, bool is_big);
	~Pacdot();
};