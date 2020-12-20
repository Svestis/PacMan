#pragma once

typedef enum { UP1, UP2, UP3, DOWN1, DOWN2, DOWN3, LEFT1, LEFT2, LEFT3, RIGHT1, RIGHT2, RIGHT3, CENTER } rotation;

struct Rect
{
	float cx, cy, size;
};

struct Position
{
	int x, y;
};


/*class Collidable
{
public:
	virtual Rect getCollisionHull() const = 0;
};*/

class GameElement
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	virtual void updateLeftC() = 0;
	virtual void updateRightC() = 0;
	virtual void updateUpC() = 0;
	virtual void updateDownC() = 0;
	virtual void updateLeftM() = 0;
	virtual void updateRightM() = 0;
	virtual void updateUpM() = 0;
	virtual void updateDownM() = 0;
	virtual void updateC() = 0;
	virtual void updateM() = 0;
	virtual void drawInitM() = 0;
	virtual void drawInitC() = 0;
};
