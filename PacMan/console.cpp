#include "console.h"

void Console::createMenu()
{
	//if (!menu) menu = new Menu(*this);
}

void Console::createPacManSigle()
{
}

void Console::createPacManMulti()
{
}

void Console::createPong()
{
}

void Console::update()
{
	createMenu();
	if (menu)
	{
		menu->update();
	}
}

void Console::draw()
{
	if (menu)
	{
		menu->draw();
	}
}

void Console::init()
{
}

Console::Console()
{
}

Console::~Console()
{
	
	if (menu)
	{
		delete menu;
	}
	graphics::destroyWindow();
}
