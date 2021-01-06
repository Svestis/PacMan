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
		if (start)
		{
			createPacDotM();
			createObstacle();
			start = false;
		}
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE1);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 45.f), maze_width, maze_height, brush);
		if (obstacles[0])
		{
			obstacles[0]->draw();
		}
		//gridM();
	}
	else if (!modern)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE2);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 55.f), maze_width, maze_height, brush);
		if (start)
		{
			createPacDotC();
			createObstacle();
			start = false;
		}
		//gridC();
	}
	for (auto i : pacdots)
	{
		i->draw();
	}

	for (auto i : obstacles)
	{
		i->draw();
	}
}

void Maze::createPacDotC()
{

}

void Maze::createObstacle()
{
	obstacles.push_back(new Obstacle(menu, 601, 256, 170, 61));

	obstacles.push_back(new Obstacle(menu, 602, 49, 23, 37));

	obstacles.push_back(new Obstacle(menu, 601, 326, 170, 15));

	obstacles.push_back(new Obstacle(menu, 601, 145, 22, 93));

	obstacles.push_back(new Obstacle(menu, 601, 420, 22, 110));

	for (int inc : {0, 485})
	{
		obstacles.push_back(new Obstacle(menu, 359 + inc, 83, 72, 31));

		for (int i : {0, 94, 141, 235, 330})
		{
			obstacles.push_back(new Obstacle(menu, 359 + inc, 138 + i, 72, 15));
		}
	}

	for (int inc : {0, 436})
	{
		for (int i : {0, 93, 187})
		{
			obstacles.push_back(new Obstacle(menu, 383 + inc, 209 + i, 24, 63));
		}
	}

	for (int inc : {0, 613})
	{
		for (int i : {0, 142, 235})
		{
			obstacles.push_back(new Obstacle(menu, 295 + inc, 185 + i, 55, 15));
		}
	}

	for (int inc : {0, 217})
	{
		obstacles.push_back(new Obstacle(menu, 493 + inc, 83, 96, 31));

		for (int i : {47, 235, 330})
		{
			obstacles.push_back(new Obstacle(menu, 493 + inc, 138 + i, 95, 15));
		}
	}

	for (int inc : {0, 291})
	{
		for (int i : {0, 283})
		{
			obstacles.push_back(new Obstacle(menu, 456 + inc, 162 + i, 22, 60));
		}

		obstacles.push_back(new Obstacle(menu, 456 + inc, 279, 22, 110));
	}

	for (int inc : {0, 283})
	{
		obstacles.push_back(new Obstacle(menu, 601, 138 + inc, 170, 15));
	}

}

void Maze::createPacDotM()
{
	for (int inc : {50, 115}) // first/ last row
	{
		for (int i = 330; i < 600; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}

		for (int i = 630; i < 900; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}
	

	for (int i = 330; i < 900; i += 30) // last row
	{
		pacdots.push_back(new Pacdot(menu, i, 490, false));
	}

	for (int i = 330; i < 900; i += 30) // 1 before last row
	{
		pacdots.push_back(new Pacdot(menu, i, 350, false));
	}

	for (int inc : {295, 907}) // first/last column
	{
		for (int i = 85; i < 155; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 210; i < 310; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 360; i < 410; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 360; i < 410; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 450; i < 480; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

	}

	pacdots.push_back(new Pacdot(menu, 420, 85, false));
	pacdots.push_back(new Pacdot(menu, 780, 85, false));

	for (int inc : {420, 780}) // second / one-before the end column
	{
		for (int i = 145; i < 330; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 375; i < 475; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}
	}

	for (int i = 555; i < 670; i += 30) // first row
	{
		pacdots.push_back(new Pacdot(menu, i, 85, false));
	}

	for (int inc : {160, 210, 303, 395, 443})
	{
		for (int i = 480; i < 600; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}

		for (int i = 630; i < 750; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}

		for (int i = 327; i < 387; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}

		for (int i = 850; i < 910; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}

	for (int inc : {185, 327, 420})
	{
		for (int i = 343; i < 1060; i+=520)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}

	for (int inc : {185, 373, 467})
	{
		for (int i = 560 ; i < 660; i += 83)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}

	for (int inc : {137, 240, 270, 325, 420})
	{
		for (int i = 495; i < 750; i += 210)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}

	for (int inc : {210, 395})
	{
		for (int i = 450; i < 760; i += 305)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}

	for (int inc : {160, 255, 443})
	{
		for (int i = 387; i < 860; i += 430)
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}

	for (int i = 325; i < 370; i += 30)
	{
		pacdots.push_back(new Pacdot(menu, i, 255, false));
	}

	for (int i = 850; i < 895; i += 30)
	{
		pacdots.push_back(new Pacdot(menu, i, 255, false));
	}

	pacdots.push_back(new Pacdot(menu, 295, 55, true));
	pacdots.push_back(new Pacdot(menu, 295, 485, true));
	pacdots.push_back(new Pacdot(menu, 907, 55, true));
	pacdots.push_back(new Pacdot(menu, 907, 485, true));
}

void Maze::gridM()
{
	brush.texture = "";
	brush.outline_opacity = 0.f;
	brush.fill_opacity = .2f;
	for (int i = 0; i < 40; i++)
	{
		graphics::drawRect(i * maze_width / 40 + 260, canvas_height / 2 - 30, 1, canvas_height / 2 + 200, brush);
	}

	for (int i = 0; i < 40; i++)
	{
		graphics::drawRect(canvas_width / 2, i * maze_height / 40 + 26, canvas_width / 2 + 150, 1, brush);
	}

}

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

void Maze::destroyDot(Pacdot* element)
{
	auto it = find(pacdots.begin(), pacdots.end(), element);
	int index = -1;
	if (it != pacdots.end())
	{
		index = it - pacdots.begin();
	}

	delete pacdots[index];
	(pacdots)[index] = NULL;
	(pacdots).erase(pacdots.begin() + index);
}

Maze::Maze(const Menu& ingame)
	:menu(ingame)
{
	modern = menu.getModern();
}

Maze::~Maze()
{
}
