#include "obstacle.h"

void Obstacle::init()
{
}

void Obstacle::draw()
{
	graphics::Brush br;
	brush.outline_opacity = 0.f;
	br.fill_color[0] = 0.5f;
	br.fill_color[1] = 1.f;
	br.fill_color[2] = 0.f;
	br.fill_opacity = 0.3f;
	br.outline_opacity = 0.f;
	br.gradient = false;
	rect = getCollisionHull();
	graphics::drawRect(rect.cx, rect.cy, rect.w, rect.h, br);
}

void Obstacle::update()
{
}

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
