#pragma once
#include "gameobject.h"
#include "config.h"

class Player : public GameObject
{
	float speed = 10.0f;
	float pos_x = CANVAS_HEIGHT/2, pos_y = CANVAS_HEIGHT/2;
public:
	void update() override;
	void draw() override;
	void init() override;
};