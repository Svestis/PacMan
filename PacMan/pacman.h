/**
* FILE: pacman.h
* TITLE: pacman 
*
* PURPOSE:
*
* This is the class for the pacman.
*
* CLASS:
* Pacman
*
*	FUNCTIONS:
*
*	 init
*		general init function
*
*	 drawPacmanC
*		drawing pacman in classig game mode
*
*	 drawPacmanM
*		drawing pacman in modern game mode
*
*	 updateLeftC
*		updating left movement classic
*
*	updateRightC
*		updating right movement classic
*
*	 updateUpC
*		updating up movmeent classic
*
*	 updateDownC
*		updating down movement classic
*
*	 updateLeftM
*		updating left movement modern
*
*	 updateRightM
*		updating right movement modern
*
*	 updateUpM
*		updating up movement modern
*
*	 updateDownM
*		updating down movement modern
*
*	 updateC
*		general update for classic
*
*	 updateM
*		general update for modern
*
*	 drawInitM
*		init for modern ame
*
*	 drawInitC
*		init for classic game
*
*	 updateMulti
*		updating for multiplayer
*
*	 update
*		general update
*
*	 draw
*		general draw
*
*	 getCollisionHull
*		returning collision area
*
*	 getCollidable
*		returning bool on if the pacman can die
*
*	 setCollidable
*		changing the value to set if pacman can die or not
*
*	 setSpeed
*		setting pacman speed
*
*	 getPosition
*		getting pacman position
*
* INCLUDED FILES:
*
* gameelement.h
* config.h
* graphics.h
*
* @file pacman.h
**/

#pragma once

#include "gameelement.h"
#include "config.h"
#include "graphics.h"

class PacMan : public GameElement, public CollidableD
{
	rotation rot = CENTER; // pacman rotation
	direction dir = LEFT; // pacman direction
	Disk disk; // disk for the collision area
	double timer = 0; // a simple timer
	float speed = 5.f, // pacman speed
		  moveUp, // indicating if can move up
		  moveDown, // indicating if can move down
		  moveLeft, // indicating if can move left
		  moveRight; // indicating if can move right
	bool start = true, // indicating if pacman started
		 modern = true,  // indicating if we are playing modern game
		 multi = false, // indicating if we are playing multiplayer game
		 collid = true; // indicating if pacman can die
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 }; // pacman possition
	graphics::Brush brush; // a simple brush
	void init() override; // init function
	void drawPacmanC(); // Spawn
	void drawPacmanM(); // Spawn
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
	void updateMulti(); // multiplayer gameplay
public:
	void update() override; // update function
	void draw() override; // draw function
	Disk getCollisionHull() const override; // collsion area
	bool getCollidable() { return collid; }; // returning if pacman can die
	void setCollidable(bool c) { collid = c; };	 // chaning the collid variable
	void setSpeed(float s) { speed = s; }; // changing pacman speed
 	Position getPosition() { return pos; }; // returning pacman position
	bool movement[4] = { true, true, true, true }; // left, right, top, down, indicating if movement is possible
	PacMan(const class Menu& ingame); // constructor
	~PacMan(); // destructor
};