#include "menu.h"
#include "graphics.h"
#include "config.h"
#include <iostream>


void Menu::updateM()
{
	graphics::getMouseState(mouse);
	if (mouse.button_left_released)
	{
		music_on = !music_on;
		updateMusic(modern);
	}
	else
	{
		hover[2] = 1.3f;
	}
}

void Menu::updateS()
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		sound_on = !sound_on; //TODO: Add function to turn sound on off
	}
	else
	{
		hover[3] = 1.3f;
	}
}

void Menu::updateB(status s)
{
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		current_status = s;
	}
	else
	{
		hover[4] = 1.3f;
	}
}

void Menu::updateX()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		delete this;
	}
	else
	{
	
		hover[0] = 1.3f;
	}
}

void Menu::updateI()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	if (mouse.button_left_released)
	{
		system(std::string(WEBPAGE).c_str());
	}
	else
	{
		hover[1] = 1.3f;
	}
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
	else
	{
		hover[8] = 1.2f;
	}
}

void Menu::updateClassicScreen()
{
	// Closing windw on escape
	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		delete this; //TODO: Check this
	}
	// Music on/off
	else if (graphics::getKeyState(graphics::SCANCODE_M))
	{
		music_on = !music_on;
		updateMusic(modern);
	}
	// Sound on/off
	else if (graphics::getKeyState(graphics::SCANCODE_N))
	{
		sound_on = !sound_on; //TODO: Add function to turn sound on off
	}
	// Back to classics
	else if (graphics::getKeyState(graphics::SCANCODE_LSHIFT))
	{
		modern = !modern;
		updateMusic(modern);
	}
	// Single player
	else if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		current_status = STATUS_PLAYINGC;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RSHIFT))
	{
		full_screen = !full_screen;
		graphics::setFullScreen(full_screen);
	}
}

void Menu::updateModernScreen()
{
	// Checking the mouse state
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
	// Back to classics
	else if ((window2CanvasX(mouse.cur_pos_x) >= 700 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		if (mouse.button_left_released)
		{
			modern = !modern;
			updateMusic(modern);
		}
		else
		{
			hover[4] = 1.3f;
		}
	}
	// Bored
	else if ((window2CanvasX(mouse.cur_pos_x) >= 300 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		if (mouse.button_left_released)
		{
			current_status = STATUS_PLAYINGB;
		}
		else
		{
			hover[5] = 1.1f;
		}
	}
	// Single player
	else if ((window2CanvasX(mouse.cur_pos_x) >= 300 - 120) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15))
	{
		if (mouse.button_left_released)
		{
			current_status = STATUS_PLAYINGC;
		}
		else
		{
			hover[6] = 1.1f;
		}
	}
	// Multi player
	else if (window2CanvasX(mouse.cur_pos_x) >= 580 &&
		window2CanvasX(mouse.cur_pos_x) <= 815 && window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58 && window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15)
	{
		if (mouse.button_left_released)
		{
			current_status = STATUS_PLAYINGM;
		}
		else
		{
			hover[7] = 1.1f;
		}
	}
	// full screen
	else if ((window2CanvasX(mouse.cur_pos_x) >= 25) && (window2CanvasX(mouse.cur_pos_x) <= 55) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 45) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 20))
	{
		updateFullScreen();
	}
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
	if (modern)
	{
		updateModernScreen();
	}
	else
	{
		updateClassicScreen();
	}
}

void Menu::updateClassicWelcome()
{
	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		delete this; // TODO: check this one
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		graphics::stopMusic(1000);
		current_status = STATUS_PLAYINGCGAME;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_B))
	{
		current_status = STATUS_START;
	}
}

void Menu::updateClassicGame()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		std::cout << "HI";
	}
	if (!pacman)
	{
		pacman = new PacMan();
	}

	if (pacman)
	{
		pacman->update();
	}
}


