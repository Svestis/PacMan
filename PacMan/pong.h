#pragma once

#include "config.h"

#include "graphics.h"

#include "gameelement.h"

class Pong
{
	Position pos{100, CANVAS_HEIGHT / 2 };
	bool ai;
	short int level = 1;
	float speed = 5.f;
	graphics::Brush brush;
	const class Menu& menu;
public:
	void update();
	void draw();
	void init();
	Pong(const class Menu& ingame, bool player_playing);
	~Pong();
};
