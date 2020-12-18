#pragma once

#include "graphics.h"

class Menu
{
	bool modern = true, music_on = true, sound_on = true; // TODO: Move it to console class
	float hover[8] = {1.f, 1.f, 1.f, 1.f, 1.2f, 1.f, 1.f, 1.f}; // Hovering for close button, info button, music button, sound button, classic button, bored button, single player & multiplayer
	int score = 0; int highscore = 0; // TODO: Move it to console class
	const class Console& curr_console;
	graphics::Brush brush;
	graphics::MouseState mouse;
	void updateMusic(bool musictype);
public:
	void update();
	void draw();
	void init();
	Menu(const class Console & console);
	~Menu();
};
