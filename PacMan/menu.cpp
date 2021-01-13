#include "menu.h"
#include "graphics.h"
#include "config.h"
#include <iostream>
#include "util.h"
#include <fstream>
#include <iostream>
#include <algorithm>


void Menu::updateY()
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		paused = false;
		lost = false;
		replay = false;
		hover[5] = 1.f;
	}
	else hover[5] = 1.2f;
}

void Menu::updateM()
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		music_on = !music_on;
		music_on_holder = music_on;
		updateMusic(modern);
	}
	else hover[2] = 1.2f;
}

void Menu::updateP()
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		hover[13] = 1.f;
		paused = !paused;
	}
	else hover[13] = 1.3f;
}

void Menu::updateS()
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)	sound_on = !sound_on; //TODO: Add function to turn sound on off
	else hover[3] = 1.3f;
}

void Menu::updateN(status s)
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		if (paused) paused = !paused;
		score_pong = 0;
		local_score = 0;
		if(score > pacman_local_score) pacman_local_score = score;
		score = 0;
		level = 1;
		lost = false;
		local_level = 1;
		time_counter = 0;
		pong_speed = 5.f;
		current_status = s;
		if (!music_on)
		{
			music_on = music_on_holder;
			updateMusic(modern);
		}
		hover[6] = 1.f;
 	}
	else hover[6] = 1.2f;
}

void Menu::updateB(status s)
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		if (paused) paused = !paused;
		if (maze)
		{
			delete maze;
			maze = nullptr;
		}
		if (pacman)
		{
			delete pacman;
			pacman = nullptr;
		}

		for (int i = 0; i < 4; i++)
		{
			if (enemies[i])
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}

		score_pong = 0;
		local_score = 0;
		player_score = 0;
		phantom_score = 0;
		if (score > pacman_local_score) pacman_local_score = score;
		score = 0;
		level = 1;
		lost = false;
		paused = false;
		local_level = 1;
		time_counter = 0;
		pong_speed = 5.f;
		current_status = s;
		obst_counter = 0;
		obst_counter_2 = 0;
		obst_counter_3 = 0;
		obst_counter_4 = 0;
		obst_counter_5 = 0;
		pacman_level = 1;
		pacman_speed = 5.f;
		phantom_speed = 4.f;
		if (!music_on)
		{
			music_on = music_on_holder;
			updateMusic(modern);
		}
	}
	else hover[4] = 1.3f;
}

void Menu::updateX()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)	delete this;
	else hover[0] = 1.2f;
}

void Menu::updateI()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	if (mouse.button_left_released) system(std::string(WEBPAGE).c_str());
	else hover[1] = 1.2f;
}

void Menu::updateFullScreen()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		full_screen = !full_screen;
		graphics::setFullScreen(full_screen);
	}
	else hover[8] = 1.2f;
}

void Menu::updateClassicScreen()
{
	// Closing windw on escape
	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE)) delete this; //TODO: Check this
	// Music on/off
	else if (graphics::getKeyState(graphics::SCANCODE_M) && !key_down)
	{
		key_down = true;
		music_on = !music_on;
		music_on_holder = music_on;
		updateMusic(modern);
	}
	// Sound on/off
	else if (graphics::getKeyState(graphics::SCANCODE_N) && !key_down)
	{
		key_down = true;
		sound_on = !sound_on; //TODO: Add function to turn sound on off
	}
	// Back to classics
	else if (graphics::getKeyState(graphics::SCANCODE_LSHIFT))
	{
		modern = true;
		updateMusic(modern);
	}
	// Single player
	else if (graphics::getKeyState(graphics::SCANCODE_RETURN) && !key_down)
	{
		key_down = true;
		current_status = STATUS_PLAYINGC;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RSHIFT) && !key_down)
	{
		key_down = true;
		full_screen = !full_screen;
		graphics::setFullScreen(full_screen);
	}
	else if (!graphics::getKeyState(graphics::SCANCODE_RETURN) && !graphics::getKeyState(graphics::SCANCODE_M) && !graphics::getKeyState(graphics::SCANCODE_N) && !graphics::getKeyState(graphics::SCANCODE_RSHIFT)) key_down = false;
}

void Menu::updateModernWelcome()
{
	graphics::getMouseState(mouse);
	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43)) updateX();

	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))	updateFullScreen();

	else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30 + 20)) updateB(STATUS_START);

	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5)) updateM();

	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5)) updateS();

	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH / 2 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH / 2 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 + 110 - 10) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 110 + 50))
	{
		if (mouse.button_left_released)
		{
			graphics::stopMusic(1000);
			music_on_holder = music_on;
			music_on = false;
			current_status = STATUS_PLAYINGCGAME;
		}
		else hover[6] = 1.1f;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_RETURN) && !key_down))
	{
		graphics::stopMusic(1000);
		music_on_holder = music_on;
		music_on = false;
		key_down = true;
		current_status = STATUS_PLAYINGCGAME;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))	delete this; // TODO: check this one

	else if (!key_down) // TODO: SECOND PRIORITY add more info button
	{
		hover[0] = 1.f;
		hover[8] = 1.f;
		hover[4] = 1.f;
		hover[2] = 1.f;
		hover[6] = 1.f;
		hover[3] = 1.f;
	}
	else if (!graphics::getKeyState(graphics::SCANCODE_RETURN) && key_down)	key_down = false;
}

void Menu::updateModernScreen()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43)) updateX();

	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 14) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 53 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 25 + 5)) updateI();

	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5)) updateM();

	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5)) updateS();

	else if ((window2CanvasX(mouse.cur_pos_x) >= 700 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		if (mouse.button_left_released)
		{
			modern = false;
			updateMusic(modern);
		}
		else hover[4] = 1.3f;
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 300 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		if (mouse.button_left_released)	current_status = STATUS_PLAYINGB;
		else hover[5] = 1.1f;
	}
	// Single player
	else if ((window2CanvasX(mouse.cur_pos_x) >= 300 - 120) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15))
	{
		if (mouse.button_left_released)
		{
			current_status = STATUS_PLAYINGC;
			hover[6] = 1.f;
		}
		else hover[6] = 1.1f;
	}
	// Multi player
	else if (window2CanvasX(mouse.cur_pos_x) >= 580 &&
		window2CanvasX(mouse.cur_pos_x) <= 815 && window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58 && window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15)
	{
		if (mouse.button_left_released)	current_status = STATUS_PLAYINGM;
		else hover[7] = 1.1f;
	}
	// full screen
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20)) updateFullScreen();
	else
	{
		hover[0] = 1.f;
		hover[1] = 1.f;
		hover[2] = 1.f;
		hover[3] = 1.f;
		hover[4] = 1.2f;
		hover[5] = 1.f;
		hover[7] = 1.f;
		hover[6] = 1.f;
		hover[8] = 1.f;
	}
}

// General menu screen update function
void Menu::updateMenuScreen()
{
	if (modern)	updateModernScreen();
	else updateClassicScreen();
}

void Menu::updateClassicWelcome()
{
	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE)) delete this;
	else if (graphics::getKeyState(graphics::SCANCODE_RETURN) && !key_down)
	{
		key_down = true;
		current_status = STATUS_PLAYINGC2;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_B) && !key_down)
	{
		if (paused) !paused;
		key_down = true;
		current_status = STATUS_START;
	}
	// Music on/off
	else if (graphics::getKeyState(graphics::SCANCODE_M) && !key_down)
	{
		key_down = true;
		music_on = !music_on;
		music_on_holder = music_on;
		updateMusic(modern);
	}
	// Sound on/off
	else if (graphics::getKeyState(graphics::SCANCODE_N) && !key_down)
	{
		key_down = true;
		sound_on = !sound_on; //TODO: Add function to turn sound on off
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RSHIFT) && !key_down)
	{
		key_down = true;
		full_screen = !full_screen;
		graphics::setFullScreen(full_screen);
	}
	else if (!graphics::getKeyState(graphics::SCANCODE_RETURN) && !graphics::getKeyState(graphics::SCANCODE_B) && !graphics::getKeyState(graphics::SCANCODE_M) && !graphics::getKeyState(graphics::SCANCODE_N) && !graphics::getKeyState(graphics::SCANCODE_RSHIFT))
	{
		key_down = false;
	}
}

