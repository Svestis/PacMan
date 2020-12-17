#pragma once


class Menu
{
	bool modern = true, sound_on = true;

public:
	void update();
	void draw();
	void init();
	void setModern(bool m) { modern = m; };
	void setSoundOn(bool s) { sound_on = s; };
	bool getModern() { return modern; };
	bool getSoundOn() { return sound_on; };
	Menu();
	~Menu();
};
