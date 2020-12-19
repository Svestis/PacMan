#pragma once

#include "graphics.h"
#include "config.h"

class Menu
{
	typedef enum { STATUS_START, STATUS_PLAYINGM, STATUS_PLAYINGC, STATUS_PLAYINGB } status;
	status current_status = STATUS_START;
	bool modern = true, 
		 music_on = true, 
		 sound_on = true, 
		 debug = true,
		 full_sreen = false;
	float hover[8] = {1.f, 1.f, 1.f, 1.f, 1.2f, 1.f, 1.f, 1.f}; // Hovering for close button, info button, music button, sound button, classic button, bored button, single player & multiplayer
	int score = 0, 
		highscore = 0;
	unsigned short int window_width = WINDOW_WIDTH, 
					   window_height = WINDOW_HEIGHT;
	int* score_ptr = &score;
	int* highscore_ptr = &highscore;
	graphics::Brush brush;
	graphics::MouseState mouse;
	void updateClassicScreen();
	void updateModernScreen();
	void updateMenuScreen();
	void drawMenuScreen();
	void drawModernScreen();
	void drawClassicScreen();
public:
	void update();
	void draw();
	void init();
	void updateMusic(bool musictype);
	bool getFullScreen() { return full_sreen; };
	void setWindowDimensions(unsigned short int w, unsigned short int h) { window_width = w; window_height = h; };
	unsigned short int getWindowWidth() { return window_width; };
	unsigned short int getWindowHeight() { return window_height; };
	float window2CanvasX(float x);
	float window2CanvasY(float y);
	//Menu(const class Console & console);
	Menu();
	~Menu();
};
