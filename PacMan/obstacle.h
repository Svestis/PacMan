#pragma once

#include "config.h"
#include "graphics.h"
#include "maze.h"
#include "gameelement.h"

class Obstacle : public CollidableR
{
	graphics::Brush brush;
	Rectangle rect;
	Position pos, w_h;
	void init();
protected:
	const class Menu& menu;
public:
	void draw();
	void update();
	Rectangle getCollisionHull() const;
	Obstacle(const class Menu& ingame, int x, int y, int w, int h);
	~Obstacle();
};