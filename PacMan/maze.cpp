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
			createObstacleM();
			start = false;
		}
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE1);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 45.f), maze_width, maze_height, brush);
	}
	else if (!modern)
	{
		if (start)
		{
			createPacDotC();
			createObstacleC();
			start = false;
		}
		brush.texture = std::string(ASSET_PATH) + std::string(MAZE2);
		graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 55.f), maze_width, maze_height, brush);
	}

	for (auto i : pacdots)
	{
		i->draw();
	}
}

void Maze::createPacDotC()
{

	for (int inc : {103, 410}) // first/ last row
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

	for (int inc : {555, 170})
	{
		for (int i = 330; i < 900; i += 30) // last row
		{
			pacdots.push_back(new Pacdot(menu, i, inc, false));
		}
	}


	for (int inc : {285, 917}) // first/last column
	{
		for (int i = 139; i < 229; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 417; i < 461; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 515; i < 520; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

	}
	
	pacdots.push_back(new Pacdot(menu, 412, 135, false));
	pacdots.push_back(new Pacdot(menu, 787, 135, false));
	
	for (int inc : {412, 787}) // second / one-before the end column
	{
		for (int i = 197; i < 390; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}

		for (int i = 440; i < 501; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}
	}

	for (int inc : {485, 713})
	{
		for (int i = 280; i < 380; i += 30)
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}
	}

	for (int inc : {560, 640})
	{
		for (int i: { 135, 433, 530})
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}
	}

	for (int inc : {450, 600})
	{
		for (int i : {215, 507})
		{
			for (int j : {30, 60, 90, 120})
			{
				pacdots.push_back(new Pacdot(menu, inc + j, i, false));
			}
		}
	}

	for (int inc : {290, 790})
	{
		for (int i : {215, 507})
		{
			for (int j : {30, 60, 90})
			{
				pacdots.push_back(new Pacdot(menu, inc + j, i, false));
			}
		}
	}

	for (int inc : {560, 640})
	{
		pacdots.push_back(new Pacdot(menu, inc, 240, false));
	}

	for (int inc : {490, 710})
	{
		for (int i : {192, 480})
		{
			pacdots.push_back(new Pacdot(menu, inc, i, false));
		}
	}

	for (int inc : {450, 750})
	{
		pacdots.push_back(new Pacdot(menu, inc, 312, false));
	}

	for (int i = 435; i < 790; i += 30)
	{
		pacdots.push_back(new Pacdot(menu, i, 458, false));
	}

	for (int inc : {310, 860})
	{
		for (int i : {0, 30})
		{
			pacdots.push_back(new Pacdot(menu, inc + i, 456, false));
		}		
	}

	for (int inc : {305, 835})
	{
		pacdots.push_back(new Pacdot(menu, inc + 30, 482, false));
	}
	
	pacdots.push_back(new Pacdot(menu, 285, 105, true));
	pacdots.push_back(new Pacdot(menu, 285, 550, true));
	pacdots.push_back(new Pacdot(menu, 917, 105, true));
	pacdots.push_back(new Pacdot(menu, 917, 550, true));
}

void Maze::createObstacleC()
{
	obstacles.push_back(new Obstacle(menu, 601, 314, 176, 64));

	for (int i : {0, 193, 290})
	{
		obstacles.push_back(new Obstacle(menu, 600, 193+i, 173, 16));

		obstacles.push_back(new Obstacle(menu, 600, 218+i, 23, 63));
	}


	for (int i : {0, 242})
	{
		for (int j : {0, 500})
		{
			obstacles.push_back(new Obstacle(menu, 350+j, 193 + i, 73, 17));
		}
	}

	for (int i : {0, 450})
	{
		obstacles.push_back(new Obstacle(menu, 375+i, 460, 24, 63));
	}

	for (int i : {0, 638})
	{
		obstacles.push_back(new Obstacle(menu, 282 + i, 483, 59, 15));
	}

	for (int i : {0, 194})
	{
		for (int j: {487, 714})
		obstacles.push_back(new Obstacle(menu, j, 242 + i, 98, 17));
	}

	for (int i : {750, 449})
	{
		for (int j : {362, 508})
		{
			obstacles.push_back(new Obstacle(menu, i, j, 22, 62));
			
		}
		obstacles.push_back(new Obstacle(menu, i, 241, 22, 110));
	}

	for (int i : {776, 425})
	{
		obstacles.push_back(new Obstacle(menu, i, 532, 221, 17));
	}

	for (int inc : {850, 350})
	{
		obstacles.push_back(new Obstacle(menu, inc, 137, 73, 31));
	}

	for (int inc : {488, 712})
	{
		obstacles.push_back(new Obstacle(menu, inc, 137, 100, 31));
	}
}