void Menu::updateClassicGame()
{
	if (modern)
	{
		graphics::getMouseState(mouse);
		// Closing windw on close window click
		if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
			(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
		{
			updateX();
		}
		else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
		{
			updateFullScreen();
		}
		else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30 + 20))
		{
			updateB(STATUS_START);
		}
		// Music on/off
		else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
			(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
		{
			updateM();
		}
		// Sound on/off
		else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
			(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
		{
			updateS();
		}
		else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
		{
			delete this; // TODO: check this one
		}
		else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 40 - 20) &&
			(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 20) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 40 - 15) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 15))
		{
			if (!lost)
			{
				updateP();
			}
		}
		else if ((window2CanvasX(mouse.cur_pos_x) >= 128) &&
			(window2CanvasX(mouse.cur_pos_x) <= 372) && (window2CanvasY(mouse.cur_pos_y) >= 259) && (window2CanvasY(mouse.cur_pos_y) <= 391) && lost)
		{
			updateY();
		}
		else if ((window2CanvasX(mouse.cur_pos_x) >= 128 + 500) &&
			(window2CanvasX(mouse.cur_pos_x) <= 372 + 500) && (window2CanvasY(mouse.cur_pos_y) >= 259) && (window2CanvasY(mouse.cur_pos_y) <= 391) && lost)
		{
			updateN(STATUS_START);
		}
		else // TODO: SECOND PRIORITY add more info button
		{
			hover[0] = 1.f;
			hover[8] = 1.f;
			hover[4] = 1.f;
			hover[2] = 1.f;
			hover[6] = 1.f;
			hover[3] = 1.f;
			hover[13] = 1.f;
			hover[6] = 1.f;
			hover[5] = 1.f;
		}
	}
	else
	{
		if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
		{
			delete this; // TODO: check this one
		}
		else if (graphics::getKeyState(graphics::SCANCODE_B) && !key_down)
		{
			key_down = true;
			music_on = music_on_holder;
			if (paused) paused = !paused;
			updateMusic(modern);
			current_status = STATUS_START;
		}
		// Sound on/off
		else if (graphics::getKeyState(graphics::SCANCODE_N) && !key_down)
		{
			key_down = true;
			sound_on = !sound_on; //TODO: Add function to turn sound on off
		}
		else if (graphics::getKeyState(graphics::SCANCODE_RSHIFT) && !key_down)
		{
			key_down = true;
			full_screen = !full_screen;
			graphics::setFullScreen(full_screen);
		}
		else if (graphics::getKeyState(graphics::SCANCODE_SPACE) && !key_down)
		{
			key_down = true;
			paused = !paused;
		}
		else if (!graphics::getKeyState(graphics::SCANCODE_B) && !graphics::getKeyState(graphics::SCANCODE_N) && !graphics::getKeyState(graphics::SCANCODE_RSHIFT) && !graphics::getKeyState(graphics::SCANCODE_SPACE))
		{
			key_down = false;
		}
	}

	if (enemies[0] && enemies[0]->getCollidable())
	{
		time_counter += graphics::getDeltaTime();
		if (time_counter > 5000)
		{
			enemies[0]->setCollidable(false);
			pacman->setCollidable(true);
			time_counter = 0;
		}
	}

	if (enemies[1] && enemies[1]->getCollidable())
	{
		time_counter += graphics::getDeltaTime();
		if (time_counter > 5000)
		{
			enemies[1]->setCollidable(false);
			pacman->setCollidable(true);
			time_counter = 0;
		}
	}

	if (enemies[2] && enemies[2]->getCollidable())
	{
		time_counter += graphics::getDeltaTime();
		if (time_counter > 5000)
		{
			enemies[2]->setCollidable(false);
			pacman->setCollidable(true);
			time_counter = 0;
		}
	}

	if (enemies[3] && enemies[3]->getCollidable())
	{
		time_counter += graphics::getDeltaTime();
		if (time_counter > 5000)
		{
			enemies[3]->setCollidable(false);
			pacman->setCollidable(true);
			time_counter = 0;
		}
	}

	if (!maze)
	{
		maze = new Maze(*this);
		time_counter_2 = 0;
	}

	if (!pacman)
	{
		if (pacman_lives > 0)
		{
			pacman = new PacMan(*this);
			pacman->setCollidable(true);
			time_counter = 0;
			pacman->setSpeed(pacman_speed);
		}
	}

	if (!enemies[0])
	{
		if (!enemies[3])
		{
			enemies[0] = new Phantom(*this, BLINKY);
			time_counter = 0;
			enemies[0]->setCollidable(false);
			enemies[0]->setSpeed(phantom_speed);
		}
	}

	if (!enemies[1])
	{
		if(!enemies[3])
		{
			enemies[1] = new Phantom(*this, PINKY);
			time_counter = 0;
			enemies[1]->setCollidable(false);
			enemies[1]->setSpeed(phantom_speed);
		}
	}

	if (!enemies[2])
	{
		if (!enemies[3])
		{
			enemies[2] = new Phantom(*this, INKY);
			time_counter = 0;
			enemies[2]->setCollidable(false);
			enemies[2]->setSpeed(phantom_speed);
		}
	}

	if (!enemies[3])
	{
		if (enemies[0])
		{
			enemies[3] = new Phantom(*this, CLYDE);
			time_counter = 0;
			enemies[3]->setCollidable(false);
			enemies[3]->setSpeed(phantom_speed);
		}
	}

	if (maze)
	{
		maze->update();
	}

	for (int i = 0; i < 4; i++)
	{
		if (enemies[i]) enemies[i]->update();
	}

	if (pacman)
	{
		pacman->update();
	}
	
	if (pacman && pacman->getCollidable() && enemies[0] && enemies[1] && enemies[2] && enemies[3] && (checkCollisionPacMan() || checkCollisionPacMan(1) || checkCollisionPacMan(2) || checkCollisionPacMan(3)))
	{
		delete pacman;
		pacman = nullptr;
		--pacman_lives;
	}

	if (pacman_lives == 0)
	{
		lost = true;
	}

	for (int i = 0; i < 4; i++)
	{
		if (checkCollisionPacMan(i) && enemies[i]->getCollidable())
		{
			delete enemies[i];
			pacman->setCollidable(true);
			enemies[i] = nullptr;
			obst_counter = 0;
			if (i != 3 && enemies[i+1]) enemies[i+1]->setStart(false);
			time_counter = 0;
		}
	}

	for (auto const& value : maze->pacdots)
	{
		if (checkCollisionPacDot(value, true))
		{
			if (!value->getBig())
			{
				score += 10;
				local_score += 1;
			}
			else
			{
				score += 50;
				local_score += 1;
				if (enemies[0])enemies[0]->setCollidable(true);
				else if (enemies[1]) enemies[1]->setCollidable(true);
				else if (enemies[2]) enemies[2]->setCollidable(true);
				else if (enemies[3]) enemies[3]->setCollidable(true);
				pacman->setCollidable(false);
			}

			if (score % 5 == 0 && sound_on)
			{
				graphics::playSound(std::string(ASSET_PATH) + std::string(CHOMP), 1.f, false);
			}

			if (score > highscore)
			{
				highscore = score;
			}
			maze->destroyDot(value);
		}
	}

	if (pacman && maze)
	{
		for (auto const& value : maze->obstacles)
		{
			if (!checkCollisionObstacle(value, true))
			{
				obst_counter_2 += 1;
			}
			else
			{
				obst_counter_2 = 0;
			}

			if (obst_counter_2 == maze->obstacles.size())
			{
				if (pacman)
				{
					pacman->movement[0] = true;
					pacman->movement[1] = true;
					pacman->movement[2] = true;
					pacman->movement[3] = true;
				}
			}
		}
	}

	if (maze)
	{
		for (int i = 0; i < 4; i++)
		{
			obst_counter = 0;
			if (enemies[i] && !enemies[i]->getStart())
			{
				for (auto const& value : maze->obstacles)
				{
					if (!checkCollisionObstacle(value, false, i))
					{
						obst_counter += 1;
					}
					else
					{
						obst_counter = 0;
					}

					if (obst_counter == maze->obstacles.size())
					{
						if (enemies[i])
						{
							enemies[i]->movement[0] = true;
							enemies[i]->movement[1] = true;
							enemies[i]->movement[2] = true;
							enemies[i]->movement[3] = true;
						}
					}
				}
			}
		}
	}
		
	if (!enemies[0] && !enemies[1] && !enemies[2] && !enemies[3])
	{
		delete maze;
		maze = nullptr;
		delete pacman;
		pacman = nullptr;
		phantom_speed += 0.3f;
		pacman_speed += 0.3f;
		pacman_level += 1;
		local_score = 0;
	}

	
	if (pacman && maze && maze->pacdots.empty() && local_score > 0)
	{
		delete maze;
		maze = nullptr;
		delete pacman;
		pacman = nullptr;
		for (int i = 0; i < 4; i++)
		{
			if (enemies[i])
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
		phantom_speed += 0.3f;
		pacman_speed += 0.3f;
		pacman_level += 1;
		local_score = 0;
	}
}


void Menu::updateGameC()
{
	if (modern)
	{
		updateModernWelcome();
	}
	else
	{
		updateClassicWelcome();
	}
}

void Menu::updateGameMSelection()
{
	time_counter += graphics::getDeltaTime();

	if (time_counter > 200)
	{
		place_holder = !place_holder;
		time_counter = 0;
	}
}

void Menu::updateGameMInfo()
{
	graphics::getMouseState(mouse);
	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		updateX();
	}
	// Openning info panel
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 14) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 53 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 25 + 5))
	{
		updateI();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
	{
		updateFullScreen();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30 + 20))
	{
		updateB(STATUS_PLAYINGM);
	}
	// Music on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateM();
	}
	// Sound on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateS();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH/2 - 120) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH / 2 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT/2 + 110 - 40) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT/2 + 110 + 40))
	{
		if (mouse.button_left_released)
		{
			graphics::stopMusic(1000);
			music_on_holder = music_on;
			music_on = false;
			modern = true;
			current_status = STATUS_PLAYINGM_GAME;
		}
		else
		{
			hover[7] = 1.2f;
		}
	}
	else // TODO: SECOND PRIORITY add more info button
	{
		hover[0] = 1.f;
		hover[8] = 1.f;
		hover[4] = 1.f;
		hover[2] = 1.f;
		hover[3] = 1.f;
		hover[7] = 1.f;
	}
}

void Menu::updateGameM()
{
	graphics::getMouseState(mouse);
	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		updateX();
	}
	// Openning info panel
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 14) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 53 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 25 + 5))
	{
		updateI();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
	{
		updateFullScreen();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30 + 20))
	{
		updateB();
	}
	// Music on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateM();
	}
	// Sound on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateS();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 250 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700) && (window2CanvasY(mouse.cur_pos_y) >= 180 - 15) && (window2CanvasY(mouse.cur_pos_y) <= 180 + 15))
	{
		if (mouse.button_left_released)
		{
			phantom = BLINKY;
			current_status = STATUS_PLAYINGM_INFO;
		}
		else
		{
			hover[9] = 1.5f;
		}
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 250 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700) && (window2CanvasY(mouse.cur_pos_y) >= 255 - 15) && (window2CanvasY(mouse.cur_pos_y) <= 255 + 15))
	{
		if (mouse.button_left_released)
		{
			phantom = PINKY;
			current_status = STATUS_PLAYINGM_INFO;
		}
		else
		{
			hover[10] = 1.5f;
		}
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 250 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700) && (window2CanvasY(mouse.cur_pos_y) >= 330 - 15) && (window2CanvasY(mouse.cur_pos_y) <= 330 + 15))
	{
		if (mouse.button_left_released)
		{
			phantom = INKY;
			current_status = STATUS_PLAYINGM_INFO;
		}
		else
		{
			hover[11] = 1.5f;
		}
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 250 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700) && (window2CanvasY(mouse.cur_pos_y) >= 405 - 15) && (window2CanvasY(mouse.cur_pos_y) <= 405 + 15))
	{
		if (mouse.button_left_released)
		{
			phantom = CLYDE;
			current_status = STATUS_PLAYINGM_INFO;
		}
		else
		{
			hover[12] = 1.5f;
		}
	}
	else
	{
		hover[0] = 1.f;
		hover[8] = 1.f;
		hover[4] = 1.f;
		hover[2] = 1.f;
		hover[3] = 1.f;
		hover[9] = 1.f;
		hover[10] = 1.f;
		hover[11] = 1.f;
		hover[12] = 1.f;
	}
	updateGameMSelection();
}

void Menu::updateGameB()
{
	graphics::getMouseState(mouse);

	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		updateX();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateM();
	}
	// Sound on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateS();
	}
	// Openning info panel
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 14) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 53 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 25 + 5))
	{
		updateI();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH/4 + CANVAS_WIDTH/2 - 100) && (window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH / 4 + CANVAS_WIDTH / 2 + 100) 
		&& (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT /2 - 100) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT/2+100))

	{
		if (mouse.button_left_released)
		{
			system(std::string(WEBPAGEPONG).c_str());
		}
		else
		{
			hover[5] = 1.1f;
		}
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH / 4 - 100) && (window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH / 4 + 100)
		&& (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 100) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 100))

	{
		if (mouse.button_left_released)
		{	
			graphics::stopMusic(1000);
			music_on_holder = music_on;
			music_on = false;
			current_status = STATUS_PLAYINGPONG;
		}
		else
		{
			hover[6] = 1.1f;
		}
	}
	// full screen
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
	{
		updateFullScreen();
	}
	// back
	else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30+20))
	{
		updateB();
	}
	else
	{
		hover[0] = 1.f;
		hover[1] = 1.f;
		hover[2] = 1.f;
		hover[3] = 1.f;
		hover[4] = 1.f;
		hover[5] = 1.f;
		hover[6] = 1.f;
		hover[8] = 1.f;
	}
}

// Changing music
void Menu::updateMusic(bool musictype)
{
	// Checking music type and playing it if it should play
	if (modern && music_on) {
		graphics::stopMusic(500);
		graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICM), 1.0f);
	}
	else if (!modern && music_on)
	{
		graphics::stopMusic(500);
		graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICC), 1.0F);
	}
	else if (!music_on)
	{
		graphics::stopMusic(500);
	}
}

