#include "obstacle.h"

Rectangle Obstacle::getCollisionHull() const
{
	Rectangle rect;
	rect.cx = pos.x;
	rect.cy = pos.y;
	rect.w = w_h.x;
	rect.h = w_h.y;
	return rect;
}

Obstacle::Obstacle(const Menu& ingame, int x, int y, int w, int h)
	:menu(ingame)
{
	pos.x = x;
	pos.y = y;
	w_h.x = w;
	w_h.y = h;
}

Obstacle::~Obstacle()
{
}
