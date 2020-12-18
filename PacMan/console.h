#pragma once

#include "graphics.h"
#include "menu.h"

class Console {
	bool modern = true, music_on = true, sound_on = true;
	int * score; 
	int highscore = 0;
	Menu *menu = nullptr;
	void createMenu();
	void createPacManSigle();
	void createPacManMulti();
	void createPong();
public:
	void update();
	void draw();
	void init();
	void setScore(int* new_score) { score = new_score; };
	Console();
	~Console();
};