void Menu::updateClassicWelcome2()
{
	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		delete this; // TODO: check this one
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RETURN) && !key_down)
	{
		key_down = true;
		graphics::stopMusic(1000);
		music_on_holder = music_on;
		music_on = false;
		current_status = STATUS_PLAYINGCGAME;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_B) && !key_down)
	{
		key_down = true;
		current_status = STATUS_START;
	}
	// Music on/off
	else if (graphics::getKeyState(graphics::SCANCODE_M) && !key_down)
	{
		key_down = true;
		music_on = !music_on;
		music_on_holder = music_on;
		updateMusic(modern);
	}
	// Sound on/off
	else if (graphics::getKeyState(graphics::SCANCODE_N) && !key_down)
	{
		key_down = true;
		sound_on = !sound_on; //TODO: Add function to turn sound on off
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RSHIFT) && !key_down)
	{
		key_down = true;
		full_screen = !full_screen;
		graphics::setFullScreen(full_screen);
	}
	else if (!graphics::getKeyState(graphics::SCANCODE_RETURN) && !graphics::getKeyState(graphics::SCANCODE_B) && !graphics::getKeyState(graphics::SCANCODE_M) && !graphics::getKeyState(graphics::SCANCODE_N) && !graphics::getKeyState(graphics::SCANCODE_RSHIFT))
	{
		key_down = false;
	}
}

void Menu::updateGameMultiPlayer()
{
	graphics::getMouseState(mouse);
	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		updateX();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
	{
		updateFullScreen();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30 + 20))
	{	
		updateB(STATUS_START);
	}
	// Music on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateM();
	}
	// Sound on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateS();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		delete this; // TODO: check this one
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 40 - 20) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 20) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 40 - 15) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 15))
	{
		if (!lost)
		{
			updateP();
		}
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 128) &&
		(window2CanvasX(mouse.cur_pos_x) <= 372) && (window2CanvasY(mouse.cur_pos_y) >= 259) && (window2CanvasY(mouse.cur_pos_y) <= 391) && lost)
	{
		updateY();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 128 + 500) &&
		(window2CanvasX(mouse.cur_pos_x) <= 372 + 500) && (window2CanvasY(mouse.cur_pos_y) >= 259) && (window2CanvasY(mouse.cur_pos_y) <= 391) && lost)
	{
		updateN(STATUS_START);
	}
	else // TODO: SECOND PRIORITY add more info button
	{
		hover[0] = 1.f;
		hover[8] = 1.f;
		hover[4] = 1.f;
		hover[5] = 1.f;
		hover[2] = 1.f;
		hover[6] = 1.f;
		hover[3] = 1.f;
		hover[13] = 1.f;
	}

	if (!maze)
	{
		maze = new Maze(*this);
		time_counter_2 = 0;
	}

	if (maze)
	{
		maze->update();
	}

	if (!enemies[0] && !replay)
	{
		enemies[0] = new Phantom(*this);
		time_counter = 0;
		enemies[0]->setCollidable(false);
	}
	else if (!enemies[0])
	{
		time_counter_2 += graphics::getDeltaTime();
		if (time_counter_2 > 5000)
		{
			enemies[0] = new Phantom(*this);
			time_counter_2 = 0;
		}
	}

	if (enemies[0])
	{
		enemies[0]->update();
	}

	if (!pacman && !replay)
	{
		pacman = new PacMan(*this);
		pacman->setCollidable(true);
	}
	else if (!pacman)
	{
		time_counter_2 += graphics::getDeltaTime();
		if (time_counter_2 > 5000)
		{
			pacman = new PacMan(*this);
			time_counter_2 = 0;
		}
	}

	if (pacman)
	{
		pacman->update();
	}

	if (checkCollisionPacMan() && pacman->getCollidable())
	{
		delete pacman;
		pacman = nullptr;
		replay = true;
	}

	if (checkCollisionPacMan() && enemies[0]->getCollidable())
	{
		delete enemies[0];
		pacman->setCollidable(true);
		enemies[0] = nullptr;
		replay = true;
	}

	if (maze && !maze->pacdots.empty())
	{
		for (auto const& value : maze->pacdots)
		{
			if (checkCollisionPacDot(value, true))
			{
				if (!value->getBig())
				{
					player_score += 10;
				}
				else
				{
					player_score += 50;
					enemies[0]->setCollidable(true);
					pacman->setCollidable(false);
				}

				if (player_score % 5 == 0 && sound_on)
				{
					graphics::playSound(std::string(ASSET_PATH) + std::string(CHOMP), 1.f, false);
				}
				maze->destroyDot(value);
			}
		}

		for (auto const& value : maze->pacdots)
		{
			if (checkCollisionPacDot(value, false))
			{
				if (!value->getBig())
				{
					phantom_score += 10;
				}
				else
				{
					phantom_score += 50;
				}

				if (phantom_score % 5 == 0 && sound_on)
				{
					graphics::playSound(std::string(ASSET_PATH) + std::string(CHOMPFRUIT), 1.f, false);
				}
				maze->destroyDot(value);
			}
		}
	}
	
	if (enemies[0] && maze)
	{
		for (auto const& value : maze->obstacles)
		{
			if (!checkCollisionObstacle(value, false))
			{
				obst_counter += 1;
			}
			else
			{
				obst_counter = 0;
			}

			if (obst_counter == maze->obstacles.size())
			{
				if (enemies[0])
				{
					enemies[0]->movement[0] = true;
					enemies[0]->movement[1] = true;
					enemies[0]->movement[2] = true;
					enemies[0]->movement[3] = true;
				}
			}
		}
	}

	if (pacman && maze)
	{
		for (auto const& value : maze->obstacles)
		{
			if (!checkCollisionObstacle(value, true))
			{
				obst_counter_2 += 1;
			}
			else
			{
				obst_counter_2 = 0;
			}

			if (obst_counter_2 == maze->obstacles.size())
			{
				if (pacman)
				{
					pacman->movement[0] = true;
					pacman->movement[1] = true;
					pacman->movement[2] = true;
					pacman->movement[3] = true;
				}
			}
		}
	}
	
	if (enemies[0] && enemies[0]->getCollidable())
	{
		time_counter += graphics::getDeltaTime();
		if (time_counter > 5000)
		{
			enemies[0]->setCollidable(false);
			pacman->setCollidable(true);
			time_counter = 0;
		}
	}

	if (maze && maze->pacdots.size() == 0 && (player_score > 0 || phantom_score > 0))
	{
		paused = true;
		lost = true;
		replay = false;
		delete pacman;
		pacman = nullptr;
		delete enemies[0];
		enemies[0] = nullptr;
		delete maze;
		maze = nullptr;
		if (phantom_score > player_score) // TODO: PRIO player score increases with b button
		{
			if (sound_on) graphics::playSound(std::string(ASSET_PATH) + std::string(GAMEOVERPACMAN), 1.f, false);
			msg = "PHANTOM WINS";
		}
		else if (phantom_score < player_score)
		{
			if (sound_on) graphics::playSound(std::string(ASSET_PATH) + std::string(WINPACMAN), 1.f, false);
			msg = "PLAYER WINS";
		}
		else
		{
			if (sound_on) graphics::playSound(std::string(ASSET_PATH) + std::string(TIEPACMAN), 1.f, false);
			msg = "THAT IS A DRAW";
		}
		phantom_score = 0;
		player_score = 0;
	}
}

void Menu::updatePong() // TODO: SECOND PRIO ADD MULTIPLAYER VS SINGLE PLAYER
{
	graphics::getMouseState(mouse);
	// Closing windw on close window click
	if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		updateX();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
	{
		updateFullScreen();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 20) && (window2CanvasX(mouse.cur_pos_x) <= 60) && (window2CanvasY(mouse.cur_pos_y) >= 30 - 20) && (window2CanvasY(mouse.cur_pos_y) <= 30 + 20))
	{
		if (mouse.button_left_released){
			if (music_on)
			{
				updateMusic(modern);
			}
		}
		updateB(STATUS_PLAYINGB);
	}
	// Music on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateM();
	}
	// Sound on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		updateS();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 40-20) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH-20) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 40-15) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 15))
	{
		if (!lost)
		{
			updateP();
		}
	}
	else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		delete this; // TODO: check this one
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 128) &&
		(window2CanvasX(mouse.cur_pos_x) <= 372) && (window2CanvasY(mouse.cur_pos_y) >= 259) && (window2CanvasY(mouse.cur_pos_y) <= 391 ) && lost)
	{
		updateY();
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= 128+500) &&
		(window2CanvasX(mouse.cur_pos_x) <= 372+500) && (window2CanvasY(mouse.cur_pos_y) >= 259) && (window2CanvasY(mouse.cur_pos_y) <= 391) && lost)
	{
		updateN(STATUS_PLAYINGB);
	}
	else
	{
		hover[0] = 1.f;
		hover[8] = 1.f;
		hover[4] = 1.f;
		hover[2] = 1.f;
		hover[6] = 1.f;
		hover[3] = 1.f;
		hover[13] = 1.f;
		hover[5] = 1.f;
	}

	if (!pong_player)
	{
		pong_player = new Pong(*this, false);
	}

	if (!pong_ai)
	{
		pong_ai = new Pong(*this, true);
	}

	if (!pong_ball)
	{
		pong_ball = new PongBall(*this);
		time_counter = 0.f;
	}

	if (pong_player && !paused)
	{
		pong_player->update();
	}

	if (pong_ai && !paused)
	{
		pong_ai->update();
	}

	if (pong_ball && !paused)
	{
		pong_ball->update();
	}
	if (checkCollisionPong(pong_ball->getDir()) && pong_ball && !paused)
	{
		pong_ball->changeDirection();
	}
	time_counter += graphics::getDeltaTime();

	if (local_score % 150 == 0 && local_score!=0 && !lost)
	{
		local_score = 0;
		level += 1;
		local_level += 1;
	}

	if (time_counter > 60000 && !lost && !paused)
	{
		time_counter = 0.f;
		pong_speed += 1;
		local_level += 1;
	}

	if (pong_ball)
	{
		if (pong_ball->getX() < 0 || pong_ball->getX() > CANVAS_WIDTH)
		{
			if(sound_on) graphics::playSound(std::string(ASSET_PATH) + std::string(GAMEOVERPONG), 1.f, false);
			paused = true;
			lost = true;
			delete pong_ball;
			pong_ball = nullptr;
			delete pong_ai;
			pong_ai = nullptr;
			delete pong_player;
			pong_player = nullptr;
			score_pong = 0;
			local_score = 0;
			level = 1;
			local_level = 1;
		}
	}	
}