void Menu::updateGameC()
{
	if (modern)
	{
		// TODO: update screen for moderng single player
	}
	else
	{
		if (current_status == STATUS_PLAYINGC)
		{
			updateClassicWelcome();
		}
		else if (current_status == STATUS_PLAYINGCGAME)
		{
			updateClassicGame();
		}
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
			hover[2] = 1.1f;
		}
	}
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH / 4 - 100) && (window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH / 4 + 100)
		&& (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 100) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 100))

	{
		if (mouse.button_left_released)
		{
			// TODO: Add pong game
		}
		else
		{
			hover[3] = 1.1f;
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

void Menu::update()
{
	if (current_status == STATUS_START) 
	{
		updateMenuScreen();
	}
	else if (current_status == STATUS_PLAYINGC || current_status == STATUS_PLAYINGCGAME)
	{
		updateGameC();
	}
	else if (current_status == STATUS_PLAYINGM)
	{
		updateGameM();
	}
	else if (current_status == STATUS_PLAYINGM_INFO)
	{
		updateGameMInfo();
	}
	else if (current_status == STATUS_PLAYINGB)
	{
		updateGameB();
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
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 600, CANVAS_HEIGHT, brush);

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
	graphics::drawText(CANVAS_WIDTH / 2 - 135, 150, 50.F, std::string(TITLE), brush);

	// ----- High Score & Score -----

	// Setting color for text for classic game mode
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Setting font for classic game mode
	//graphics::setFont(std::string(ASSET_PATH) + std::string(FONTC)); 
	// TODO: Check why font is not working on change

	// Drawing text
	graphics::drawText(250, 50, 30.F, std::string(SCORE), brush);
	graphics::drawText(250, 80, 25.F, std::to_string(score), brush);

	// Drawing text
	graphics::drawText(CANVAS_WIDTH - 250 - 104, 50, 30.f, std::string(HSCORE), brush);
	graphics::drawText(CANVAS_WIDTH - 250 - 104, 80, 25.f, std::to_string(highscore), brush);

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
	graphics::drawText(CANVAS_WIDTH / 2 - 146, CANVAS_HEIGHT / 2, 25.f, std::string(PLAY), loc_brush);

	brush.fill_opacity = .5f;
	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 4 - 177, CANVAS_HEIGHT / 2 + 90, 25.f, std::string(MUSICT), brush);

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 4 * 3 - 179, CANVAS_HEIGHT / 2 + 90, 25.f, std::string(SOUNDT), brush);

	// Drawing text
	graphics::drawText(25, CANVAS_HEIGHT / 2 + 140, 25.f, std::string(SWITCH), brush);

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 2 + 45, CANVAS_HEIGHT / 2 + 140, 25.f, std::string(FULLSCREEN), brush);

	// Setting color for text for classic game mode
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 2 - 138, CANVAS_HEIGHT / 2 + 190, 25.f, std::string(ESCA), brush);

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
	graphics::drawRect(CANVAS_WIDTH - 30, 30, 40, 40, brush);

	brush.outline_opacity = 1.f;

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Closed
	graphics::drawText(952, 62, 10.F, std::string(CLOSET), brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;
}

