#pragma once

#include "config.h"

#include "graphics.h"

#include "gameelement.h"
#include <iostream>
#include <random>


class PongBall : public CollidableD
{
	Position pos{ CANVAS_WIDTH / 2, rand() % (CANVAS_HEIGHT - 10 - 10) + 10.f };
	Disk disk;
	bool active = true;
	float dir = 1.f,
		  angleY = 1.f;
	graphics::Brush brush;
	const class Menu& menu;
public:
	float getX() { return pos.x; };
	float getY() { return pos.y; };
	float getDir() { return dir; };
	void update();
	void draw();
	void init();
	Disk getCollisionHull() const override;
	bool isActive() { return active; };
	void changeDirection() { dir = -dir; };
	void setAngle(const Rectangle* rectangle);
	PongBall(const class Menu& ingame);
	~PongBall();
};
