#pragma once

#include "gameobject.h"
#include "graphics.h"

class Enemy : public GameObject
{
	float pos_x, pos_y;
	float size;
	float rotation;
	float speed;
	graphics::Brush brush;

public:
	void update() override;
	void draw() override;
	void init() override;
	Enemy();
	~Enemy();
};