void Menu::drawI()
{
	brush.outline_opacity = 0.f;

	// Taking out the info button if hover
	graphics::setScale(hover[1], hover[1]);

	// Setting the image brush for the info button
	brush.texture = std::string(ASSET_PATH) + std::string(INFO);

	// Drawing image for info button
	graphics::drawRect(CANVAS_WIDTH - 30, CANVAS_HEIGHT - 35, 40, 40, brush);

	// Resetting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Info
	graphics::drawText(957, CANVAS_HEIGHT - 58, 10.F, std::string(INFOT), brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	brush.outline_opacity = 1.f;
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
	graphics::drawRect(40, CANVAS_HEIGHT - 32, 38, 38, brush);

	// Resetting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Full screen
	graphics::drawText(7, WINDOW_HEIGHT - 55, 10.F, std::string(FULLT), brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	brush.outline_opacity = 1.f;
}

void Menu::drawB()
{
	brush.outline_opacity = 0.f;

	// Taking out the close button if hover
	graphics::setScale(hover[4], hover[4]);

	// Setting the image brush for the close button
	brush.texture = std::string(ASSET_PATH) + std::string(BACK);

	// Drawing image for close button
	graphics::drawRect(40, 30, 40, 40, brush);

	brush.outline_opacity = 1.f;

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Closed
	graphics::drawText(26, 62, 10.F, std::string(BACKT), brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;
}

void Menu::drawClassicWelcome()
{
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
		graphics::drawText(300, CANVAS_HEIGHT - 50, 15.f, std::to_string(score), brush);
	}
	if (time_counter > 1000)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_1);
		graphics::drawRect(280, 190-25, 30, 30, brush);
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
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_1);
		graphics::drawRect(280, 230-25, 30, 30, brush);
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
		brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_1);
		graphics::drawRect(280, 270-25, 30, 30, brush);
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
		brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_1);
		graphics::drawRect(280, 310-25, 30, 30, brush);
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
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_C);
		graphics::drawRect(400, 350, 10, 10, brush);
		graphics::drawRect(400, 380, 25, 25, brush);
		graphics::drawText(520, 357, 13.f, "PTS", brush);
		graphics::drawText(520, 389, 13.f, "PTS", brush);
		graphics::drawText(490, 357, 17.f, "10", brush);
		graphics::drawText(490, 389, 17.f, "50", brush);
	}
	if (time_counter > 15000)
	{
		time_counter = 0.f;
	}
}


void Menu::drawClassicGame()
{
	if (pacman)
	{
		pacman->draw();
	}
}

