/**
* FILE: phantom.h
* TITLE: phantom
*
* PURPOSE:
*
* This is the class for the phantoms of the pacman.
*
* CLASS:
* Phantom
*
*	FUNCTIONS:
*	
*	init
*		init function
*
*	drawPhantomC
*		drawing classic phantom
*
*	drawPhantomM
*		drawing modern phantom
*
*	updateLeftC
*		updating left classic
*
*	updateRightC
*		updating right classic
*
*	updateUpC
*		updating up classic
*
*	updateDownC
*		updating down clasic
*
*	updateLeftM
*		updating left modern
*
*	updateRightM
*		updating right modern
*
*	updateUpM
*		updating up modern
*
*	updateDownM
*		updating down modern
*
*	updateC
*		updating classic
*
*	updateM
*		updating modern
*
*	updateChaseM
*		updating modern chawse mode
*
*	updateChaseC
*		updating classic chase mode
*
*	updateMulti
*		updating multi
*
*	chase
*		chasing function
*
*	update
*		general update
*
*	draw
*		general draw
*
*	getCollisionHull
*		returning collision points
*
*	getCollidable
*		returning if phantom can die or not
*
*	setCollidable
*		changing if the phantom can die or not
*
*	setStart
*		setting start state of phantom
*
*	getStart
*		returning if phantom has started
*
*	setSpeed
*		setting phantom speed
*
* INCLUDED FILES:
*
* gameelement.h
* config.h
* graphics.h
* util.h
* obstacle.h
*
* @file phantom.h
**/

#pragma once

#include "gameelement.h"
#include "graphics.h"
#include "config.h"
#include "util.h"
#include "obstacle.h"

class Phantom : public GameElement, public CollidableD
{
	Position pos{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 - 90}; // position of the phantom
	rotation rot = LEFT1; // rotation of the phantom
	character phantom = BLINKY; // character
	Disk disk; // disk modeling the collision points
	double timer = 0, timer_2 = 0;  // two simple timers
	bool start = true, // checking if phantom has started
		 modern = true, // playing modern holder
		 multi = false, // indicating if we are playing multiplayer
		 collid = false,  // indicating if phantom can die or not
		 out = false; // indicating if phantom is out of the 
	float speed = 5.f; // phantom speed
	int dir = 1, // direction of phantom 
		counter = 0; // simple counter
	graphics::Brush brush; // brush
	void init() override; // init function
	void drawPhantomC(); // drawing classic phantom
	void drawPhantomM(); // drawing modern phantom
	void updateLeftC() override; // updating left classic
	void updateRightC() override; // updating right classic
	void updateUpC() override; // updating up classic
	void updateDownC() override; // updating down classic
	void updateLeftM() override; //updating left modern
	void updateRightM() override; // updating right modern
	void updateUpM() override; // updating up modern
	void updateDownM() override; // updating down modern
	void updateC() override; // updating classic
	void updateM() override; // updating modern
	void updateChaseM(); // updating chase modern mode
	void updateChaseC(); // updating chase classic mode
	void updateMulti(); // updating multi
	void chase(); // chase function
public:
	bool movement[4] = { true, true, true, true }; // left, right, top, down - indicating if movement is possible
	void update() override; // generla update
	void draw() override; // general draw
	Disk getCollisionHull() const override; // returning the colission pounts
	bool getCollidable() { return collid; }; // returning if phantom can die
	void setCollidable(bool c) { collid = c; }; // changing if phantom can die or not
	void setStart(bool s) { start = s; }; // setting start
	bool getStart() { return start; }; // getting start
	void setSpeed(double s) { speed = s; }; // setting phantom speed
	Phantom(const class Menu& ingame); // constructor
	Phantom(const class Menu& ingame, character charac); // constructor
	~Phantom(); // destructor
};