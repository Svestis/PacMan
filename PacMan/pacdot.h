#pragma once

#include "gameelement.h"
#include "config.h"

class Pacdot : public GameElement
{
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 };
	void update() override;
	void draw() override;
	void init() override;
};