void Menu::update()
{
	if (current_status == STATUS_START) 
	{
		if (pacman) 
		{
			delete pacman;
			pacman = nullptr;
		}
		if (pong_ai)
		{
			delete pong_ai;
			pong_ai = nullptr;
		}
		if (pong_player)
		{
			delete pong_player;
			pong_player = nullptr;
		}
		if (pong_ball)
		{
			delete pong_ball;
			pong_ball = nullptr;
		}
		if(maze)
		{
			delete maze;
			maze = nullptr;
		}

		for (int i = 0; i < 4; i++)
		{
			if (enemies[i])
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
		multi = false;
		updateMenuScreen();
	}
	else if (current_status == STATUS_PLAYINGC)
	{
		if (pacman)
		{
			delete pacman;
			pacman = nullptr;
		}
		multi = false;
		updateGameC();
	}
	else if (current_status == STATUS_PLAYINGC2)
	{
		if(maze)
		{
			delete maze;
			maze = nullptr;
		}
		if (pacman)
		{
			delete pacman;
			pacman = nullptr;
		}

		for (int i = 0; i < 4; i++)
		{
			if (enemies[i])
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
		multi = false;
		updateClassicWelcome2();
	}
	else if (current_status == STATUS_PLAYINGM)
	{
		if(maze)
		{
			delete maze;
			maze = nullptr;
		}
		if (pacman)
		{
			delete pacman;
			pacman = nullptr;
		}

		for (int i = 0; i < 4; i++)
		{
			if (enemies[i])
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
		multi = false;
		updateGameM();
	}
	else if (current_status == STATUS_PLAYINGM_INFO)
	{
		if (pacman)
		{
			delete pacman;
			pacman = nullptr;
		}
		if (enemies[0])
		{
			delete enemies[0];
			enemies[0] = nullptr;
		}
		if (maze)
		{
			delete maze;
			maze = nullptr;
		}
		multi = false;
		lost = false;
		updateGameMInfo();
	}
	else if (current_status == STATUS_PLAYINGB)
	{
		if (pong_ai)
		{
			delete pong_ai;
			pong_ai = nullptr;
		}
		if (pong_player)
		{
			delete pong_player;
			pong_player = nullptr;
		}
		if (pong_ball)
		{
			delete pong_ball;
			pong_ball = nullptr;
		}
		multi = false;
		updateGameB();
	}
	else if (current_status == STATUS_PLAYINGCGAME)
	{
		multi = false;
		lost = false;
		updateClassicGame();
	}
	else if (current_status == STATUS_PLAYINGM_GAME)
	{
		multi = true;
		modern = true;
		updateGameMultiPlayer();
	}
	else if (current_status == STATUS_PLAYINGPONG)
	{
		multi = false;
		updatePong();
	}
	
}

void Menu::drawClassicScreen()
{
	// Resetting opacity
	brush.outline_opacity = 0.f;

	// ----- Images -----

	// Setting the image brush for the background
	brush.texture = FONTC;

	// Resetting opacity
	brush.fill_opacity = 1.f;

	// Setting colors to black for classic game mode
	brush.fill_color[0] = 0.f;
	brush.fill_color[1] = 0.f;
	brush.fill_color[2] = 0.f;

	// Drawing black background
	graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 50.f), 600, canvas_height, brush);

	// ----- Title -----

	// Setting font for classic game mode
	graphics::setFont(std::string(ASSET_PATH) + std::string(FONTPACMAN));

	// Setting txt opacity to default
	brush.fill_opacity = 1.f;

	// Setting color for title
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Drawing text for title
	graphics::drawText(width_to_x(canvas_width, 39.f), height_to_y(canvas_height, 25.f), 50.F, std::string(TITLE), brush);

	// ----- High Score & Score -----

	// Setting color for text for classic game mode
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Setting font for classic game mode
	//graphics::setFont(std::string(ASSET_PATH) + std::string(FONTC)); 
	// TODO: Check why font is not working on change

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 26.25f), height_to_y(canvas_height, 7.f), 30.F, std::string(SCORE), brush);
	graphics::drawText(width_to_x(canvas_width, 26.25f), height_to_y(canvas_height, 12.f), 25.F, std::to_string(pacman_local_score), brush);

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 65.f), height_to_y(canvas_height, 7.f), 30.f, std::string(HSCORE), brush);
	graphics::drawText(width_to_x(canvas_width, 65.f), height_to_y(canvas_height, 12.f), 25.f, std::to_string(highscore), brush);

	// ----- KEY HANDLING TEXT -----

	// Setting color for text for classic game mode
	brush.fill_color[0] = COLORBLUE_R;
	brush.fill_color[1] = COLORBLUE_G;
	brush.fill_color[2] = COLORBLUE_B;
	loc_brush.fill_color[0] = COLORBLUE_R;
	loc_brush.fill_color[1] = COLORBLUE_G;
	loc_brush.fill_color[2] = COLORBLUE_B;

	time_counter += graphics::getDeltaTime();

	if (time_counter >= 750 && loc_brush.fill_opacity < 1.f)
	{
		loc_brush.fill_opacity = 1.f;
		time_counter = 0.f;
	}
	if (time_counter >= 750 && loc_brush.fill_opacity != 0.f)
	{
		loc_brush.fill_opacity = 0.f;
		time_counter = 0.f;
	}

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 37.5f), height_to_y(canvas_height, 50.f), 25.f, std::string(PLAY), loc_brush);

	brush.fill_opacity = .5f;
	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 10.f), height_to_y(canvas_height, 64.f), 25.f, std::string(MUSICT), brush);

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 60.f), height_to_y(canvas_height, 64.f), 25.f, std::string(SOUNDT), brush);

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 8.f), height_to_y(canvas_height, 78.f), 25.f, std::string(SWITCH), brush);

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 56.f), height_to_y(canvas_height, 78.f), 25.f, std::string(FULLSCREEN), brush);

	// Setting color for text for classic game mode
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Drawing text
	graphics::drawText(width_to_x(canvas_width, 38.2f), height_to_y(canvas_height, 90.f), 25.f, std::string(ESCA), brush);

	// Resetting opacity
	brush.fill_opacity = 1.f;
}

void Menu::drawX()
{

	brush.outline_opacity = 0.f;

	// Taking out the close button if hover
	graphics::setScale(hover[0], hover[0]);

	// Setting the image brush for the close button
	brush.texture = std::string(ASSET_PATH) + std::string(CLOSE);

	// Drawing image for close button
	graphics::drawRect(width_to_x(canvas_width, 95.f), height_to_y(canvas_height, 5.f), 40, 40, brush);

	brush.outline_opacity = 1.f;

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Closed
	graphics::drawText(width_to_x(canvas_width, 93.5f), height_to_y(canvas_height, 11.f), 10.F, std::string(CLOSET), brush);

	resetBrush();
}

void Menu::drawI()
{
	brush.outline_opacity = 0.f;

	// Taking out the info button if hover
	graphics::setScale(hover[1], hover[1]);

	// Setting the image brush for the info button
	brush.texture = std::string(ASSET_PATH) + std::string(INFO);

	// Drawing image for info button
	graphics::drawRect(width_to_x(canvas_width, 95.f), height_to_y(canvas_height, 95.f), 40, 40, brush);

	// Resetting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Info
	graphics::drawText(width_to_x(canvas_width, 93.83f), height_to_y(canvas_height, 90.f), 10.F, std::string(INFOT), brush);

	resetBrush();
}

void Menu::drawFullScreen()
{
	brush.outline_opacity = 0.f;

	// Taking out the full screen
	graphics::setScale(hover[8], hover[8]);

	// Setting the image brush for on/off full screen
	if (full_screen)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(NOTFULL);
	}
	else
	{
		brush.texture = std::string(ASSET_PATH) + std::string(FULL);
	}

	// Drawing image for multi player
	graphics::drawRect(width_to_x(canvas_width, 5.f), height_to_y(canvas_height, 95.f), 40, 40, brush);

	// Resetting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Full screen
	graphics::drawText(width_to_x(canvas_width, 2.17f), height_to_y(canvas_height, 90.f), 10.F, std::string(FULLT), brush);

	resetBrush();
}

void Menu::drawB()
{
	brush.outline_opacity = 0.f;

	// Taking out the close button if hover
	graphics::setScale(hover[4], hover[4]);

	// Setting the image brush for the close button
	brush.texture = std::string(ASSET_PATH) + std::string(BACK);

	// Drawing image for close button
	graphics::drawRect(width_to_x(canvas_width, 5.f), height_to_y(canvas_height, 5.f), 40, 40, brush);

	brush.outline_opacity = 1.f;

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Closed
	graphics::drawText(width_to_x(canvas_width, 3.65f), height_to_y(canvas_height, 11.f), 10.F, std::string(BACKT), brush);

	resetBrush();
}

void Menu::drawP()
{
	brush.outline_opacity = 0.f;

	// Taking out the close button if hover
	graphics::setScale(hover[13], hover[13]);

	// Setting the image brush for the close button
	if (!paused)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PAUSEIMG);
	}
	else
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PLAYIMG);
	}

	// Drawing image for close button
	graphics::drawRect(width_to_x(canvas_width, 95.f), height_to_y(canvas_height, 95.f), 40, 40, brush);

	brush.outline_opacity = 1.f;

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Closed
	if (paused)
	{
		graphics::drawText(width_to_x(canvas_width, 93.05f), height_to_y(canvas_height, 90.f), 10.F, std::string(RESUMET), brush);
	}
	else
	{
		graphics::drawText(width_to_x(canvas_width, 93.36f), height_to_y(canvas_height, 90.f), 10.f, std::string(PAUSET), brush);
	}

	resetBrush();
}

