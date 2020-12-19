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

bool Game::checkCollision()
{
	if (!player || !meteorite)
	{
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = meteorite->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->drainLife(0.1f);
		return true;
	}
	else
		return false;
}

void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
		status = STATUS_PLAYING;
	}
}

void Game::updateLevelScreen()
{
}

void Game::drawStartScreen()
{
	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Press enter to start");
	graphics::drawText(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 30, info, br);

	graphics::MouseState ms;

	graphics::getMouseState(ms);

	graphics::drawDisk(windows2canvasX(ms.cur_pos_x), window2canvasY(ms.cur_pos_y), 10, br);
}

void Game::drawLevelScreen()
{

	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "back1.png";
	brush.outline_opacity = 0.0f;

	// draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, brush);

	// draw player

	if (player) player->draw();

	if (player)
	{
		char info[40];
		sprintf_s(info, "(%6.2f, %6.2f)", player->getPosX(), player->getPosY());
		graphics::drawText(30, 30, 20, info, brush);
	}


	if (meteorite) meteorite->draw();

	float player_life = player ? player->getRemainingLife() : 0.0f;

	brush.outline_opacity = 1.0f;
	brush.fill_color[0] = 1.0f;
	brush.fill_color[1] = 0.0f;
	brush.fill_color[2] = 0.0f;
	brush.texture = "";
	brush.fill_secondary_color[0] = 1.0f * (1 - player_life) + player_life * 0.2f;
	brush.fill_secondary_color[1] = 0.2f;
	brush.fill_secondary_color[2] = 0.2f * (1 - player_life) + player_life * 1.0f;
	brush.gradient = true;
	brush.gradient_dir_u = 1.0f;
	brush.gradient_dir_v = 0.f;

	graphics::drawRect(CANVAS_WIDTH - 100 - (1.0f - player_life) * 120 / 2, 30, player_life * 120, 20, brush);
	brush.outline_opacity = 1.f;
	brush.gradient = false;
	brush.fill_opacity = 0.f;
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, brush);
}

void Game::update()
{
	if (status == STATUS_START) {
		updateStartScreen();
	}
	else
	{
		updateLevelScreen();
	}

	if (!player_init && graphics::getGlobalTime() > 1000 )
	{
		player = new Player(*this);
		player_init = true;
	}

	if (player) player->update();

	checkMeteorite();
	spawnMeteorite();

	if (meteorite) meteorite->update();

	if (checkCollision())
	{
		delete meteorite;
		meteorite = nullptr;
	}
}

void Game::draw()
{
	if (status == STATUS_START) {
		drawStartScreen();
	}
	else drawLevelScreen();
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + std::string(FONTM));
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

float Game::window2canvasY(float y)
{
	return y * CANVAS_HEIGHT / (float)window_height;
}

float Game::windows2canvasX(float x)
{
	return x * CANVAS_WIDTH / (float) window_width;
}
