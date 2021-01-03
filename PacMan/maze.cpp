#include "maze.h"
#include "menu.h"
#include "util.h"
#include <iostream>

void Maze::draw()
{
	brush.outline_opacity = 0.f;
	brush.fill_opacity = 1.f;
	if (modern)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE1);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 45.f), maze_width, maze_height, brush);
		gridM();
	}
	else if (!modern)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE2);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 55.f), maze_width, maze_height, brush);
		gridC();
		
	}
}

void Maze::gridM()
{
	brush.texture = "";
	brush.outline_opacity = 0.f;
	brush.fill_opacity = .2f;
	for (int i = 0; i < 40; i++)
	{		
		graphics::drawRect(i * maze_width / 40 +260, canvas_height/2-30, 1, canvas_height/2+200, brush);
	}

	for (int i = 0; i < 40; i++)
	{
		graphics::drawRect(canvas_width/2, i * maze_height / 40 + 26, canvas_width / 2 + 150, 1, brush);
	}
}

/*Fine tunned maze
void Maze::gridM()
{
	brush.texture = "";
	brush.outline_opacity = 0.f;
	brush.fill_opacity = .2f;

	for (int i = 0; i < 20; i++)
	{
		if (i==4 || i==5)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 + 21, canvas_width / 2 + 150, 1, brush);
		}
		else if (i==6 || i ==7)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 + 5, canvas_width / 2 + 150, 1, brush);
		}
		else if (i==8 || i==9)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 -9, canvas_width / 2 + 150, 1, brush);
		}
		else if (i == 10 || i==11)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 - 25, canvas_width / 2 + 150, 1, brush);
		}
		else if (i == 12 || i == 13)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 - 40, canvas_width / 2 + 150, 1, brush);
		}
		else if (i == 14|| i == 15)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 - 56, canvas_width / 2 + 150, 1, brush);
		}
		else if (i == 16 || i == 17)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 - 70, canvas_width / 2 + 150, 1, brush);
		}
		else if (i == 18 || i == 19)
		{
			graphics::drawRect(canvas_width / 2, i * 31.25 - 88, canvas_width / 2 + 150, 1, brush);
		}
		else
		{
			graphics::drawRect(canvas_width / 2, i *31.25 + 37, canvas_width / 2 + 150, 1, brush);
		}
	}

	for (int i = 0; i < 16; i++)
	{
		if (i == 2 || i == 12)
		{
			graphics::drawRect(i * 45 + 269, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
		else if (i == 3 || i == 10 || i == 11 || i == 13)
		{
			graphics::drawRect(i * 45 + 262, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
		else if (i == 4)
		{
			graphics::drawRect(i * 45 + 265, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
		else if (i == 5 || i == 6 || i == 7)
		{
			graphics::drawRect(i * 45 + 273, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
		else if (i == 8 || i == 9)
		{
			graphics::drawRect(i * 45 + 256, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
		else if (i == 8 || i == 9)
		{
			graphics::drawRect(i * 45 + 380, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
		else if (i == 14 || i == 15)
		{
			graphics::drawRect(i * 45 + 253, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
		}
	}
}
*/

void Maze::gridC()
{
	brush.texture = "";
	brush.outline_opacity = 0.f;
	brush.fill_opacity = .2f;
	for (int i = 0; i < (int)(maze_width / 17 ); i++)
	{
		graphics::drawRect(i * maze_width / 40 + 250, canvas_height / 2 + 30, 1, canvas_height / 2 + 205, brush);
	}

	for (int i = 0; i < (int)(maze_height / 12); i++)
	{
		graphics::drawRect(canvas_width / 2, i * maze_height / 40 + 79, canvas_width / 2 + 150, 1, brush);
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