void Menu::drawClassicWelcome()
{
	brush.outline_opacity = 0.f;
	time_counter += graphics::getDeltaTime();
	if (time_counter > 500)
	{
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;

		graphics::drawText(width_to_x(canvas_width, 36.f), height_to_y(canvas_height, 5.f), 25.f, CLASSSTARTTITLE, brush);
		graphics::drawText(width_to_x(canvas_width, 45.f), height_to_y(canvas_height, 10.f), 20.f, std::to_string(highscore), brush);

		graphics::drawText(width_to_x(canvas_width, 34.5f), height_to_y(canvas_height, 20.f), 20.f, CHARNICK, brush);
		graphics::drawText(width_to_x(canvas_width, 10.f),height_to_y(canvas_height, 95.f), 15.f, CREDITS, brush);
		graphics::drawText(width_to_x(canvas_width, 17.5f), height_to_y(canvas_height, 95.f), 15.f, std::to_string(pacman_local_score), brush);
	}
	if (time_counter > 1000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_1);
		graphics::drawRect(width_to_x(canvas_width, 30.f), height_to_y(canvas_height, 35.f), 30, 30, brush);
		brush.fill_color[0] = COLORBLINKYC_R;
		brush.fill_color[1] = COLORBLINKYC_G;
		brush.fill_color[2] = COLORBLINKYC_B;
	}
	if (time_counter > 2000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 35.5f), height_to_y(canvas_height, 36.f), 15.f, BLINKYT, brush);
	}
	if (time_counter > 3000) 
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 57.f), height_to_y(canvas_height, 36.f), 15.f, BLINKYTN, brush);
	}
	if (time_counter > 4000)
	{
		brush.outline_opacity = 0.f;
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_1);
		graphics::drawRect(width_to_x(canvas_width, 30.f), height_to_y(canvas_height, 45.f), 30, 30, brush);
		brush.fill_color[0] = COLORPINKYC_R;
		brush.fill_color[1] = COLORPINKYC_G;
		brush.fill_color[2] = COLORPINKYC_B;
	}
	if (time_counter > 5000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 35.5f), height_to_y(canvas_height, 46.f), 15.f, PINCKYT, brush);
	}
	if (time_counter > 6000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 57.f), height_to_y(canvas_height, 46.f), 15.f, PINCKYTN, brush);
	}
	if (time_counter > 7000)
	{
		brush.outline_opacity = 0.f;
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_1);
		graphics::drawRect(width_to_x(canvas_width, 30.f), height_to_y(canvas_height, 55.f), 30, 30, brush);
		brush.fill_color[0] = COLORINKYC_R;
		brush.fill_color[1] = COLORINKYC_G;
		brush.fill_color[2] = COLORINKYC_B;
	}
	if (time_counter > 8000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 35.5f), height_to_y(canvas_height, 56.f), 15.f, INKYT, brush);
	}
	if (time_counter > 9000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 57.f), height_to_y(canvas_height, 56.f), 15.f, INKYTN, brush);
	}
	if (time_counter > 10000)
	{
		brush.outline_opacity = 0.f;
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_1);
		graphics::drawRect(width_to_x(canvas_width, 30.f), height_to_y(canvas_height, 65.f), 30, 30, brush);
		brush.fill_color[0] = COLORCLYDEC_R;
		brush.fill_color[1] = COLORCLYDEC_G;
		brush.fill_color[2] = COLORCLYDEC_B;
	}
	if (time_counter > 11000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 35.5f), height_to_y(canvas_height, 66.f), 15.f, CLYDET, brush);
	}
	if (time_counter > 12000)
	{
		brush.outline_opacity = 0.f;
		brush.texture = "";
		graphics::drawText(width_to_x(canvas_width, 57.f), height_to_y(canvas_height, 66.f), 15.f, CLYDETN, brush);
	}
	if (time_counter > 13000)
	{
		brush.outline_opacity = 0.f;
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_C);
		graphics::drawRect(width_to_x(canvas_width, 44.f), height_to_y(canvas_height, 85.f), 10, 10, brush);
		graphics::drawRect(width_to_x(canvas_width, 44.f), height_to_y(canvas_height, 90.f), 25, 25, brush);
		graphics::drawText(width_to_x(canvas_width, 54.f), height_to_y(canvas_height, 86.f), 13.f, "PTS", brush);
		graphics::drawText(width_to_x(canvas_width, 54.f), height_to_y(canvas_height, 91.f), 13.f, "PTS", brush);
		graphics::drawText(width_to_x(canvas_width, 49.f), height_to_y(canvas_height, 86.f), 17.f, "10", brush);
		graphics::drawText(width_to_x(canvas_width, 49.f), height_to_y(canvas_height, 91.f), 17.f, "50", brush);
	}
	if (time_counter > 14000 && counter<601)
	{
		brush.outline_opacity = 0.f;
		time_counter_2 += graphics::getDeltaTime();
		counter += 1;
		if (time_counter_2 < 100 && canvas_width / 2 + 100 - counter >= canvas_width / 2 - 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_2);
			graphics::drawRect(canvas_width/2 + 100 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
			graphics::drawRect(canvas_width / 2 + 140 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 160 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 180 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 200 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_C);
			graphics::drawRect(width_to_x(canvas_width, 30.f), height_to_y(canvas_height, 76.f), 20, 20, brush);
		}
		else if (time_counter_2 < 200 && CANVAS_WIDTH / 2 + 100 - counter >= CANVAS_WIDTH / 2 - 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH/2 + 100 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 140 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 160 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 180 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 200 - counter, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 300 && CANVAS_WIDTH/2 + 100 - counter >= CANVAS_WIDTH/2 -200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_START);
			graphics::drawRect(CANVAS_WIDTH/2 + 100 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 140 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 160 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 180 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 200 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_C);
			graphics::drawRect(width_to_x(canvas_width, 30.f), height_to_y(canvas_height, 76.f), 20, 20, brush);
		}
		else if (time_counter_2 < 100)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_RIGHT_2);
			graphics::drawRect(counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter + 40, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter+60, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter+80, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter+100, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_RIGHT_1);
			graphics::drawRect(counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_2);
			graphics::drawRect(counter + 40, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_2);
			graphics::drawRect(counter + 60, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_2);
			graphics::drawRect(counter + 80, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_2);
			graphics::drawRect(counter + 100, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 300)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_START);
			graphics::drawRect(counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter + 40, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter + 60, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter + 80, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			graphics::drawRect(counter + 100, 330, 20, 20, brush);
		}
		else
		{
			time_counter_2 = 0.f;
		}
	}
	if (counter > 600)
	{
		time_counter = 0.f;
		counter = 0;
	}
}


void Menu::drawClassicGame()
{
	if (modern) 
	{
		if (lost)
		{
			drawYN(msg);
		}
		drawM();
		drawS();
		drawX();
		drawB();
		drawP();
		drawFullScreen();
		brush.outline_opacity = 0.f;
	}

	if (!lost)
	{
		if (maze)
		{
			maze->draw();
		}

		if (pacman)
		{
			pacman->draw();
		}

		if (enemies[0])
		{
			enemies[0]->draw();
		}

		if (enemies[1])
		{
			enemies[1]->draw();
		}

		if (enemies[2])
		{
			enemies[2]->draw();
		}

		if (enemies[3])
		{
			enemies[3]->draw();
		}
	}

	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	if (modern)
	{
		graphics::drawText(CANVAS_WIDTH / 2 + 400, 130, 25.f, HISCORE, brush);
		graphics::drawText(CANVAS_WIDTH / 2 + 400, 150, 20.f, std::to_string(highscore), brush);
		graphics::drawText(CANVAS_WIDTH / 2 - 500, 130, 25.f, SCORE, brush);
		graphics::drawText(CANVAS_WIDTH / 2 - 500, 150, 20.f, std::to_string(score), brush);
		graphics::drawText(CANVAS_WIDTH / 2 - 500, 190, 25.f, "LEVEL", brush);
		graphics::drawText(CANVAS_WIDTH / 2 - 500, 210, 20.f, std::to_string(pacman_level), brush);

		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_2);
		if(pacman_lives>0)graphics::drawRect(140, CANVAS_HEIGHT - 30, 20, 20, brush);
		if(pacman_lives>1)graphics::drawRect(160, CANVAS_HEIGHT - 30, 20, 20, brush);
		if(pacman_lives>2)graphics::drawRect(180, CANVAS_HEIGHT - 30, 20, 20, brush);
		if(pacman_lives>3)graphics::drawRect(200, CANVAS_HEIGHT - 30, 20, 20, brush);
	}
}

void Menu::drawModernWelcome()
{
	brush.outline_opacity = 0.f;
	time_counter += graphics::getDeltaTime();
	if (time_counter > 500)
	{
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;

		graphics::drawText(CANVAS_WIDTH / 2 - 166, 50, 25.f, CLASSSTARTTITLE, brush);
		graphics::drawText(CANVAS_WIDTH / 2 - 166 + 85, 70, 20.f, std::to_string(highscore), brush);

		graphics::drawText(CANVAS_WIDTH / 2 - 188, 125, 20.f, CHARNICK, brush);
		graphics::drawText(200, CANVAS_HEIGHT - 50, 15.f, CREDITS, brush);
		graphics::drawText(300, CANVAS_HEIGHT - 50, 15.f, std::to_string(pacman_local_score), brush);
	}
	if (time_counter > 1000)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_1);
		graphics::drawRect(280, 190 - 25, 30, 30, brush);
		brush.fill_color[0] = COLORBLINKYC_R;
		brush.fill_color[1] = COLORBLINKYC_G;
		brush.fill_color[2] = COLORBLINKYC_B;
	}
	if (time_counter > 2000)
	{
		brush.texture = "";
		graphics::drawText(330, 190 - 25 + 5, 15.f, BLINKYT, brush);
	}
	if (time_counter > 3000)
	{
		brush.texture = "";
		graphics::drawText(590, 190 - 25 + 5, 15.f, BLINKYTN, brush);
	}
	if (time_counter > 4000)
	{
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_1);
		graphics::drawRect(280, 230 - 25, 30, 30, brush);
		brush.fill_color[0] = COLORPINKYC_R;
		brush.fill_color[1] = COLORPINKYC_G;
		brush.fill_color[2] = COLORPINKYC_B;
	}
	if (time_counter > 5000)
	{
		brush.texture = "";
		graphics::drawText(330, 230 - 25 + 5, 15.f, PINCKYT, brush);
	}
	if (time_counter > 6000)
	{
		brush.texture = "";
		graphics::drawText(590, 230 - 25 + 5, 15.f, PINCKYTN, brush);
	}
	if (time_counter > 7000)
	{
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_1);
		graphics::drawRect(280, 270 - 25, 30, 30, brush);
		brush.fill_color[0] = COLORINKYC_R;
		brush.fill_color[1] = COLORINKYC_G;
		brush.fill_color[2] = COLORINKYC_B;
	}
	if (time_counter > 8000)
	{
		brush.texture = "";
		graphics::drawText(330, 270 - 25 + 5, 15.f, INKYT, brush);
	}
	if (time_counter > 9000)
	{
		brush.texture = "";
		graphics::drawText(590, 270 - 25 + 5, 15.f, INKYTN, brush);
	}
	if (time_counter > 10000)
	{
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_1);
		graphics::drawRect(280, 310 - 25, 30, 30, brush);
		brush.fill_color[0] = COLORCLYDEC_R;
		brush.fill_color[1] = COLORCLYDEC_G;
		brush.fill_color[2] = COLORCLYDEC_B;
	}
	if (time_counter > 11000)
	{
		brush.texture = "";
		graphics::drawText(330, 310 - 25 + 5, 15.f, CLYDET, brush);
	}
	if (time_counter > 12000)
	{
		brush.texture = "";
		graphics::drawText(590, 310 - 25 + 5, 15.f, CLYDETN, brush);
	}
	if (time_counter > 13000)
	{
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_M);
		graphics::drawRect(200-120, 360-160, 10, 10, brush);
		graphics::drawRect(200-120, 390-160, 25, 25, brush);
		graphics::drawText(220-120, 367-160, 13.f, "PTS", brush);
		graphics::drawText(220-120, 399-160, 13.f, "PTS", brush);
		graphics::drawText(290-120, 367-160, 17.f, "10", brush);
		graphics::drawText(290-120, 399-160, 17.f, "50", brush);

		brush.texture = std::string(ASSET_PATH) + std::string(WASD);
		brush.outline_opacity = 0.5f;
		graphics::drawRect(CANVAS_WIDTH - 250 + 120, CANVAS_HEIGHT - 300, 150, 75, brush);
		brush.texture = std::string(ASSET_PATH) + std::string(ARROWS);
		graphics::drawRect(CANVAS_WIDTH - 250 + 120, CANVAS_HEIGHT - 200, 150, 75, brush);
		brush.outline_opacity = 0.f;
	}
	if (time_counter > 14000 && counter < 601)
	{
		time_counter_2 += graphics::getDeltaTime();
		counter += 1;
		if (time_counter_2 < 100 && CANVAS_WIDTH / 2 + 100 - counter >= CANVAS_WIDTH / 2 - 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 100 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 140 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 160 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 180 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 200 - counter, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 200 && CANVAS_WIDTH / 2 + 100 - counter >= CANVAS_WIDTH / 2 - 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 100 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 140 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 160 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 180 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_2);
			graphics::drawRect(CANVAS_WIDTH / 2 + 200 - counter, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 300 && CANVAS_WIDTH / 2 + 100 - counter >= CANVAS_WIDTH / 2 - 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_3);
			graphics::drawRect(CANVAS_WIDTH / 2 + 100 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 140 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 160 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 180 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_1);
			graphics::drawRect(CANVAS_WIDTH / 2 + 200 - counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_M);
			graphics::drawRect(300, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 100)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_2);
			graphics::drawRect(counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 40, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 60, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 80, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 100, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 200)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_1);
			graphics::drawRect(counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_2);
			graphics::drawRect(counter + 40, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_2);
			graphics::drawRect(counter + 60, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_2);
			graphics::drawRect(counter + 80, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_2);
			graphics::drawRect(counter + 100, 330, 20, 20, brush);
		}
		else if (time_counter_2 < 300)
		{
			brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_2);
			graphics::drawRect(counter, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 40, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 60, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 80, 330, 20, 20, brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_M_RIGHT_1);
			graphics::drawRect(counter + 100, 330, 20, 20, brush);
		}
		else
		{
			time_counter_2 = 0.f;
		}
	}
	if (counter > 600)
	{
		time_counter = 0.f;
		counter = 0;
	}
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;


	drawB();
	drawX();
	drawM();
	drawS();
	drawFullScreen();

	brush.outline_opacity = 0.f;

	// Taking out the signle player hover
	graphics::setScale(hover[6], hover[6]);

	// Setting the image brush for the single player
	brush.texture = std::string(ASSET_PATH) + std::string(SINGLEPALYER);

	// Drawing image for single player
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT / 2 + 130, 210, 70, brush);

	// Resetting hover
	graphics::resetPose();
}

