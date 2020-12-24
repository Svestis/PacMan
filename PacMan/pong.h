#pragma once

#include "config.h"

#include "graphics.h"

#include "gameelement.h"
#include "pongball.h"

class Pong: public CollidableR
{
	Position pos{100, CANVAS_HEIGHT / 2 };
	Rectangle rectangle;
	bool ai;
	float speed = 5.f;
	float move = 0.f;
	graphics::Brush brush;
	const class Menu& menu;
public:
	void update();
	void draw();
	void init();
	Rectangle getCollisionHull() const override;
	Pong(const class Menu& ingame, bool player_playing);
	~Pong();
};
