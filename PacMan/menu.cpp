#include "menu.h"
#include "graphics.h"
#include "config.h"
#include "console.h"

// Chaning music
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
	// Checking the mouse state
	graphics::getMouseState(mouse);

	// Closing winthod on close window click
	if (mouse.button_left_released && (mouse.cur_pos_x >= CANVAS_WIDTH - 30 - 13) && 
		(mouse.cur_pos_x <= CANVAS_WIDTH -30 + 13) && (mouse.cur_pos_y >= 14) && (mouse.cur_pos_y <= 43) && modern) 
	{
		Menu::~Menu();
	}
	// Hover effect on close button
	else if ((mouse.cur_pos_x >= CANVAS_WIDTH - 30 - 13) &&
		(mouse.cur_pos_x <= CANVAS_WIDTH - 30 + 13) && (mouse.cur_pos_y >= 14) && (mouse.cur_pos_y <= 43) && modern)
	{
		hover_c = 1.5f;
	}
	// Openning info panel
	else if (mouse.button_left_released && (mouse.cur_pos_x >= CANVAS_WIDTH - 30 - 15) &&
		(mouse.cur_pos_x <= CANVAS_WIDTH - 30 + 14) && (mouse.cur_pos_y >= CANVAS_HEIGHT - 53) && (mouse.cur_pos_y <= CANVAS_HEIGHT - 25) && modern)
	{
		// TODO: Add screen /rectangle over all for info
	}
	// Hover effect on info button
	else if ((mouse.cur_pos_x >= CANVAS_WIDTH - 30 - 15) &&
		(mouse.cur_pos_x <= CANVAS_WIDTH - 30 + 14) && (mouse.cur_pos_y >= CANVAS_HEIGHT - 53) && (mouse.cur_pos_y <= CANVAS_HEIGHT - 25) && modern)
	{
		hover_i = 1.5f;
	}
	// Openning info panel
	else if (mouse.button_left_released && (mouse.cur_pos_x >= 485-83) &&
		(mouse.cur_pos_x <= 520-83) && (mouse.cur_pos_y >= CANVAS_HEIGHT - 50) && (mouse.cur_pos_y <= CANVAS_HEIGHT - 30) && modern)
	{
		music_on = !music_on;
		updateMusic(modern);
	}
	// Hover effect on info button
	else if ((mouse.cur_pos_x >= 485-83) &&  (mouse.cur_pos_x <= 515-83) && (mouse.cur_pos_y >= CANVAS_HEIGHT - 50) && (mouse.cur_pos_y <= CANVAS_HEIGHT - 30) && modern)
	{
		hover_m = 1.5f;
	}
	else
	{
		hover_c = 1.f;
		hover_i = 1.f;
		hover_m = 1.f;
	}
	// Chaning modern flag according to mousclick
	// TODO: Change it for button click for modern or classic
	
	if (graphics::getKeyState(graphics::SCANCODE_LSHIFT))
	{
		modern = !modern;
		updateMusic(modern);
	}
	else if (graphics::getKeyState(graphics::SCANCODE_M))
	{
		music_on = !music_on;
		updateMusic(modern);
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		sound_on = !sound_on;
	}
}

void Menu::draw()
{
	// Moderng game mode
	if (modern) {
		
		// ----- Images -----

		// Setting the image brush for background
		brush.texture = std::string(ASSET_PATH) + std::string(BACKGROUND_MENUM);

		// Removing the outline and setting image opacity
		brush.outline_opacity = 0.f;
		brush.fill_opacity = 0.1f;
		
		// Setting color to defaults
		brush.fill_color[0] = 1.f;
		brush.fill_color[1] = 1.f;
		brush.fill_color[2] = 1.f;

		// Drawing image for background
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 600, CANVAS_HEIGHT, brush);

		// Setting opacity to default
		brush.fill_opacity = 1.f;

		// Taking out the close button if hover
		graphics::setScale(hover_c, hover_c);

		// Setting the image brush for the close button
		brush.texture = std::string(ASSET_PATH) + std::string(CLOSE);

		// Drawing image for close button
		graphics::drawRect(CANVAS_WIDTH - 30, 30, 40, 40, brush);

		// Resseting hover
		graphics::resetPose();

		// Taking out the info button if hover
		graphics::setScale(hover_i, hover_i);

		// Setting the image brush for the info button
		brush.texture = std::string(ASSET_PATH) + std::string(INFO);

		// Drawing image for close button
		graphics::drawRect(CANVAS_WIDTH - 30, CANVAS_HEIGHT - 40, 40, 40, brush);

		// Resetting hover
		graphics::resetPose();

		// Taking out the close button if hover
		graphics::setScale(hover_m, hover_m);

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
		graphics::drawRect(500-83, CANVAS_HEIGHT - 40, 40, 40, brush);

		// Resseting hover
		graphics::resetPose();

		// Taking out the close button if hover
		graphics::setScale(hover_m, hover_m);

		if (!sound_on)
		{
			// Setting the image brush for the music off button
			brush.texture = std::string(ASSET_PATH) + std::string(MUSIC_OFF);
		}
		else
		{
			// Setting the image brush for the music on button
			brush.texture = std::string(ASSET_PATH) + std::string(SOUND_ON);
		}

		// Drawing image for sound button
		graphics::drawRect(500 + 83, CANVAS_HEIGHT - 40, 40, 40, brush);

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
	}
	// Classic game mode
	else {

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
		graphics::drawText(CANVAS_WIDTH - 250 - 104 , 50, 30.F, std::string(HSCORE), brush);
		graphics::drawText(CANVAS_WIDTH - 250 - 104, 80, 25.F, std::to_string(highscore), brush);
	}	
}

void Menu::init()
{
	// Checking music type and playing it if it should play
	if (modern && music_on) graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICM), 1.0f, true, 4000);
	else if (!modern && music_on) graphics::playMusic(std::string(ASSET_PATH) + std::string(WELCOME_MUSICC), 1.0F, true, 4000);
}

Menu::Menu(const Console& console)
	:curr_console(console)
{
	init();
}

Menu::~Menu()
{
	graphics::destroyWindow();
	//  TODO: Add destructor of console class here to delete also ref to object
}
