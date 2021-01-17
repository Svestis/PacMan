/**
* FILE: pongball.cpp
* TITLE: pongball class cpp file
*
* PURPOSE:
*
* This is the implementation file of the pongball class (the ball of the pong game)

* FUNCTIONS:
*
* update
*   updating the ball (moving)
*
* draw
*   drawing the ball
*
* init
*   defining the position in x axis according to the player type (human or pc)
*
* changeDirection
*	chaning ball direction (left/right)
*
* setAngle
*	setting the angle of the ball in order not to move to a straight line parallel to x'x
*
* getCollisionHull
*	setting the collision area for the ball
*
* INCLUDED FILES:
*
* pongball.h
* menu.h
* config.h
*
* @file pongball.cpp
**/

#include "pongball.h"
#include "config.h"
#include "menu.h"

/**
* Update the position of the ball
*
* NAME: update
*
* @param none
* @return none
*
**/
void PongBall::update()
{
	pos.x -= dir * menu.getPongSpeed() * angleX * graphics::getDeltaTime() / 20; //Changing position of x axis

	if (pos.y < 0 || pos.y > CANVAS_HEIGHT) // Case of hitting wall
	{
		angleY = -angleY;
		if (menu.playSound())
		{
			graphics::playSound(std::string(ASSET_PATH) + std::string(PONGHIT), 1.f, false);
		}
	}
	pos.y -= angleY; // changing position of y axis
}

/**
* Draws the ball
*
* NAME: draw
*
* @param none
* @return none
*
**/
void PongBall::draw()
{
	brush.outline_opacity = 0.f;
	brush.texture = std::string(ASSET_PATH) + std::string(PONG_BALL);
	graphics::drawRect(pos.x, pos.y, 35, 35, brush);
}

/**
* Returns the collision space of the ball
*
* NAME: getCollisionHull
*
* @param none
* @return a disk shape indicating the rectangle area of collision of the ball
* @rtype Disk
*
**/
Disk PongBall::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	disk.radius = 10.0f;
	return disk;
}

/**
* Changes the direction of the ball (left/right)
*
* NAME: changeDirection
*
* @param none
* @return none
* @rtype none
*
**/
void PongBall::changeDirection()
{
	dir = -dir; 
	if (menu.playSound()) graphics::playSound(std::string(ASSET_PATH) + std::string(PONGHIT), 1.f, false);
}

/**
* Changes the angle of the ball according to the collision point of the ball on the racket
*
* NAME: setAngle
*
* @param reference to rect
* @return none
* @rtype none
*
**/
void PongBall::setAngle(Rectangle& rect)
{
	float relativeY = rect.cy - pos.y;

	float normY = (rect.cy - pos.y) / rect.h / 2.f;
	angleY = 10*sin(normY); // normalizing through a sin function
	angleX = cos(normY); // normalizing through a cos function
}

/**
* Construcctor for the ball
*
* NAME: PongBall
*
* @param ingame
* @param_type Menu reference
* @return an instance of the pong ball initialized with a reference to the Menu running instance
* @rtype PongBall instance
*
**/
PongBall::PongBall(const Menu& ingame)
	:menu(ingame)
{
}

/**
* Destructor for the pong ball
*
* NAME: ~PongBall
*
* @param none
* @return none
*
**/
PongBall::~PongBall()
{
}
