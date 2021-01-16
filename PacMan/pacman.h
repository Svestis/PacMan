#pragma once

#include "gameelement.h"
#include "config.h"
#include "graphics.h"
#include <tuple>

class PacMan : public GameElement, public CollidableD
{
	rotation rot = CENTER;
	direction dir = LEFT;
	bool moveUp = true, moveDown = true, moveLeft = true, moveRight = true;
	Disk disk;
	double timer = 0;
	bool start = true,
		modern, multi, collid = true;
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 };
	std::tuple <unsigned short int, unsigned short int> pos_grid;
	float speed = 5.f;
	graphics::Brush brush;
public:
	void update() override;
	void draw() override;
	void init() override;
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
	void drawInitM(); // Init
	void drawInitC(); // Init
	void updateMulti();
	bool getCollidable() { return collid; };
	void setCollidable(bool c) { collid = c; };	
	void setSpeed(float s) { speed = s; };
 	Position getPosition() { return pos; };
	bool movement[4] = { true, true, true, true }; // left, right, top, down
	PacMan(const class Menu& ingame);
	~PacMan();
};