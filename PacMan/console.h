#pragma once

#include "graphics.h"
#include "menu.h"

class Console {
	bool modern = true, music_on = true, sound_on = true;
	int score = 0; int highscore = 0;
	Menu *menu = nullptr;
	void createMenu();
	void createPacManSigle();
	void createPacManMulti();
	void createPong();
public:
	void update();
	void draw();
	void init();
	void setModern(bool m) { modern = m; };
	void setSoundOn(bool s) { sound_on = s; };
	bool& getModern() { return modern; };
	bool getSoundOn() { return sound_on; };
	Console();
	~Console();
};