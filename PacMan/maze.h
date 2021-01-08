#pragma once

#include "graphics.h"
#include "config.h"
#include "pacdot.h"
#include "obstacle.h"
#include <vector>
#include <memory>

class Pacdot;
class Obstacle;

class Maze
{
	bool modern, start = true;
	graphics::Brush brush;
	unsigned short int canvas_width = CANVAS_WIDTH, canvas_height = CANVAS_HEIGHT, maze_width = 700, maze_height = 500;
	void gridM();
	void gridC();
	void createPacDotM();
	void createPacDotC();
	void createObstacleUpLeft();
	void createObstacleUpRight();
	void createObstacleDownLeft();
	void createObstacleDownRight();
	void init();
protected:
	const class Menu& menu;
public:
	void draw();
	void update();
	void destroyDot(Pacdot* element);
	void destroyObstacle(Obstacle* element, std::string side);
	unsigned short int getHeight() { return maze_height; };
	unsigned short int getWidth() { return maze_width; };
	std::vector<Pacdot*> pacdots;
	std::vector<Obstacle*> obstacles;
	std::vector<Obstacle*> obstaclesUpLeft;
	std::vector<Obstacle*> obstaclesUpRight;
	std::vector<Obstacle*> obstaclesDownLeft;
	std::vector<Obstacle*> obstaclesDownRight;
	bool getModern() const { return modern; };
	Maze(const class Menu& ingame);
	~Maze();
};