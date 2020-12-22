#pragma once

#include "gameelement.h"
#include "config.h"
#include "graphics.h"

class PacMan : public GameElement
{
	rotation rot = CENTER;
	double timer = 0;
	bool modern = false,
		 start = true,
		 multi = false; // Take it from game
	Position pos{ CANVAS_WIDTH/2, CANVAS_HEIGHT/2 };
	float speed = 10.f;
	graphics::Brush brush;
public:
	void update() override;
	void draw() override;
	void init() override;
	void drawPacmanC();
	void drawPacmanM();
	void updateLeftC() override;
	void updateRightC() override;
	void updateUpC() override;
	void updateDownC() override;
	void updateLeftM() override;
	void updateRightM() override;
	void updateUpM() override;
	void updateDownM() override;
	void updateC() override;
	void updateM() override;
	void drawInitM() override;
	void drawInitC() override;
	void updateMulti();
	PacMan(const class Menu& ingame);
	~PacMan();
};