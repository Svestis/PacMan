#pragma once

#include "player.h"
#include "enemy.h"

class Game
{
	Player *player = nullptr;
	bool player_init = false;
	Enemy* meteorite = NULL;
	void spawnMeteorite();
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();
};