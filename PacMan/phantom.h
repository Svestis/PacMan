#pragma once

#include "gameelement.h"
#include "graphics.h"
#include "config.h"
#include "util.h"

class Phantom : public GameElement, public CollidableD
{
	Position pos{ CANVAS_WIDTH / 2 + 50, CANVAS_HEIGHT / 2 + 50 };
	rotation rot = LEFT1;
	character phantom;
	Disk disk;
	double timer = 0;
	bool start = true,
		 modern,
		multi, collid = true;
	float speed = 7.f;
	graphics::Brush brush;
public:
	void update() override;
	void draw() override;
	void init() override;
	void drawPhantomC();
	void drawPhantomM();
	Disk getCollisionHull() const override;
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
	void updateMulti();
	void drawInitM() override;
	void drawInitC() override;
	bool getCollidable() { return collid; };
	void setCollidable(bool c) { collid = c; };
	Phantom(const class Menu& ingame);
	~Phantom();
};