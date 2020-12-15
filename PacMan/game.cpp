#include "game.h"
#include "graphics.h"
#include "config.h"

void Game::update()
{
	if (!player_init && graphics::getGlobalTime() > 1000 )
	{
		player = new Player();
		player_init = true;
	}

	if (player)
	{
		player->update();
	}
}

void Game::draw()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "back.png";
	brush.outline_opacity = 0.0f;
	
	// draw background
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_WIDTH, brush);

	// draw player

	if (player) {
		player->draw();
	}
}

void Game::init()
{

}

Game::Game()
{

}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
