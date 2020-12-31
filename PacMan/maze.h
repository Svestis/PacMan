#pragma once

#include "graphics.h"
#include "config.h"

class Maze
{
	bool modern;
	graphics::Brush brush;
	unsigned short int canvas_width = CANVAS_WIDTH, canvas_height = CANVAS_HEIGHT, maze_width = 700, maze_height = 500;
protected:
	const class Menu& menu;
public:
	void draw();
	void update();
	void init();
	unsigned short int getHeight() { return maze_height; };
	unsigned short int getWidth() { return maze_width; };
	Maze(const class Menu& ingame);
	~Maze();
};