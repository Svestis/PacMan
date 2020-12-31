#include "maze.h"
#include "menu.h"
#include "util.h"
#include <iostream>

void Maze::draw()
{
	brush.outline_opacity = 0.f;

	if (modern)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE1);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 45.f), maze_width, maze_height, brush);
	}
	else if (!modern)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE2);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 55.f), maze_width, maze_height, brush);
		std::cout << modern << std::endl;
	}
}

void Maze::update()
{
	
}

void Maze::init()
{
}

Maze::Maze(const Menu& ingame)
	:menu(ingame)
{
	modern = menu.getModern();
}

Maze::~Maze()
{
}