void Menu::drawGameC()
{
	if (modern)
	{

	}
	// TODO: Seperate classic game from modern game for single player

	else 
	{
		if (current_status == STATUS_PLAYINGC) 
		{
			drawClassicWelcome();
		}
		else if (current_status == STATUS_PLAYINGCGAME)
		{
			drawClassicGame();
		}
		
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

	graphics::setScale(hover[2], hover[2]);

	graphics::drawRect(CANVAS_WIDTH / 4 + CANVAS_WIDTH /2 , CANVAS_HEIGHT / 2, 200, 200, brush);

	graphics::resetPose();

	brush.texture = std::string(ASSET_PATH) + std::string(BOREDPONG);

	brush.outline_opacity = 1.f;

	graphics::setScale(hover[3], hover[3]);

	graphics::drawRect(CANVAS_WIDTH / 4 , CANVAS_HEIGHT / 2, 200, 200, brush);

	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	graphics::drawText(CANVAS_WIDTH / 4 + CANVAS_WIDTH/2 - 65, CANVAS_HEIGHT / 2 - 115, 10.f, BOREDT, brush);

	graphics::drawText(CANVAS_WIDTH / 4 - 100 + 104 - 15, CANVAS_HEIGHT / 2 - 115, 10.f, PONG, brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;

	drawX();

	drawI();

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
	graphics::drawRect(500 - 83, CANVAS_HEIGHT - 35, 40, 40, brush);

	// Resseting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Music
	graphics::drawText(398, CANVAS_HEIGHT - 61, 10.F, std::string(MUSIC), brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;
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
	graphics::drawRect(500 + 83, CANVAS_HEIGHT - 35, 40, 40, brush);

	// Resetting hover
	graphics::resetPose();

	// Setting color to defaults for txt
	brush.fill_color[0] = COLORPACKMAN_R;
	brush.fill_color[1] = COLORPACKMAN_G;
	brush.fill_color[2] = COLORPACKMAN_B;

	// Sound
	graphics::drawText(563, CANVAS_HEIGHT - 61, 10.F, std::string(SOUND), brush);

	// Setting color to defaults for txt
	brush.fill_color[0] = 1.f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 1.f;
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
	loc_brush.outline_opacity = 0.f;

	if (place_holder)
	{
		loc_brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_1);
		graphics::setScale(hover[9], hover[9]);
		graphics::drawRect(250, 180, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_1);
		graphics::setScale(hover[10], hover[10]);
		graphics::drawRect(250, 255, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_1);
		graphics::setScale(hover[11], hover[11]);
		graphics::drawRect(250, 330, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_1);
		graphics::setScale(hover[12], hover[12]);
		graphics::drawRect(250, 405, 30, 30, loc_brush);
		graphics::resetPose();
	}
	else
	{
		loc_brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_2);
		graphics::setScale(hover[9], hover[9]);
		graphics::drawRect(250, 180, 30, 30, loc_brush);
		graphics::resetPose();
		loc_brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_2);
		graphics::setScale(hover[10], hover[10]);
		graphics::drawRect(250, 255, 30, 30, loc_brush);
		graphics::resetPose();
		graphics::setScale(hover[11], hover[11]);
		loc_brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_2);
		graphics::drawRect(250, 330, 30, 30, loc_brush);
		graphics::resetPose();
		graphics::setScale(hover[12], hover[12]);
		loc_brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_2);
		graphics::drawRect(250, 405, 30, 30, loc_brush);
		graphics::resetPose();
	}
	
	brush.fill_color[0] = COLORBLINKY_R;
	brush.fill_color[1] = COLORBLINKY_G;
	brush.fill_color[2] = COLORBLINKY_B;
	graphics::setScale(hover[9], hover[9]);
	graphics::drawText(330, 185, 15.f, BLINKYT, brush);
	graphics::drawText(605, 185, 15.f, BLINKYTN, brush);
	graphics::resetPose();
	brush.fill_color[0] = COLORPINKY_R;
	brush.fill_color[1] = COLORPINKY_G;
	brush.fill_color[2] = COLORPINKY_B;
	graphics::setScale(hover[10], hover[10]);
	graphics::drawText(335, 260, 15.f, PINCKYT, brush);
	graphics::drawText(610, 260, 15.f, PINCKYTN, brush);
	graphics::resetPose();
	brush.fill_color[0] = COLORINKY_R;
	brush.fill_color[1] = COLORINKY_G;
	brush.fill_color[2] = COLORINKY_B;
	graphics::setScale(hover[11], hover[11]);
	graphics::drawText(330, 335, 15.f, INKYT, brush);
	graphics::drawText(612, 335, 15.f, INKYTN, brush);
	graphics::resetPose();
	brush.fill_color[0] = COLORCLYDE_R;
	brush.fill_color[1] = COLORCLYDE_G;
	brush.fill_color[2] = COLORCLYDE_B;
	graphics::setScale(hover[12], hover[12]);
	graphics::drawText(340, 410, 15.f, CLYDET, brush);
	graphics::drawText(610, 410, 15.f, CLYDETN, brush);
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
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 600, CANVAS_HEIGHT, brush);

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
	graphics::drawRect(700, CANVAS_HEIGHT - 150, 180, 60, brush);

	// Resetting hover
	graphics::resetPose();

	// Taking out the bored hover
	graphics::setScale(hover[5], hover[5]);

	// Setting the image brush for the bored button
	brush.texture = std::string(ASSET_PATH) + std::string(DF);

	// Drawing image for single player button
	graphics::drawRect(300, CANVAS_HEIGHT - 150, 210, 70, brush);

	// Resetting hover
	graphics::resetPose();

	// Taking out the signle player hover
	graphics::setScale(hover[6], hover[6]);

	// Setting the image brush for the single player
	brush.texture = std::string(ASSET_PATH) + std::string(SINGLEPALYER);

	// Drawing image for single player
	graphics::drawRect(300, CANVAS_HEIGHT / 2 - 25, 240, 80, brush);

	// Resetting hover
	graphics::resetPose();

	// Taking out the multi player
	graphics::setScale(hover[7], hover[7]);

	// Setting the image brush for the multi player
	brush.texture = std::string(ASSET_PATH) + std::string(MULTIPLAYER);

	// Drawing image for multi player
	graphics::drawRect(700, CANVAS_HEIGHT / 2 - 25, 240, 80, brush);

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
	graphics::drawText(CANVAS_WIDTH / 2 - 145, 150, 50.F, std::string(TITLE), brush);

	// ----- Text over button -----

	// Back to clasic
	graphics::drawText(635, CANVAS_HEIGHT - 195, 12.F, std::string(BC), brush);

	// Bored
	graphics::drawText(245, CANVAS_HEIGHT - 195, 12.F, std::string(BR), brush);

	// Multiplayer
	graphics::drawText(255, WINDOW_HEIGHT / 2 - 65, 10.F, std::string(SINGLET), brush);

	// Singleplayer
	graphics::drawText(650, WINDOW_HEIGHT / 2 - 65, 10.F, std::string(MULTIT), brush);

	// ----- High Score & Score -----

	// Setting color for text score & high score
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Drawing text for score & var
	graphics::drawText(250, 50, 30.F, std::string(SCORE), brush);
	graphics::drawText(250, 80, 25.F, std::to_string(score), brush);

	// Drawing text for high score & var
	graphics::drawText(CANVAS_WIDTH - 250 - 117, 50, 30.F, std::string(HSCORE), brush);
	graphics::drawText(CANVAS_WIDTH - 250 - 117, 80, 25.F, std::to_string(highscore), brush);

	// Creating the info box

	// Resetting the box image
	brush.texture = "";

	// Setting opacity
	brush.fill_opacity = 0.9f;

	// Resetting the box color
	brush.fill_color[0] = 0.f;
	brush.fill_color[1] = 0.f;
	brush.fill_color[2] = 0.f;

	// Resetting the opacity
	brush.fill_opacity = 1.f;
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

