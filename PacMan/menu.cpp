#include "menu.h"
#include "graphics.h"
#include "config.h"

void Menu::update()
{
}

void Menu::draw()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + std::string(BACKGROUND_MENU);
	brush.outline_opacity = 0.0f;

	// draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, brush);
}

void Menu::init()
{
	graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICM), 1.0f, true, 4000);
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