void Maze::createObstacleM()
{
	obstacles.push_back(new Obstacle(menu, 601, 256, 170, 61));

	obstacles.push_back(new Obstacle(menu, 601, 326, 170, 15));

	obstacles.push_back(new Obstacle(menu, 601, 420, 22, 110));

	for (int i : {141, 235, 330})
	{
		obstacles.push_back(new Obstacle(menu, 844, 138 + i, 72, 15));
	}

	for (int i : {93, 187})
	{
		obstacles.push_back(new Obstacle(menu, 819, 209 + i, 24, 63));
	}

	for (int i : {142, 235})
	{
		obstacles.push_back(new Obstacle(menu, 908, 185 + i, 55, 15));
	}

	for (int i : {235, 330})
	{
		obstacles.push_back(new Obstacle(menu, 710, 138 + i, 95, 15));
	}

	obstacles.push_back(new Obstacle(menu, 747, 445, 22, 60));

	obstacles.push_back(new Obstacle(menu, 747, 279, 22, 110));

	obstacles.push_back(new Obstacle(menu, 601, 421, 170, 15));

	for (int i : {141, 235, 330})
	{
		obstacles.push_back(new Obstacle(menu, 359, 138 + i, 72, 15));
	}

	for (int i : {93, 187})
	{
		obstacles.push_back(new Obstacle(menu, 383, 209 + i, 24, 63));
	}

	for (int i : {142, 235})
	{
		obstacles.push_back(new Obstacle(menu, 295, 185 + i, 55, 15));
	}

	for (int i : {235, 330})
	{
		obstacles.push_back(new Obstacle(menu, 493, 138 + i, 95, 15));
	}

	obstacles.push_back(new Obstacle(menu, 456, 445, 22, 60));

	obstacles.push_back(new Obstacle(menu, 456, 279, 22, 110));

	obstacles.push_back(new Obstacle(menu, 602, 49, 23, 37));

	obstacles.push_back(new Obstacle(menu, 601, 145, 22, 93));

	obstacles.push_back(new Obstacle(menu, 844, 83, 72, 31));

	for (int i : {0, 94})
	{
		obstacles.push_back(new Obstacle(menu, 844, 138 + i, 72, 15));
	}

	obstacles.push_back(new Obstacle(menu, 747, 162, 22, 60));

	obstacles.push_back(new Obstacle(menu, 710, 83, 96, 31));

	obstacles.push_back(new Obstacle(menu, 710, 185, 95, 15));

	obstacles.push_back(new Obstacle(menu, 819, 209, 24, 63));

	obstacles.push_back(new Obstacle(menu, 908, 185, 55, 15));

	obstacles.push_back(new Obstacle(menu, 601, 138, 170, 15));

	obstacles.push_back(new Obstacle(menu, 359, 83, 72, 31));

	for (int i : {0, 94})
	{
		obstacles.push_back(new Obstacle(menu, 359, 138 + i, 72, 15));
	}

	obstacles.push_back(new Obstacle(menu, 383, 209, 24, 63));

	obstacles.push_back(new Obstacle(menu, 295, 185, 55, 15));

	obstacles.push_back(new Obstacle(menu, 493, 83, 96, 31));

	obstacles.push_back(new Obstacle(menu, 493, 185, 95, 15));

	obstacles.push_back(new Obstacle(menu, 456, 162, 22, 60));
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
	for (auto element : pacdots)
	{
		delete element;
	}
	pacdots.clear();

	for (auto element : obstacles)
	{
		delete element;
	}
	obstacles.clear();
}
