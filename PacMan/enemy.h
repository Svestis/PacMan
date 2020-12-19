#pragma once

#include "gameobject.h"
#include "graphics.h"

class Enemy : public GameObject, public Collidable
{
	float pos_x, pos_y;
	float size;
	float rotation;
	float speed;
	bool active = true;
	graphics::Brush brush;
public:

	void update() override;
	void draw() override;
	void init() override;
	bool isActive() { return active; };
	Enemy(const class Game& game);
	~Enemy();
	Disk getCollisionHull() const override;
};
