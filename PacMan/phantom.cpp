#include "phantom.h"
#include "menu.h"

void Phantom::updateM()
{

}

void Phantom::updateMulti()
{
}

void Phantom::updateLeftM()
{
}

void Phantom::updateRightM()
{
}

void Phantom::updateUpM()
{
}

void Phantom::updateDownM()
{
}

void Phantom::updateC()
{
}

void Phantom::updateLeftC()
{
}

void Phantom::updateRightC()
{
}

void Phantom::updateUpC()
{
}

void Phantom::updateDownC()
{
}

void Phantom::drawInitM()
{
	if (enemy == BLINKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
	}
	else if (enemy == PINKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
	}
	else if (enemy == INKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
	}
	else if (enemy == CLYDE)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
	}
	start = false;
}

void Phantom::drawInitC()
{
	if (enemy == BLINKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
	}
	else if (enemy== PINKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
	}
	else if (enemy == INKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
	}
	else if (enemy == CLYDE)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
	}
	start = false;
}

void Phantom::update()
{
	if (start) drawInitC();

}

void Phantom::drawPhantomC()
{
	switch (enemy)
	{
	case(PINKY):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_2);
		}
	case(INKY):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_2);
		}
	case(BLINKY):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_2);
		}
	case(CLYDE):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_2);
		}
	}
	
}

void Phantom::drawPhantomM()
{
	switch (enemy)
	{
	case(PINKY):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_2);
		}
	case(INKY):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_2);
		}
	case(BLINKY):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_2);
		}
	case(CLYDE):
		if (rot == LEFT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_1);
		}
		else if (rot == LEFT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_2);
		}
		else if (rot == DOWN1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_1);
		}
		else if (rot == DOWN2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_2);
		}
		else if (rot == UP1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_UP_1);
		}
		else if (rot == UP2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_UP_2);
		}
		else if (rot == RIGHT1)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_1);
		}
		else if (rot == RIGHT2)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_2);
		}
	}
}


void Phantom::draw()
{
	brush.outline_opacity = 0.f;
	if (start && !modern)
	{
		drawInitC();
	}
	else if (!start && !modern)
	{
		drawPhantomC();
	}
	else if (start && modern)
	{
		drawInitM();
	}
	else if (!start && modern)
	{
		drawPhantomM();
	}

	graphics::drawRect(pos.x, pos.y, 30, 30, brush);
}

void Phantom::init()
{

}

Phantom::Phantom(character c, const Menu& ingame)
	: GameElement(ingame)
{
}

Phantom::~Phantom()
{
}