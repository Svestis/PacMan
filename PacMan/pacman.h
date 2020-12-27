#pragma once

#include "gameelement.h"
#include "config.h"
#include "graphics.h"

class PacMan : public GameElement, public CollidableD
{
	rotation rot = CENTER;
	Disk disk;
	double timer = 0;
	bool start = true;
	Position pos{ CANVAS_WIDTH/2, CANVAS_HEIGHT/2 };
	float speed = 7.f;
	graphics::Brush brush;
public:
	void update() override;
	void draw() override;
	void init() override;
	void drawDeath();
	void drawPacmanC(); // Spawn
	void drawPacmanM(); // Spawn
	Disk getCollisionHull() const override;
	void updateLeftC() override; // Move left
	void updateRightC() override; // Move right
	void updateUpC() override; // Move Up
	void updateDownC() override; // Move down
	void updateLeftM() override; // Move left
	void updateRightM() override; // Move right
	void updateUpM() override; // Move up
	void updateDownM() override; //Move down
	void updateC() override; // Moving
	void updateM() override; // Moving
	void drawInitM() override; // Init
	void drawInitC() override; // Init
	void updateMulti();
	PacMan(const class Menu& ingame);
	~PacMan();
};