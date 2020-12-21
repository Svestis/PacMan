#pragma once

#include "graphics.h"
#include "config.h"
#include "pacman.h"

class Menu
{
	typedef enum { STATUS_START, STATUS_PLAYINGM, STATUS_PLAYINGM_INFO, STATUS_PLAYINGM_GAME, STATUS_PLAYINGC, STATUS_PLAYINGCGAME, STATUS_PLAYINGB } status;
	typedef enum { PINKY, BLINKY, INKY, CLYDE} multiplayer_phantom;
	status current_status = STATUS_START;
	multiplayer_phantom phantom;
	bool modern = true, 
		 music_on = true, 
		 sound_on = true, 
		 debug = false,
		 full_screen = false,
		 place_holder = false;
	float hover[13] = { 1.f, 1.f, 1.f, 1.f, 1.2f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }; // Hovering for close button, info button, music button (or arcade), sound button (or pong), classic button (or back), bored button, single player, multiplayer, full screen, blinky, pinky, inky, clyde
	int score = 0, 
		highscore = 0;
	unsigned short int window_width = WINDOW_WIDTH, 
					   window_height = WINDOW_HEIGHT,
					   canvas_width = CANVAS_WIDTH,
					   canvas_height = CANVAS_HEIGHT;
	double time_counter = 0.f;
	int* score_ptr = &score;
	int* highscore_ptr = &highscore;
	graphics::Brush brush,
					loc_brush;
	graphics::MouseState mouse;
	PacMan* pacman = nullptr;
	void updateClassicScreen(); // update function for classic menu screen
	void updateModernScreen(); // update function for classic modern screen
	void updateMenuScreen(); // update function for menu in general
	void updateGameC(); // update function for single player state
	void updateGameM(); // update function for multiplayr state
	void updateGameB(); // update function for bored state
	void updateX(); // update function for close button
	void updateB(status s = STATUS_START); // update function for back button
	void updateI(); // update function for info button
	void updateM(); // update function for music button
	void updateS(); // update function for sound button
	void updateFullScreen(); // update function for full screen
	void updateGameMSelection();
	void updateGameMInfo();
	void updateClassicWelcome();
	void updateClassicGame();
	void drawMenuScreen(); // drawing menu screen
	void drawModernScreen(); //drawing modern screen
	void drawClassicScreen(); // drawing classic screen
	void drawGameC(); // drawing game for single player state
	void drawGameM(); // drawing game for multiplayer state
	void drawGameB(); // drawing game for bored state
	void drawM(); // drawing music button
	void drawS(); //drawing sound button
	void drawGameMSelection(); // Draw selection screen of multiplayer
	void drawGameMInfo(); // Draw pre-game multiplayer screen
	void drawClassicWelcome(); // Draws welcome screen of classic game mode
	void drawClassicGame();
	void drawX(); // close button
	void drawI(); // info button
	void drawB(); // back button
	void drawFullScreen(); // full screen button
	void cacheImages(); // Caching images
public:
	void update();
	void draw();
	void init();
	void updateMusic(bool musictype);
	bool getFullScreen() { return full_screen; };
	void setWindowDimensions(unsigned short int w, unsigned short int h);
	unsigned short int getWindowWidth() { return window_width; };
	unsigned short int getWindowHeight() { return window_height; };
	float window2CanvasX(float x);
	float window2CanvasY(float y);
	//Menu(const class Console & console);
	Menu();
	~Menu();
};