void Menu::drawGameC()
{
	if (modern)
	{
		drawModernWelcome();
	}
	// TODO: Seperate classic game from modern game for single player

	else 
	{
		drawClassicWelcome();		
	}
}

void Menu::drawGameM()
{
	drawGameMSelection();

	drawX();
	drawB();
	drawFullScreen();
	drawM();
	drawS();
}

void Menu::drawGameB()
{
	brush.texture = std::string(ASSET_PATH) + std::string(BOREDARC);

	brush.outline_opacity = 1.f;

	graphics::setScale(hover[5], hover[5]);

	graphics::drawRect(width_to_x(canvas_width, 75.f), height_to_y(canvas_height, 50.f), 200, 200, brush);

	graphics::resetPose();

	brush.texture = std::string(ASSET_PATH) + std::string(BOREDPONG);

	brush.outline_opacity = 1.f;

	graphics::setScale(hover[6], hover[6]);

	graphics::drawRect(width_to_x(canvas_width, 25.f) , height_to_y(canvas_height, 50.f), 200, 200, brush);

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	graphics::drawText(width_to_x(canvas_width, 69.5f), height_to_y(canvas_height, 30.5f), 10.f, BOREDT, brush);

	graphics::drawText(width_to_x(canvas_width, 24.f), height_to_y(canvas_height, 30.5f), 10.f, PONG, brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	drawX();

	drawI();
		
	drawM();

	drawS();

	drawFullScreen();

	drawB();
}

void Menu::drawM()
{
	brush.outline_opacity = 0.f;

	// Taking out the music button if hover
	graphics::setScale(hover[2], hover[2]);

	if (!music_on)
	{
		// Setting the image brush for the music off button
		brush.texture = std::string(ASSET_PATH) + std::string(MUSIC_OFF);
	}
	else
	{
		// Setting the image brush for the music on button
		brush.texture = std::string(ASSET_PATH) + std::string(MUSIC_ON);
	}

	// Drawing image for sound button
	graphics::drawRect(width_to_x(canvas_width, 40.f), height_to_y(canvas_height, 94.f), 40, 40, brush);

	// Resseting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Music
	graphics::drawText(width_to_x(canvas_width, 38.3f), height_to_y(canvas_height, 90.f), 10.F, std::string(MUSIC), brush);

	resetBrush();
}

void Menu::drawS()
{
	
	brush.outline_opacity = 0.f;

	// Taking out the sound button if hover
	graphics::setScale(hover[3], hover[3]);

	// Setting the image brush for the close button
	brush.texture = std::string(ASSET_PATH) + std::string(CLOSE);

	if (!sound_on)
	{
		// Setting the image brush for the sound off button
		brush.texture = std::string(ASSET_PATH) + std::string(SOUND_OFF);
	}
	else
	{
		// Setting the image brush for the sound on button
		brush.texture = std::string(ASSET_PATH) + std::string(SOUND_ON);
	}

	// Drawing image for sound button
	graphics::drawRect(width_to_x(canvas_width, 60.f), height_to_y(canvas_height, 94.5f), 40, 40, brush);

	// Resetting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Sound
	graphics::drawText(width_to_x(canvas_width, 58.3f), height_to_y(canvas_height, 90.f), 10.F, std::string(SOUND), brush);

	resetBrush();
}

void Menu::drawGameMSelection()
{

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;
	graphics::drawText(CANVAS_WIDTH / 2 - 177, CANVAS_HEIGHT / 2 - 200, 20.f, SELECTCHAR, brush);

	graphics::drawText(CANVAS_WIDTH / 2 - 197, CANVAS_HEIGHT / 2 - 100, 20.f, CHARNICK, brush);

	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	brush.outline_opacity = 0.f;
	loc_brush.fill_color[0] = 1.f;
	loc_brush.fill_color[1] = 1.f;
	loc_brush.fill_color[2] = 1.f;
	loc_brush.fill_opacity = 1.f;
	loc_brush.outline_opacity = 0.f;

	if (place_holder)
	{
		loc_brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_1);
		graphics::setScale(hover[9], hover[9]);
		graphics::drawRect(350, 250, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_1);
		graphics::setScale(hover[10], hover[10]);
		graphics::drawRect(350, 325, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_1);
		graphics::setScale(hover[11], hover[11]);
		graphics::drawRect(350, 400, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_1);
		graphics::setScale(hover[12], hover[12]);
		graphics::drawRect(350, 475, 30, 30, loc_brush);
		graphics::resetPose();
	}
	else
	{
		loc_brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_2);
		graphics::setScale(hover[9], hover[9]);
		graphics::drawRect(350, 250, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_2);
		graphics::setScale(hover[10], hover[10]);
		graphics::drawRect(350, 325, 30, 30, loc_brush);
		graphics::resetPose();
		graphics::setScale(hover[11], hover[11]);
		loc_brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_2);
		graphics::drawRect(350, 400, 30, 30, loc_brush);
		graphics::resetPose();
		graphics::setScale(hover[12], hover[12]);
		loc_brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_2);
		graphics::drawRect(350, 475, 30, 30, loc_brush);
		graphics::resetPose();
	}
	
	brush.fill_color[0] = COLORBLINKY_R;
	brush.fill_color[1] = COLORBLINKY_G;
	brush.fill_color[2] = COLORBLINKY_B;
	graphics::setScale(hover[9], hover[9]);
	graphics::drawText(430, 255, 15.f, BLINKYT, brush);
	graphics::drawText(705, 255, 15.f, BLINKYTN, brush);
	graphics::resetPose();
	brush.fill_color[0] = COLORPINKY_R;
	brush.fill_color[1] = COLORPINKY_G;
	brush.fill_color[2] = COLORPINKY_B;
	graphics::setScale(hover[10], hover[10]);
	graphics::drawText(435, 330, 15.f, PINCKYT, brush);
	graphics::drawText(710, 330, 15.f, PINCKYTN, brush);
	graphics::resetPose();
	brush.fill_color[0] = COLORINKY_R;
	brush.fill_color[1] = COLORINKY_G;
	brush.fill_color[2] = COLORINKY_B;
	graphics::setScale(hover[11], hover[11]);
	graphics::drawText(430, 405, 15.f, INKYT, brush);
	graphics::drawText(712, 405, 15.f, INKYTN, brush);
	graphics::resetPose();
	brush.fill_color[0] = COLORCLYDE_R;
	brush.fill_color[1] = COLORCLYDE_G;
	brush.fill_color[2] = COLORCLYDE_B;
	graphics::setScale(hover[12], hover[12]);
	graphics::drawText(440, 480, 15.f, CLYDET, brush);
	graphics::drawText(710, 480, 15.f, CLYDETN, brush);
	graphics::resetPose();
	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;
}

void Menu::drawGameMInfo()
{
	graphics::setScale(hover[7], hover[7]);
	brush.texture = std::string(ASSET_PATH) + std::string(SINGLEPALYER);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 + 110, 240, 80, brush);
	graphics::resetPose();
	drawX();
	drawB();
	drawFullScreen();
	drawS();
	drawM();

	brush.texture = std::string(ASSET_PATH) + std::string(VERTICALLINE);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT/2 - 90, 1, 275, brush);


	brush.texture = std::string(ASSET_PATH) + std::string(PACMANCHAR);
	graphics::drawRect(217+52, CANVAS_HEIGHT / 2 - 50, 175, 175, brush);
	
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	graphics::drawText(217, 50, 20.f, P1, brush);
	graphics::drawText(WINDOW_WIDTH - 219 - 103, 50, 20.f, P2, brush);
	graphics::drawText(217 + 12, 80, 15.f, PACMANINF, brush);

	if (phantom == BLINKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKYCHAR);
		graphics::drawText(WINDOW_WIDTH - 219 - 103 + 24, 80, 15.f, BLINKYTN, brush);
	}
	else if (phantom == PINKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PINKYCHAR);
		graphics::drawText(WINDOW_WIDTH - 219 - 103 + 24, 80, 15.f, PINCKYTN, brush);
	}
	else if (phantom == INKY)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(INKYCHAR);
		graphics::drawText(WINDOW_WIDTH - 219 - 103 + 24, 80, 15.f, INKYTN, brush);
	}
	else if (phantom == CLYDE)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(CLYDECHAR);
		graphics::drawText(WINDOW_WIDTH - 219 - 103 + 24, 80, 15.f, CLYDETN, brush);
	}

	brush.outline_opacity = 0.f;
	brush.outline_width = 0.f;

	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	graphics::drawRect(WINDOW_WIDTH - 219 - 52, CANVAS_HEIGHT / 2 - 50, 175, 175, brush);

	brush.texture = std::string(ASSET_PATH) + std::string(WASD);
	brush.outline_opacity = 0.5f; //TODO: 2ND PRIORITY CHANGE KEYBOARD SETTINGS (SWITCH PLAYERS FROM KEYS TO WASD)
	graphics::drawRect(120, CANVAS_HEIGHT - 150, 150, 75, brush);
	brush.texture = std::string(ASSET_PATH) + std::string(ARROWS);
	graphics::drawRect(CANVAS_WIDTH - 120, CANVAS_HEIGHT - 150, 150, 75, brush);
	brush.outline_opacity = 0.f;
	
}

