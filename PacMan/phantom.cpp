#include "phantom.h"

void Phantom::updateM()
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

void Phantom::draw()
{
}

void Phantom::init()
{

}

Phantom::Phantom(character c)
{
	enemy = c;
	init();
}

Phantom::~Phantom()
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
