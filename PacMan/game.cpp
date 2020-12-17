#include "game.h"
#include "graphics.h"
#include "config.h"

void Game::spawnMeteorite()
{
	if (!meteorite) 
	{
		meteorite = new Enemy(*this);
	}
	
}

void Game::checkMeteorite()
{
	if (meteorite && !meteorite->isActive())
	{
		delete meteorite;
		meteorite = nullptr;
	}
}

void Game::update()
{
	if (!player_init && graphics::getGlobalTime() > 1000 )
	{
		player = new Player(*this);
		player_init = true;
	}

	if (player) player->update();

	checkMeteorite();
	spawnMeteorite();

	if (meteorite) meteorite->update();
}

void Game::draw()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "back.png";
	brush.outline_opacity = 0.0f;
	
	// draw background
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_WIDTH, brush);

	// draw player

	if (player) player->draw();

	if (player)
	{
		char info[40];
		sprintf_s(info, "(%6.2f, %6.2f)", player->getPosX(), player->getPosY());
		graphics::drawText(30, 30, 20, info, brush);
	}


	if (meteorite) meteorite->draw();
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + std::string(FONT));
	graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICM), 1.0f, true, 4000);
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

	if (meteorite)
	{
		delete meteorite;
	}
}