void Menu::drawModernScreen()
{
	graphics::Brush brush;
	// ----- Images -----

	// Setting the image brush for background
	brush.texture = std::string(ASSET_PATH) + std::string(BACKGROUND_MENUM);

	// Removing the outline and setting image opacity
	brush.outline_opacity = 0.f;
	brush.fill_opacity = 0.1f;

	// Drawing image for background
	graphics::drawRect(width_to_x(canvas_width, 50.f), height_to_y(canvas_height, 50.f), canvas_width, canvas_height, brush);

	// Resseting hover
	graphics::resetPose();

	drawX();

	drawI();

	drawFullScreen();

	drawM();
	
	drawS();

	brush.fill_opacity = 1.f;

	// Taking out the banner hover
	graphics::setScale(hover[4], hover[4]);

	// Setting the image brush for the banner button
	brush.texture = std::string(ASSET_PATH) + std::string(CLASSIC);

	// Drawing image for banner button
	graphics::drawRect(width_to_x(canvas_width, 67.f), height_to_y(canvas_height, 73.f), 180, 60, brush);

	// Resetting hover
	graphics::resetPose();

	// Taking out the bored hover
	graphics::setScale(hover[5], hover[5]);

	// Setting the image brush for the bored button
	brush.texture = std::string(ASSET_PATH) + std::string(DF);

	// Drawing image for single player button
	graphics::drawRect(width_to_x(canvas_width, 33.f), height_to_y(canvas_height, 73.f), 210, 70, brush);

	// Resetting hover
	graphics::resetPose();

	// Taking out the signle player hover
	graphics::setScale(hover[6], hover[6]);

	// Setting the image brush for the single player
	brush.texture = std::string(ASSET_PATH) + std::string(SINGLEPALYER);

	// Drawing image for single player
	graphics::drawRect(width_to_x(canvas_width, 33.f), height_to_y(canvas_height, 45.f), 240, 80, brush);

	// Resetting hover
	graphics::resetPose();

	// Taking out the multi player
	graphics::setScale(hover[7], hover[7]);

	// Setting the image brush for the multi player
	brush.texture = std::string(ASSET_PATH) + std::string(MULTIPLAYER);

	// Drawing image for multi player
	graphics::drawRect(width_to_x(canvas_width, 67.f), height_to_y(canvas_height, 45.f), 240, 80, brush);

	// Resetting hover
	graphics::resetPose();

	// ----- Title -----

	// Setting the opacity to default
	brush.fill_opacity = 1.f;

	// Setting font to default
	graphics::setFont(std::string(ASSET_PATH) + std::string(FONTM));

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Drawing text for title
	graphics::drawText(width_to_x(canvas_width, 38.f), height_to_y(canvas_height, 25.f), 50.F, std::string(TITLE), brush);

	// ----- Text over button -----

	// Back to clasic
	graphics::drawText(width_to_x(canvas_width, 61.3f), height_to_y(canvas_height, 65.f), 12.F, std::string(BC), brush);

	// Bored
	graphics::drawText(width_to_x(canvas_width, 28.5f), height_to_y(canvas_height, 65.f), 12.F, std::string(BR), brush);

	// Multiplayer
	graphics::drawText(width_to_x(canvas_width, 28.5f), height_to_y(canvas_height, 36.5f), 12.F, std::string(SINGLET), brush);

	// Singleplayer
	graphics::drawText(width_to_x(canvas_width, 63.f), height_to_y(canvas_height, 36.5f), 12.F, std::string(MULTIT), brush);

	// ----- High Score & Score -----

	// Setting color for text score & high score
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Drawing text for score & var
	graphics::drawText(width_to_x(canvas_width, 25.5f), height_to_y(canvas_height, 7.f), 30.F, std::string(SCORE), brush);
	graphics::drawText(width_to_x(canvas_width, 25.5f), height_to_y(canvas_height, 12.f), 25.F, std::to_string(pacman_local_score), brush);

	// Drawing text for high score & var
	graphics::drawText(width_to_x(canvas_width, 65.f), height_to_y(canvas_height, 7.f), 30.F, std::string(HSCORE), brush);
	graphics::drawText(width_to_x(canvas_width, 65.f), height_to_y(canvas_height, 12.f), 25.F, std::to_string(highscore), brush);

	resetBrush();

	time_counter = 0.f;
}

// General draw menu sceen function
void Menu::drawMenuScreen()
{
	if (modern)
	{
		drawModernScreen();
	}
	else
	{
		drawClassicScreen();
	}
}

void Menu::drawClassicWelcome2()
{
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	graphics::drawText(CANVAS_WIDTH / 2 - 166, 50, 25.f, CLASSSTARTTITLE, brush);
	graphics::drawText(CANVAS_WIDTH / 2 - 166 + 85, 70, 20.f, std::to_string(highscore), brush);

	graphics::drawText(200, CANVAS_HEIGHT - 50, 15.f, CREDITS, brush);
	graphics::drawText(300, CANVAS_HEIGHT - 50, 15.f, std::to_string(pacman_local_score), brush);

	brush.fill_color[0] = COLORCLYDEC_R;
	brush.fill_color[1] = COLORCLYDEC_G;
	brush.fill_color[2] = COLORCLYDEC_B;
	graphics::drawText(CANVAS_WIDTH / 2 - 113, CANVAS_HEIGHT / 2, 20.f, PUSHSTART, brush);
	
}

void Menu::drawGameMultiPlayer()
{
	if (lost)
	{
		drawYN(msg);
	}

	drawM();
	drawS();
	drawX();
	drawB();
	drawP();
	drawFullScreen();
	brush.outline_opacity = 0.f;

	if (!lost)
	{
		if (maze)
		{
			maze->draw();
		}

		if (pacman)
		{
			pacman->draw();
		}


		if (enemies[0])
		{
			enemies[0]->draw();
		}

		brush.fill_color[0] = COLORPACKMAN_R;
		brush.fill_color[1] = COLORPACKMAN_G;
		brush.fill_color[2] = COLORPACKMAN_B;

		switch (phantom)
		{
		case(0):
			graphics::drawText(1000, 150, 20.f, "PINKY", brush);
			brush.texture = std::string(ASSET_PATH) + std::string(PINKYCHAR);
			break;
		case(1):
			graphics::drawText(1000, 150, 20.f, "BLINKY", brush);
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKYCHAR);
			break;
		case(2):
			graphics::drawText(1000, 150, 20.f, "INKY", brush);
			brush.texture = std::string(ASSET_PATH) + std::string(INKYCHAR);
			break;
		case(3):
			graphics::drawText(1000, 150, 20.f, "CLYDE", brush);
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDECHAR);
			break;
		}

		graphics::drawText(100, 150, 20.f, PACMANT, brush);
		graphics::drawText(100, 180, 19.f, std::to_string(player_score), brush);
		graphics::drawText(1000, 180, 19.f, std::to_string(phantom_score), brush);

		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;

		graphics::drawRect(1040, 300, 175, 175, brush);
		brush.texture = std::string(ASSET_PATH) + std::string(PACMANCHAR);
		graphics::drawRect(140, 300, 175, 175, brush);

		resetBrush();
	}

}

void Menu::drawYN(std::string txt)
{
	if(txt == "0") graphics::drawText(width_to_x(canvas_width, 36.f), height_to_y(canvas_height, 30.f), 50.f, GAMEOVER, brush);
	else graphics::drawText(width_to_x(canvas_width, 34.f), height_to_y(canvas_height, 30.f), 50.f, txt, brush);

	graphics::drawText(width_to_x(canvas_width, 37.5f), height_to_y(canvas_height, 45.f), 40.f, PLAYAGAIN, brush);

	brush.outline_opacity = 0.f;

	brush.texture = std::string(ASSET_PATH) + std::string(YES);

	graphics::setScale(hover[5], hover[5]);

	graphics::drawRect(width_to_x(canvas_width, 25.f), height_to_y(canvas_height, 65.f), 244, 133, brush);

	graphics::resetPose();

	brush.texture = std::string(ASSET_PATH) + std::string(NO);

	graphics::setScale(hover[6], hover[6]);

	graphics::drawRect(width_to_x(canvas_width, 75.f), height_to_y(canvas_height, 65.f), 244, 133, brush);

	graphics::resetPose();
}


void Menu::drawPong()
{
	if (lost)
	{
		drawYN();
	}

	drawX();
	drawM();
	drawB();
	drawFullScreen();
	drawS();
	drawP();

	if (pong_player && !lost)
	{
		pong_player->draw();
	}

	if (pong_ai && !lost)
	{
		pong_ai->draw();
	}

	if (pong_ball && !lost)
	{
		pong_ball->draw();
	}

	
	if (!lost)
	{
		brush.outline_opacity = 1.f;
		brush.fill_opacity = 0.f;

		brush.fill_color[0] = 0.f;
		brush.fill_color[1] = 0.f;
		brush.fill_color[2] = 0.f;

		graphics::drawRect(width_to_x(canvas_width, 50.f),height_to_y(canvas_height, 50.f), 2, CANVAS_HEIGHT / 2 + 100, brush);
		brush.outline_opacity = 0.f;
		brush.fill_opacity = 1.f;

		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
	}

	graphics::drawText(width_to_x(canvas_width, 15.f), height_to_y(canvas_height, 5.f), 20.f, SCORE, brush);
	graphics::drawText(width_to_x(canvas_width, 15.f), height_to_y(canvas_height, 10.f), 20.f, std::to_string(score_pong), brush);
	graphics::drawText(width_to_x(canvas_width, 77.f), height_to_y(canvas_height, 5.f), 20.f, HISCORE, brush);
	graphics::drawText(width_to_x(canvas_width, 77.f), height_to_y(canvas_height, 10.f), 20.f, std::to_string(highscore_pong), brush);
	
	graphics::drawText(width_to_x(canvas_width, 46.5f), height_to_y(canvas_height, 7.5f), 20.f, "LEVEL " + std::to_string(local_level), brush);

}

void Menu::draw()
{
	if (current_status == STATUS_START)
	{
		drawMenuScreen();
	}
	else if (current_status == STATUS_PLAYINGC)
	{
		drawGameC();
	}
	else if (current_status == STATUS_PLAYINGC2)
	{
		drawClassicWelcome2();
	}
	else if (current_status == STATUS_PLAYINGM)
	{
		drawGameM();
	}
	else if (current_status == STATUS_PLAYINGM_INFO)
	{
		drawGameMInfo();
	}
	else if (current_status == STATUS_PLAYINGB)
	{
		drawGameB();
	}
	else if (current_status == STATUS_PLAYINGCGAME)
	{
		drawClassicGame();
	}
	else if (current_status == STATUS_PLAYINGM_GAME)
	{
		drawGameMultiPlayer();
	}
	else if (current_status == STATUS_PLAYINGPONG)
	{
		drawPong();
	}
}

void Menu::init()
{
	
	cacheImages();
	// Checking music type and playing it if it should play
	if (modern && music_on) graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICM), 1.0f, true, 4000);
	else if (!modern && music_on) graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICC), 1.0F, true, 4000);
	
}

