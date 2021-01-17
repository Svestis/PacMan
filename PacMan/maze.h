/**
* FILE: maze.h
* TITLE: maze
*
* PURPOSE:
*
* This is the class for the maze of the pacman. It contains multiple elements such as the obstacles that pacman/ghosts collid on and the pacdots
*
* CLASS:
* Maze
*
*	FUNCTIONS:
*
*	createPacDotM
*		creating the Pacdots on the modern maze
*
*	createPacDotC
*		creating the Pacdots on the classic maze
*
*	createObstacleM
*		modeling the obstacles on the modern maze
*
*	createObstacleC
*		modeling the obstacles on the classic maze
*
*	draw
*		drawing the maze
*
*	destroyDot
*		destroying single dots (eating)
*
*	getModern
*		returning the value of the modern variable, indicating if we are playing modern or classic
*
*	getHeight
*		returning the height of the maze
*
*	getWidth
*		returning the width of the maze
*
* INCLUDED FILES:
*
* graphics.h
* config.h
* pacdot.h
* obstacle.h
* vector
*
* @file maze.h
**/

#pragma once

#include "graphics.h"
#include "config.h"
#include "pacdot.h"
#include "obstacle.h"
#include <vector>

class Pacdot;
class Obstacle;

class Maze
{
	bool modern, // bool for holding the game type, modern or not
		 start = true; // bool for holding if the game has start or not
	graphics::Brush brush; // brush for drawing
	unsigned short int canvas_width = CANVAS_WIDTH, canvas_height = CANVAS_HEIGHT, maze_width = 700, maze_height = 500; // maze position
	void createPacDotM(); // creating Pacdots on Modern mode
	void createPacDotC(); // creating Pacdots on Classic mode
	void createObstacleM(); // creating Obstacles on modern mode
	void createObstacleC(); // creating Obstacles on Classic Mode
protected:
	const class Menu& menu; // variable holding the instance of the running menu
public:
	std::vector<Pacdot*> pacdots; // vector of pointers for the pacdots
	std::vector<Obstacle*> obstacles; // vector of pointers for the obstacles
	void draw(); // draw function
	void destroyDot(Pacdot* element); // destroying (eating) single pacdots
	bool getModern() const { return modern; }; // return the game mode (modern or not)
	unsigned short int getHeight() { return maze_height; }; // returning the maze height
	unsigned short int getWidth() { return maze_width; }; // return the maze width
	Maze(const class Menu& ingame); // constructor
	~Maze(); // destructor
};