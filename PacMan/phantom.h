#pragma once

#include "gameelement.h"
#include "graphics.h"
#include "config.h"
#include "util.h"

class Phantom : public GameElement, public CollidableD
{
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2};
	rotation rot = LEFT1;
	character phantom;
	Disk disk;
	double timer = 0;
	bool start = true,
		 modern,
		multi, collid = false;
	float speed = 5.f;
	graphics::Brush brush;
public:
	bool movement[4] = { true, true, true, true }; // left, right, top, down
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