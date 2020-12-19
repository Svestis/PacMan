#include "menu.h"
#include "graphics.h"
#include "config.h"
#include "console.h"
#include <iostream>

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
		//TODO: Add functionality for single player
	}
}

void Menu::updateModernScreen()
{
	// Checking the mouse state
	graphics::getMouseState(mouse);

	// Closing windw on close window click
	if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		delete this; //TODO: Check this
	}
	// Hover effect on close button
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 13) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 13) && (window2CanvasY(mouse.cur_pos_y) >= 14) && (window2CanvasY(mouse.cur_pos_y) <= 43))
	{
		hover[0] = 1.3f;
	}
	// Openning info panel
	else if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 14) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 53 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 25 + 5))
	{
		system(std::string(WEBPAGE).c_str());
	}
	// Hover effect on info button
	else if ((window2CanvasX(mouse.cur_pos_x) >= CANVAS_WIDTH - 30 - 15) &&
		(window2CanvasX(mouse.cur_pos_x) <= CANVAS_WIDTH - 30 + 14) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 53 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 25 + 5))
	{
		hover[1] = 1.3f;
	}
	// Music on/off
	else if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= 485 - 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		music_on = !music_on;
		updateMusic(modern);
	}
	// Hover effect on music on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 - 83) && (window2CanvasX(mouse.cur_pos_x) <= 515 - 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		hover[2] = 1.3f;
	}
	// Sound on/off
	else if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= 485 + 83) &&
		(window2CanvasX(mouse.cur_pos_x) <= 520 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		sound_on = !sound_on; //TODO: Add function to turn sound on off
	}
	// Hover effect on sound on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 485 + 83) && (window2CanvasX(mouse.cur_pos_x) <= 515 + 83) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 50 + 5) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 30 + 5))
	{
		hover[3] = 1.3f;
	}
	// Back to classics
	else if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= 700 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= 700 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		modern = !modern;
		updateMusic(modern);
	}
	// Back to classics hover
	else if ((window2CanvasX(mouse.cur_pos_x) >= 700 - 105) && (window2CanvasX(mouse.cur_pos_x) <= 700 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		hover[4] = 1.3f;
	}
	// Bored
	else if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= 300 - 105) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		//TODO: Add functionality for bored state
	}
	// Bored on/off
	else if ((window2CanvasX(mouse.cur_pos_x) >= 300 - 105) && (window2CanvasX(mouse.cur_pos_x) <= 300 + 105) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT - 150 - 30) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT - 150 + 30))
	{
		hover[5] = 1.1f;
	}
	// Single player
	else if ((mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= 300 - 120) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15) && modern))
	{
		//TODO: Add functionality for single player
	}
	// single player hover
	else if ((window2CanvasX(mouse.cur_pos_x) >= 300 - 120) && (window2CanvasX(mouse.cur_pos_x) <= 300 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15))
	{
		hover[6] = 1.1f;
	}
	// Multi player
	else if (mouse.button_left_released && (window2CanvasX(mouse.cur_pos_x) >= 300 - 120) &&
		(window2CanvasX(mouse.cur_pos_x) <= 300 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15))
	{
		//TODO: Add functionality for MULTI player
	}
	// mulri player hover
	else if ((window2CanvasX(mouse.cur_pos_x) >= 700 - 120) && (window2CanvasX(mouse.cur_pos_x) <= 700 + 120) && (window2CanvasY(mouse.cur_pos_y) >= CANVAS_HEIGHT / 2 - 58) && (window2CanvasY(mouse.cur_pos_y) <= CANVAS_HEIGHT / 2 + 15))
	{
		hover[7] = 1.1f;
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

	// Setting opacity
	brush.fill_opacity = 1.f;

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 2 - 146, CANVAS_HEIGHT / 2, 25.f, std::string(PLAY), brush);

	// Setting opacity
	brush.fill_opacity = 0.5f;

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 4 - 177, CANVAS_HEIGHT / 2 + 90, 25.f, std::string(MUSICT), brush);

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 4 * 3 - 179, CANVAS_HEIGHT / 2 + 90, 25.f, std::string(SOUNDT), brush);

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 2 - 208, CANVAS_HEIGHT / 2 + 140, 25.f, std::string(SWITCH), brush);

	// Setting color for text for classic game mode
	brush.fill_color[0] = COLORRED_R;
	brush.fill_color[1] = COLORRED_G;
	brush.fill_color[2] = COLORRED_B;

	// Drawing text
	graphics::drawText(CANVAS_WIDTH / 2 - 138, CANVAS_HEIGHT / 2 + 190, 25.f, std::string(ESCA), brush);

	// Resetting opacity
	brush.fill_opacity = 1.f;
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

	// Setting opacity to default
	brush.fill_opacity = 1.f;

	// Taking out the close button if hover
	graphics::setScale(hover[0], hover[0]);

	// Setting the image brush for the close button
	brush.texture = std::string(ASSET_PATH) + std::string(CLOSE);

	// Drawing image for close button
	graphics::drawRect(CANVAS_WIDTH - 30, 30, 40, 40, brush);

	// Resseting hover
	graphics::resetPose();

	// Taking out the info button if hover
	graphics::setScale(hover[1], hover[1]);

	// Setting the image brush for the info button
	brush.texture = std::string(ASSET_PATH) + std::string(INFO);

	// Drawing image for info button
	graphics::drawRect(CANVAS_WIDTH - 30, CANVAS_HEIGHT - 35, 40, 40, brush);

	// Resetting hover
	graphics::resetPose();

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

	// Taking out the sound button if hover
	graphics::setScale(hover[3], hover[3]);

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

	// Music
	graphics::drawText(398, CANVAS_HEIGHT - 61, 10.F, std::string(MUSIC), brush);

	// Sound
	graphics::drawText(563, CANVAS_HEIGHT - 61, 10.F, std::string(SOUND), brush);

	// Info
	graphics::drawText(957, CANVAS_HEIGHT - 58, 10.F, std::string(INFOT), brush);

	// Closed
	graphics::drawText(952, 62, 10.F, std::string(CLOSET), brush);

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
	
	drawMenuScreen();
	

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
	// Checking music type and playing it if it should play
	if (modern && music_on) graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICM), 1.0f, true, 4000);
	else if (!modern && music_on) graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICC), 1.0F, true, 4000);
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
		std::cout << y * CANVAS_HEIGHT/ (float)window_height << std::endl;
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
	delete score_ptr;
	delete highscore_ptr;
	graphics::destroyWindow();
}
