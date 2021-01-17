/**
* FILE: menu.h 
* TITLE: menu
*
* PURPOSE:
*
* This is the class for the menu, handling all the gameplay
*
* CLASS:
* Menu
*
*	FUNCTIONS:
*
*	updateClassicScreen
*		function to update the menu screen on classic gamemode
*
*	updateModernScreen
*		function to update the modern screen on modern game mode
*
*	updateMenuScreen
*		general function to update menu screen
*
*	updateGameC
*		update function for classig game play
*
*	updateGameM
*		update function for multiplayer game play
*	 
*	updateGameB
*		update function for bored state
*
*	updateGameX
*		update function for x button
*
*	updateB
*		update function for back button
*	
*	updateP
*		update function for paused button
*
*	updateI
*		update function for info button
* 
*	updateM 
*		update function for music button
*
*	updateS
*		update function for sound button
*
*	updateFullScreen
*		update function for full screen button
*
*	updateGameMSelection
*		update function for player selection on multiplayer
*
*	updateGameMInfo 
*		update function for selected player information
*
*	updateClassicWelcome
*		updating classic welcome screen
*
*	updateClassicWelcome2
*		updating second classic welcome screen
*
*	updateModernWelcome 
*		updating modern welcome screen
*
*	updateClassicGame 
*		update classic game general function
*
*	updateGameMultiPlayer 
*		update multiplayer game
*
*	updatePong
*		update pong game
*
*	updateY 
*		update yes button after losing
*
*	updateN(status s) 
*		update no button after losing
*
*	drawMenuScreen 
*		general draw for menu
*
*	drawModernScreen 
*		drawing modern menu
*
*	drawClassicScreen 
*		drawing classic menu
*
*	drawGameC 
*		general drawing for classic game
*
*	drawClassicWelcome2 
*		drawing classic welcome screen
*
*	drawModernWelcome 
*		drawing modern welcome screen
*
*	drawPong 
*		drawing pong game
*
*	drawYN(std::string txt ="0") 
*		drawing yes/no message
*
*	drawGameM 
*		general drawing for modern game
*
*	drawGameB 
*		general drawing for bored state
*
*	drawM 
*		drawing music button
*
*	drawS 
*		drawing sound button
*
*	drawGameMSelection 
*		drawing player selection
*
*	drawGameMInfo 
*		drawing selected plaer info
*
*	drawClassicWelcome 
*		drawing first screen of classic welcmome
*
*	drawClassicGame 
*		drawing classic game
*
*	drawP 
*		drawing paused button
*
*	drawX 
*		drawing x button
*
*	drawI 
*		drawing info button
*
*	drawB 
*		drawing back button
*
*	drawFullScreen 
*		drawing full screen button
*
*	drawGameMultiPlayer
*		drawing multiplayer game
*
*	cacheImages 
*		chacing images to be available to any brush
*
*	checkCollisionPacMan
*		checking if pacman is colliding with an enemy and vice versa
*
*	checkCollisionPacDot
*		checking if the passed pointer is colliding with a pacdot
*
*	checkCollisionObstacle
*		checking if the passed pointer is colliding with an obstacle
*
*	checkCollisionPong
*		checking collision between ball and racket
*
*	resetBrush 
*		function to resetting brush
*
*	updateMusic
*		update music function
*
*	window2CanvasX
*		modifying windo width to canvas width
*
*	window2CanvasY
*		modifying window height to canvas height
*
*	update
*		general update
*
*	draw
*		general draw
*
*	init
*		general init function
*
*	playSound
*		getter of sound state
*
*	setWindowDimensions
*		setting window dim for size change
*
*	getPongLevel
*		returning pong level
*
*	getPongSpeed
*		returning pong speed
*
*	getModern
*		returning if we are playing on modern state
*
*	getMulti
*		returning if we are playing multi player
*
*	getPhantom
*		returning phantom character
*
* INCLUDED FILES:
*
* graphics.h
* config.h
* pacman.h
* phantom.h
* pong.h
* pongball.h
* maze.h
*
* @file menu.h
**/

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
	typedef enum { STATUS_START, STATUS_PLAYINGM, STATUS_PLAYINGM_INFO, STATUS_PLAYINGM_GAME, STATUS_PLAYINGC, STATUS_PLAYINGCGAME, STATUS_PLAYINGC2, STATUS_PLAYINGB, STATUS_PLAYINGPONG } status; // game status enum
	std::string msg = "0"; // msg for drawing messages
	bool modern = true, // indicating if this is modern gameplay
		music_on = true, //inidcating if music is on
		music_on_holder = true, // remembering music status after exiting games and going to menu
		sound_on = true, // indicating if sound is on
		full_screen = false, // indicating if we are on full screen mode
		place_holder = false, // a placeholder for bool values
		key_down = false, // indicating if a key is presses
		lost = false, // indicating if we lost
		multi = false, // indicating if we are on multiplayer mode
		replay = false; // indicating if we are playing
	float hover[14] = { 1.f, 1.f, 1.f, 1.f, 1.2f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }; // Hovering for close button, info button, music button, sound button, classic button (or back), bored button (or pong or play again), single player (or arcade or dont play again), multiplayer, full screen, blinky, pinky, inky, clyde, pause
	double time_counter = 0.f, // a simple time counter
		time_counter_2 = 0.f, // a simple time counter
		pong_speed = 5.f; // speed of pong
	float phantom_speed = 4.f, // speed of phantom
		pacman_speed = 5.f; // speed of pacman
	int score = 0, // pacman score
		pacman_local_score = 0, // pacman score as holder
		local_score = 0, // local score seperating the displayed score from the logic score
		highscore = 0, // pacman high score
		counter = 0, // a simple counter
		player_score = 0, // player score for multiplayer
		phantom_score = 0, // phantom score for multiplayer
		obst_counter = 0, // counting the obstacles to verify non collision
		obst_counter_2 = 0, // counting the obstacles to verify non collision
		pacman_lives = 4, // a holder for pacman lives
		pacman_level = 1; // a holder for pacman level
	unsigned short int score_pong = 0, // pong score
					   highscore_pong = 0, // highscore pong
					   window_width = WINDOW_WIDTH, // a local variable for window width
					   window_height = WINDOW_HEIGHT, // a local variable for window height
					   canvas_width = CANVAS_WIDTH, // a local variable for 
					   canvas_height = CANVAS_HEIGHT,
					   level = 1, // pong level
					   local_level = 1; // local level seperating game level from logic level
	status current_status = STATUS_START; // start status
	character phantom = BLINKY; // the phantom character to indicate if BLINKY, PINKY, INKY or CLYDE is playing
	graphics::Brush brush, // a brush
					loc_brush; // a brush
	graphics::MouseState mouse; // a mouse state
	Phantom* enemies[4] = { nullptr, nullptr, nullptr, nullptr }; // an array of phantom pointer
	Pong* pong_player = nullptr; // the pong player racket
	Pong* pong_ai = nullptr; // the pong computer racket
	void updateClassicScreen(); // update function for classic menu screen
	void updateModernScreen(); // update function for classic modern screen
	void updateMenuScreen(); // update function for menu in general
	void updateGameC(); // update function for single player state
	void updateGameM(); // update function for modern state
	void updateGameB(); // update function for bored state
	void updateX(); // update function for close button
	void updateB(status s = STATUS_START); // update function for back button
	void updateP(); // update function for pause button
	void updateI(); // update function for info button
	void updateM(); // update function for music button
	void updateS(); // update function for sound button
	void updateFullScreen(); // update function for full screen
	void updateGameMSelection(); // update function for player selection on multiplayer
	void updateGameMInfo(); // update function for showing info of selected player on multiplayer
	void updateClassicWelcome(); // first screen of gameplay for classic game
	void updateClassicWelcome2(); // second screen of gameplay for classic ame 
	void updateModernWelcome(); // fist screen of gameplay for modern game
	void updateClassicGame(); // actual gameplay for classic game
	void updateGameMultiPlayer(); // actual gameplay for multiplayer
	void updatePong(); // pong gameplay
	void updateY(); // yes selection after lossing
	void updateN(status s); // no selection after lossing
	void drawMenuScreen(); // drawing menu screen
	void drawModernScreen(); //drawing modern screen
	void drawClassicScreen(); // drawing classic screen
	void drawGameC(); // drawing game for single player state
	void drawClassicWelcome2(); // drawing fist screen of gameplay for classic game
	void drawModernWelcome(); // drawing first screen of gameplay for modern game
	void drawPong(); // drawing pong
	void drawYN(std::string txt ="0"); // drawing yes/no message after losing
	void drawGameM(); // drawing game for multiplayer state
	void drawGameB(); // drawing game for bored state
	void drawM(); // drawing music button
	void drawS(); //drawing sound button
	void drawGameMSelection(); // Draw selection screen of multiplayer
	void drawGameMInfo(); // Draw pre-game multiplayer screen
	void drawClassicWelcome(); // Draws welcome screen of classic game mode
	void drawClassicGame(); // draws classig game
	void drawP(); // pause button
	void drawX(); // close button
	void drawI(); // info button
	void drawB(); // back button
	void drawFullScreen(); // full screen button
	void drawGameMultiPlayer(); // drawing multiplayer game
	void cacheImages(); // Caching images
	bool checkCollisionPacMan(int num=0); // colision check between pacman and enemies
	bool checkCollisionPacDot(Pacdot* cur_dot, bool is_pacman); // collision check between pacman/enemies-for multi only and pacdots
	bool checkCollisionObstacle(Obstacle* cur_obst, bool is_pacman, int num=0); // collision check between pacman/enemies and obstacles
	bool checkCollisionPong(float dir); // collision between ball and racket
	void resetBrush(); // function to reset the brush
	void updateMusic(bool musictype); // updating music
	int window2CanvasX(int x); // window dim to canvas dim x
	int window2CanvasY(int y); // window dim to canvas dim y
public:
	Maze* maze = nullptr; // a maze pointer
	PongBall* pong_ball = nullptr; // a pong ball pointer
	PacMan* pacman = nullptr; // a pacman pointer
	bool paused = false; // indicating if game is paused
	void update(); // general update
	void draw(); // general draw
	void init(); // general init function
	bool playSound() const { return sound_on; }; // getter for sound on
	void setWindowDimensions(unsigned short int w, unsigned short int h); // setting windo dim for size changing
	unsigned short int getPongLevel() const { return level; }; // returning pong level
	float getPongSpeed() const { return pong_speed; }; // returning pong speed
	bool getModern() const { return modern; }; // returning if we are playing modern or not
	bool getMulti() const { return multi; }; // returning if we are playing multi or not
	character getPhantom() const { return phantom; }; // get phantom type
	Menu(); // constuctor
	~Menu(); // destructor
};
