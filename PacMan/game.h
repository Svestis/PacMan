#pragma once

#include "player.h"
#include "enemy.h"

class Game
{
	typedef enum { STATUS_START, STATUS_PLAYING} status_t;
	Player *player = nullptr;
	bool player_init = false;
	Enemy *meteorite = nullptr;
	void spawnMeteorite();
	void checkMeteorite();
	bool checkCollision();
	status_t status = STATUS_START;
	void updateStartScreen();
	void updateLevelScreen();
	void drawStartScreen();
	void drawLevelScreen();
	unsigned int window_width = WINDOW_WIDTH, window_height = WINDOW_HEIGHT;
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();
	unsigned int getWindowWidth() { return window_width; };
	unsigned int getWindowHeight() { return window_height; };
	void setWWindowDimensions(unsigned int w, unsigned int h) { window_width = w; window_height = h; }
	float window2canvasY(float x);
	float windows2canvasX(float y);
};