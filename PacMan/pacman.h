#pragma once

#include "gameelement.h"
#include "config.h"
#include "graphics.h"

class PacMan : public GameElement
{
	rotation rot = CENTER;
	double timer = 0;
	bool modern = true,
		 start = true; // Take it from game
	Position pos{ CANVAS_WIDTH/2, CANVAS_HEIGHT/2 };
	float speed = 10.f;
	graphics::Brush brush;
	void updateLeft();
	void updateRight();
	void updateUp();
	void updateDown();
	void drawInitM();
	void drawInitC();
	void drawPacmanC();
	void drawPacmanM();
public:
	void update() override;
	void draw() override;
	void init() override;
};