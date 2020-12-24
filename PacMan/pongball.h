#pragma once

#include "config.h"

#include "graphics.h"

#include "gameelement.h"
#include <iostream>


class PongBall : public CollidableD
{
	Disk disk;
	float speed = 5.f;
	short int level = 1;
	bool active = true;
	float dir = 1.f;
	float angleY = 0.f;
	graphics::Brush brush;
	const class Menu& menu;
public:
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 };
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
