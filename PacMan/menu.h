#pragma once

#include "graphics.h"
#include "config.h"
#include "pacman.h"
#include "phantom.h"
#include "pong.h"
#include "pongball.h"
#include "maze.h"

class Menu
{
	typedef enum { STATUS_START, STATUS_PLAYINGM, STATUS_PLAYINGM_INFO, STATUS_PLAYINGM_GAME, STATUS_PLAYINGC, STATUS_PLAYINGCGAME, STATUS_PLAYINGC2, STATUS_PLAYINGB, STATUS_PLAYINGPONG } status;
	status current_status = STATUS_START;
	character phantom;
	std::string msg = "0";
	bool modern = true,
		music_on = true,
		sound_on = true,
		full_screen = false,
		place_holder = false,
		key_down = false,
		lost = false,
		music_wasplaying = true,
		multi = false,
		replay = false;
	unsigned short int score_pong = 0,
		highscore_pong = 0;
	float hover[14] = { 1.f, 1.f, 1.f, 1.f, 1.2f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }; // Hovering for close button, info button, music button, sound button, classic button (or back), bored button (or pong or play again), single player (or arcade or dont play again), multiplayer, full screen, blinky, pinky, inky, clyde, pause
	int score = 0,
		local_score = 0,
		highscore = 0,
		counter = 0,
		player_score = 0,
		phantom_score = 0,
		obst_counter = 0,
		obst_counter_2 = 0,
		obst_counter_3 = 0,
		obst_counter_4 = 0,
		obst_counter_5 = 0,
		pacman_lives = 4,
		pacman_level = 1;
	unsigned short int window_width = WINDOW_WIDTH, 
					   window_height = WINDOW_HEIGHT,
					   canvas_width = CANVAS_WIDTH,
					   canvas_height = CANVAS_HEIGHT,
					   level = 1,
					   local_level = 1;
	double time_counter = 0.f,
		   time_counter_2 = 0.f,
		   pong_speed = 5.f,
		   phantom_speed = 4.f,
		   pacman_speed = 5.f;
	graphics::Brush brush,
					loc_brush;
	graphics::MouseState mouse;
	Phantom* enemies[4] = { nullptr, nullptr, nullptr, nullptr };
	Pong* pong_player = nullptr;
	Pong* pong_ai = nullptr;
	void updateClassicScreen(); // update function for classic menu screen
	void updateModernScreen(); // update function for classic modern screen
	void updateMenuScreen(); // update function for menu in general
	void updateGameC(); // update function for single player state
	void updateGameM(); // update function for multiplayr state
	void updateGameB(); // update function for bored state
	void updateX(); // update function for close button
	void updateB(status s = STATUS_START); // update function for back button
	void updateP();
	void updateI(); // update function for info button
	void updateM(); // update function for music button
	void updateS(); // update function for sound button
	void updateFullScreen(); // update function for full screen
	void updateGameMSelection();
	void updateGameMInfo();
	void updateClassicWelcome();
	void updateClassicWelcome2();
	void updateGameC2();
	void updateModernWelcome();
	void updateClassicGame();
	void updateGameMultiPlayer();
	void updatePong();
	void updateY();
	void updateN(status s);
	void drawMenuScreen(); // drawing menu screen
	void drawModernScreen(); //drawing modern screen
	void drawClassicScreen(); // drawing classic screen
	void drawGameC(); // drawing game for single player state
	void drawGameC2();
	void drawClassicWelcome2();
	void drawModernWelcome();
	void drawPong();
	void drawYN(std::string txt ="0");
	void drawGameM(); // drawing game for multiplayer state
	void drawGameB(); // drawing game for bored state
	void drawM(); // drawing music button
	void drawS(); //drawing sound button
	void drawGameMSelection(); // Draw selection screen of multiplayer
	void drawGameMInfo(); // Draw pre-game multiplayer screen
	void drawClassicWelcome(); // Draws welcome screen of classic game mode
	void drawClassicGame();
	void drawP();
	void drawX(); // close button
	void drawI(); // info button
	void drawB(); // back button
	void drawFullScreen(); // full screen button
	void drawGameMultiPlayer();
	void cacheImages(); // Caching images
	bool checkCollisionPacMan(int num=0);
	bool checkCollisionPacDot(Pacdot* cur_dot, bool is_pacman);
	bool checkCollisionObstacle(Obstacle* cur_obst, bool is_pacman, int num=0);
	void resetBrush();
public:
	Maze* maze = nullptr;
	PongBall* pong_ball = nullptr;
	PacMan* pacman = nullptr;
	bool paused = false;
	void update();
	void draw();
	void init();
	bool playSound() const { return sound_on; };
	void updateMusic(bool musictype);
	bool getFullScreen() { return full_screen; };
	void setWindowDimensions(unsigned short int w, unsigned short int h);
	unsigned short int getWindowWidth() { return window_width; };
	unsigned short int getWindowHeight() { return window_height; };
	float window2CanvasX(float x);
	float window2CanvasY(float y);
	bool checkCollisionPong(float dir);
	unsigned short int getPongLevel() const { return level; };
	double getPongSpeed() const { return pong_speed; };
	bool getModern() const { return modern; };
	bool getMulti() const { return multi; };
	character getPhantom() const { return phantom; };
	Menu();
	~Menu();
};
