#pragma once

#include "config.h"

#include "graphics.h"

#include "gameelement.h"
#include "pongball.h"
#include <random>

class Pong: public CollidableR
{
	Position pos{100, CANVAS_HEIGHT / 2 };
	Rectangle rectangle;
	bool ai;
	float move = 0.f,
		time_counter = 0.f;
	int error = std::rand() % (5 + 1) ;
	graphics::Brush brush;
	const class Menu& menu;
public:
	void update();
	void draw();
	void init();
	Rectangle getCollisionHull() const override;
	Pong(const class Menu& ingame, bool is_ai);
	~Pong();
};
