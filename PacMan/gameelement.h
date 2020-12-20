#pragma once

typedef enum { UP1, UP2, DOWN1, DOWN2, LEFT1, LEFT2, RIGHT1, RIGHT2, CENTER } rotation;

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
};
