#pragma once

#include "graphics.h"

class Menu
{
	bool modern = true, music_on = true, sound_on = true;
	float hover_c = 1.f, hover_i = 1.f, hover_m = 1.f, hover_s = 1.f;
	int score = 0; int highscore = 0;
	const class Console& curr_console;
	graphics::Brush brush;
	graphics::MouseState mouse;
	void updateMusic(bool musictype);
public:
	void update();
	void draw();
	void init();
	void setModern(bool m) { modern = m; };
	void setSoundOn(bool s) { sound_on = s; };
	bool getModern() { return modern; };
	bool getSoundOn() { return sound_on; };
	Menu(const class Console & console);
	~Menu();
};
