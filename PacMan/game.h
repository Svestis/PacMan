#pragma once

#include "player.h"
#include "enemy.h"

class Game
{
	Player *player = nullptr;
	bool player_init = false;
	Enemy *meteorite = nullptr;
	void spawnMeteorite();
	void checkMeteorite();
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();
};