void Menu::draw()
{
	if (current_status == STATUS_START)
	{
		drawMenuScreen();
	}
	else if (current_status == STATUS_PLAYINGC || current_status == STATUS_PLAYINGCGAME)
	{
		drawGameC();
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

	if (debug) {
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;
		graphics::MouseState ms;
		graphics::getMouseState(ms);
		graphics::drawDisk(window2CanvasX(ms.cur_pos_x), window2CanvasY(ms.cur_pos_y), 10, brush);
		graphics::drawDisk(CANVAS_WIDTH, CANVAS_HEIGHT, 5, brush);
		graphics::drawDisk(0, 0, 5, brush);
		graphics::drawDisk(0, CANVAS_HEIGHT, 5, brush);
		graphics::drawDisk(CANVAS_WIDTH, 0, 5, brush);
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
}

Menu::~Menu()
{
	graphics::stopMusic();
	if (pacman)
	{
		delete pacman;
	}
	delete score_ptr;
	delete highscore_ptr;
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
		std::cout << "first: width " << canvas_width << " height " << canvas_height << "--------------------- width " << window_width << " height " << window_height << std::endl;
	}
	else if ((window_width == WINDOW_WIDTH && window_height > WINDOW_HEIGHT) || (window_width > WINDOW_WIDTH && window_height == WINDOW_HEIGHT))
	{	
		canvas_width = CANVAS_WIDTH;
		canvas_height = CANVAS_HEIGHT;
		std::cout << "second: width " << canvas_width << " height " << canvas_height << "--------------------- width " << window_width << " height " << window_height << std::endl;
	}
	else if ((window_width == WINDOW_WIDTH && window_height < WINDOW_HEIGHT) || (window_width < WINDOW_WIDTH && window_height == WINDOW_HEIGHT))
	{
		
	}
	
}
