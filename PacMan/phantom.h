#pragma once

#include "gameelement.h"
#include "graphics.h"
#include "config.h"

class Phantom : public GameElement
{
	typedef enum {PINKY, BLINKY, INKY, CLYDE} character;
	Position pos{ CANVAS_WIDTH / 2 + 50, CANVAS_HEIGHT / 2 + 50 };
	rotation rot = LEFT1;
	character enemy;
	double timer = 0;
	bool modern = true,
		start = true; // Take it from game
	float speed = 10.f;
	graphics::Brush brush;
public:
	void update() override;
	void draw() override;
	void init() override;
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
	Phantom(character c);
	~Phantom();
};