void Menu::cacheImages()
{
	brush.texture = std::string(ASSET_PATH) + std::string(BACKGROUND_MENUM);
	brush.texture = std::string(ASSET_PATH) + std::string(BACKGROUND_MENUC);
	brush.texture = std::string(ASSET_PATH) + std::string(CLOSE);
	brush.texture = std::string(ASSET_PATH) + std::string(INFO);
	brush.texture = std::string(ASSET_PATH) + std::string(MUSIC_ON);
	brush.texture = std::string(ASSET_PATH) + std::string(MUSIC_OFF);
	brush.texture = std::string(ASSET_PATH) + std::string(SOUND_ON);
	brush.texture = std::string(ASSET_PATH) + std::string(SOUND_OFF);
	brush.texture = std::string(ASSET_PATH) + std::string(CLASSIC);
	brush.texture = std::string(ASSET_PATH) + std::string(PAC0);
	brush.texture = std::string(ASSET_PATH) + std::string(DF);
	brush.texture = std::string(ASSET_PATH) + std::string(SINGLEPALYER);
	brush.texture = std::string(ASSET_PATH) + std::string(MULTIPLAYER);
	brush.texture = std::string(ASSET_PATH) + std::string(FULL);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_START);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_1);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_2);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_RIGHT_1);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_RIGHT_2);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_UP_2);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_UP_1);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DOWN_1);
	brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DOWN_2);
	brush.texture = ""; //TODO: Ask if caching should be done to every brush or only once and is for everyone
}

/*Menu::Menu(const Console& console)
	:curr_console(console)
{
	init();
}*/

float Menu::window2CanvasX(float x)
{
	return x * CANVAS_WIDTH / (float)window_width;
}

float Menu::window2CanvasY(float y)
{
	if (window_width >= WINDOW_WIDTH)
	{
		
		return y * CANVAS_HEIGHT / (float)window_height;
		
	}
	else
	{
		return (y * CANVAS_HEIGHT / (float)window_height)*(window_width/window_height);
	}
}


Menu::Menu()
{
	std::ifstream settings;
	settings.open(std::string(ASSET_PATH) + "settings.txt");
	if (settings)
	{
		std::string word;

		while (settings >> word)
		{
			if (word == "MusicOn:")
			{
				settings >> word;
				music_on = stoi(word);
			}
			else if (word == "SoundOn:")
			{
				settings >> word;
				sound_on = stoi(word);
			}
			else if (word == "PongHighScore:")
			{
				settings >> word;
				highscore_pong = stoi(word);
			}
			else if (word == "PacManHighScore:")
			{
				settings >> word;
				highscore = stoi(word);
			}
			else continue;
		}
	}

	settings.close();

}

Menu::~Menu()
{
	std::ofstream settings(std::string(ASSET_PATH) + "settings.txt");

	settings << "MusicOn: " << music_on << std::endl;
	settings << "SoundOn: " << sound_on << std::endl;
	settings << "PongHighScore: " << highscore_pong << std::endl;
	settings << "PacManHighScore: " << highscore << std::endl;

	settings.close();
	
	graphics::stopMusic();
	if (pacman)
	{
		delete pacman;
	}
	graphics::destroyWindow();
}

void Menu::setWindowDimensions(unsigned short int w, unsigned short int h)
{
	window_height = h;
	window_width = w;

	if (((window_width /(float) window_height) == 2.f))
	{
		canvas_height = window_height;
		canvas_width = window_width;
	}
	else if ((window_width == WINDOW_WIDTH && window_height > WINDOW_HEIGHT) || (window_width > WINDOW_WIDTH && window_height == WINDOW_HEIGHT))
	{	
		canvas_width = CANVAS_WIDTH;
		canvas_height = CANVAS_HEIGHT;
	}
	else if ((window_width == WINDOW_WIDTH && window_height < WINDOW_HEIGHT) || (window_width < WINDOW_WIDTH && window_height == WINDOW_HEIGHT))
	{
		
	}
}

bool Menu::checkCollisionPong(float dir)
{
	if (!pong_player || !pong_ai || !pong_ball)
	{
		return false;
	}
	
	Rectangle r1;
	float distX = 0.f, distY = 0.f;
	Disk d1 = pong_ball->getCollisionHull();

	if (dir == 1.f)
	{
		r1 = pong_player->getCollisionHull();
		distX = d1.cx - r1.cx - d1.radius - r1.w / 2.f;
		if (r1.cy > d1.cy)
		{
			distY = r1.cy - r1.h / 2.f - d1.cy - d1.radius;
		}
		else
		{
			distY = d1.cy - r1.cy - r1.h / 2.f - d1.radius;
		}
	}
	else
	{
		r1 = pong_ai->getCollisionHull();
		distX = r1.cx - d1.cx - d1.radius - r1.w / 2.f;
		if (r1.cy > d1.cy)
		{
			distY = r1.cy - r1.h / 2.f - d1.cy - d1.radius;
		}
		else
		{
			distY = d1.cy - r1.cy - r1.h / 2.f - d1.radius;
		}
	}

	if (distX < 0 && distX > -(pong_speed) && distY < 0)
	{
		if (dir == 1.f)
		{
			score_pong += 1;
			local_score += 1;
			if (score_pong > highscore_pong)
			{
				highscore_pong = score_pong;
			}
		}
		pong_ball->setAngle(r1);
		return true;
	}
	return false;
}

bool Menu::checkCollisionPacMan(int num)
{
	float dx, dy, d;
	Disk pacmanD, en1D, en2D, en3D, en4D;

	if (!pacman || !enemies[num])
	{
		return false;
	}

	if (multi)
	{
		
		pacmanD = pacman->getCollisionHull();
		en1D = enemies[0]->getCollisionHull();

		d = sqrt(pow(pacmanD.cx - en1D.cx, 2) + pow(pacmanD.cy - en1D.cy, 2));

		if (d <= pacmanD.radius + en1D.radius)
		{
			return true;
		}	
	}

	if (!multi)
	{
		if (!enemies[num]->getStart())
		{
			pacmanD = pacman->getCollisionHull();
			en1D = enemies[num]->getCollisionHull();

			d = sqrt(pow(pacmanD.cx - en1D.cx, 2) + pow(pacmanD.cy - en1D.cy, 2));

			if (d <= pacmanD.radius + en1D.radius)
			{
				return true;
			}
		}
	}
	return false;
}

bool Menu::checkCollisionPacDot(Pacdot* cur_dot, bool is_pacman)
{
	float d;
	Disk collidElement, pacdotD;

	if (is_pacman)
	{
		if (!pacman || !maze)
		{
			return false;
		}

		collidElement = pacman->getCollisionHull();
	}
	else
	{
		if (!maze || !enemies[0])
		{
			return false;
		}

		collidElement = enemies[0]->getCollisionHull();
	}
	
	pacdotD = cur_dot->getCollisionHull();

	d = sqrt(pow(collidElement.cx - pacdotD.cx, 2) + pow(collidElement.cy - pacdotD.cy, 2));

	if (d <= collidElement.radius + pacdotD.radius)
	{
		return true;
	}
	return false;
}

bool Menu::checkCollisionObstacle(Obstacle* cur_obst, bool is_pacman, int num)
{
	float dx, dy, d, nX, nY, nearestX, nearestY, topR, bottomR, leftR, rightR, distLeft, distRight, distTop, distBottom;
	Disk collidElement;
	Rectangle obstacleR;

	if (is_pacman)
	{
		if (!pacman || !maze)
		{
			return false;
		}

		collidElement = pacman->getCollisionHull();
	}
	else
	{
		if (modern)
		{
			if (!maze || !enemies[num])
			{
				return false;
			}
			collidElement = enemies[num]->getCollisionHull();
		}
		else
		{
			if (!maze || !enemies[num])
			{
				return false;
			}
			collidElement = enemies[num]->getCollisionHull();
		}
	}
	if (modern)
	{
		obstacleR = cur_obst->getCollisionHull();

		nX = obstacleR.cx - obstacleR.w / 2;
		nY = obstacleR.cy - obstacleR.h / 2;

		nearestX = std::max(nX, std::min(collidElement.cx, nX + obstacleR.w));
		nearestY = std::max(nY, std::min(collidElement.cy, nY + obstacleR.h));

		topR = nY - obstacleR.h;
		bottomR = nY + obstacleR.h;
		leftR = nX - obstacleR.w;
		rightR = nX + obstacleR.w;

		distLeft = abs(collidElement.cx + collidElement.radius - (obstacleR.cx - obstacleR.w / 2));
		distRight = abs(collidElement.cx - collidElement.radius - (obstacleR.cx + obstacleR.w / 2));
		distTop = abs(collidElement.cy + collidElement.radius - (obstacleR.cy - obstacleR.h / 2));
		distBottom = abs(collidElement.cy - collidElement.radius - (obstacleR.cy + obstacleR.h / 2));


		dx = collidElement.cx - nearestX;
		dy = collidElement.cy - nearestY;

		if (pow(dx, 2) + pow(dy, 2) < (pow(collidElement.radius, 2)))
		{
			if (!is_pacman)
			{
				if (distTop < distRight && distTop < distBottom && distTop < distLeft)
				{
					if (topR < nearestY && nearestY < obstacleR.cy)
					{
						enemies[num]->movement[3] = false;
						enemies[num]->movement[2] = true;
						enemies[num]->movement[0] = true;
						enemies[num]->movement[1] = true;
					}
				}
				else if (distBottom < distLeft && distBottom < distRight && distBottom < distTop)
				{
					if (bottomR >= nearestY && nearestY >= obstacleR.cy)
					{
						enemies[num]->movement[2] = false;
						enemies[num]->movement[3] = true;
						enemies[num]->movement[0] = true;
						enemies[num]->movement[1] = true;
					}
				}
				else if (distLeft < distBottom && distLeft < distTop && distLeft < distRight)
				{
					if (leftR < nearestX && nearestX < obstacleR.cx)
					{
						enemies[num]->movement[1] = false;
						enemies[num]->movement[0] = true;
						enemies[num]->movement[2] = true;
						enemies[num]->movement[3] = true;
					}
				}
				else if (distRight < distBottom && distRight < distTop && distRight < distLeft)
				{
					if (rightR >= nearestX && nearestX >= obstacleR.cx)
					{
						enemies[num]->movement[0] = false;
						enemies[num]->movement[1] = true;
						enemies[num]->movement[2] = true;
						enemies[num]->movement[3] = true;
					}
				}
			}
			else
			{
				if (distTop < distRight && distTop < distBottom && distTop < distLeft)
				{
					if (topR < nearestY && nearestY < obstacleR.cy)
					{
						pacman->movement[3] = false;
						pacman->movement[2] = true;
						pacman->movement[0] = true;
						pacman->movement[1] = true;
					}
				}
				else if (distBottom < distLeft && distBottom < distRight && distBottom < distTop)
				{
					if (bottomR >= nearestY && nearestY >= obstacleR.cy)
					{
						pacman->movement[2] = false;
						pacman->movement[3] = true;
						pacman->movement[0] = true;
						pacman->movement[1] = true;
					}
				}
				else if (distLeft < distBottom && distLeft < distTop && distLeft < distRight)
				{
					if (leftR < nearestX && nearestX < obstacleR.cx)
					{
						pacman->movement[1] = false;
						pacman->movement[0] = true;
						pacman->movement[2] = true;
						pacman->movement[3] = true;
					}
				}
				else if (distRight < distBottom && distRight < distTop && distRight < distLeft)
				{
					if (rightR >= nearestX && nearestX >= obstacleR.cx)
					{
						pacman->movement[0] = false;
						pacman->movement[1] = true;
						pacman->movement[2] = true;
						pacman->movement[3] = true;
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Menu::resetBrush()
{
	brush.texture = "";
	brush.outline_opacity = 0.f;
	brush.fill_opacity = 1.f;
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;
}