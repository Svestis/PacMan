#pragma once

#include "gameelement.h"
#include "graphics.h"
#include "config.h"
#include "util.h"
#include "obstacle.h"

class Phantom : public GameElement, public CollidableD
{
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 - 90};
	rotation rot = LEFT1;
	character phantom;
	Disk disk;
	int b_f = 0, u_d = 0;
	double timer = 0, timer_2 = 0;
	bool start = true,
		 modern,
		multi, init_ = true, collid = false, out = false;
	float speed = 5.f;
	int dir = 1, counter = 0;
	graphics::Brush brush;
	void init() override;
	void drawPhantomC();
	void drawPhantomM();
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
	void updateChaseM();
	void updateMulti();
	void updateStartM();
	void chase();
public:
	bool movement[4] = { true, true, true, true }; // left, right, top, down
	void update() override;
	void draw() override;
	Disk getCollisionHull() const override;
	void drawInitM() override;
	void drawInitC() override;
	bool getCollidable() { return collid; };
	void setCollidable(bool c) { collid = c; };
	void setStart(bool s) { start = s; };
	bool getStart() { return start; };
	void setSpeed(double s) { speed = s; };
	Phantom(const class Menu& ingame);
	Phantom(const class Menu& ingame, character charac);
	~Phantom();
};