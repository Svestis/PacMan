/**
* FILE: pong.cpp
* TITLE: pong class cpp file
*
* PURPOSE:
*
* This is the implementation file of the pong class (the rackets of the pong game)

* FUNCTIONS:
*
* update
*   updating the rackets
*
* draw
*   drawing the rackets
*
* init
*   defining the position in x axis according to the player type (human or pc)
*
* getCollisionHull
*	returning the collision area for the rackets
*
* INCLUDED FILES:
*
* pong.h
* menu.h
* utli.h
*
* @file pong.cpp
**/

#include "pong.h"
#include "menu.h"
#include "util.h"

/**
* Update the position of the rackets
*
* NAME: update
*
* @param none
* @return none
*
**/
void Pong::update()
{
	if (ai) // Case that the ai is playing
	{
		if (menu.pong_ball->getDir() < 0) // If the ball is coming towards the ai
		{
			if (menu.pong_ball->getY() > pos.y + error)
			{
				pos.y += menu.getPongSpeed() * graphics::getDeltaTime() / 30.f; // Move the racket down
			}
			else if (menu.pong_ball->getY() < pos.y + error)
			{
				pos.y -= menu.getPongSpeed() * graphics::getDeltaTime() / 30.f; // Move the racket up
			}
		}
		else // If the ball is moving away
		{
			error = std::rand() %(int)( ((400 / menu.getPongLevel() * 0.95) / 4 + 1) + (400 / menu.getPongLevel() * 0.95) / 4);
		}

	}
	else // Case that the human is playing
	{
		if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP)) // Moving up
		{
			pos.y -= menu.getPongSpeed() * graphics::getDeltaTime() / 30.f;
		}
		else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN)) // Moving down
		{
			pos.y += menu.getPongSpeed() * graphics::getDeltaTime() / 30.f;
		}
	}
	if (pos.y < (400 / menu.getPongLevel() * 0.95) / 2 - 10) pos.y = (400 / menu.getPongLevel()* 0.95) / 2 - 10; //Preventing going off grid - down
	if (pos.y > CANVAS_HEIGHT - (400 / menu.getPongLevel() * 0.95) / 2 + 10) pos.y = CANVAS_HEIGHT - (400 / menu.getPongLevel() * 0.95) / 2 + 10; // Preventing going off grid up
}

/**
* Draws the rackets
*
* NAME: draw
*
* @param none
* @return none
*
**/
void Pong::draw()
{
	if (ai) // Printing the ai racket on screen
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PONG_AI);
		graphics::drawRect(pos.x, pos.y, 30, 400/ menu.getPongLevel() *0.95, brush);
	}
	else // Printing the player racket on screen
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PONG_P);
		graphics::drawRect(pos.x, pos.y, 30, 400/menu.getPongLevel()*0.95, brush);
	}
}

/**
* Returns the collision space of the rectangle
*
* NAME: getCollisionHull
*
* @param none
* @return a rectangle shape indicating the rectangle area of collision of the racket
* @rtype Rectangle
*
**/
Rectangle Pong::getCollisionHull() const
{
	Rectangle rect; // Defining a rectangle
	rect.cx = pos.x; // Defining x
	rect.cy = pos.y; // Defining y
	rect.w = 1; // Defining width of the collision rectangle
	rect.h = (float)(400.f / (float)menu.getPongLevel() * 0.95f)-20.f;
	return rect;
}

/**
* Construcctor for the pong racket
* 
* NAME: Pong
*
* @param ingame
* @param_type Menu reference
* @param is_ai
* @param_type bool
* @return an instance of the pong class initialized with a reference to the Menu running instance and a value indicating if the computer is playing
* @rtype Pong instance
*
**/
Pong::Pong(const Menu& ingame, bool is_ai)
	:menu(ingame)
{
	ai = is_ai;

	if (ai)
	{
		pos.x = CANVAS_WIDTH - 80;
	}
}

/**
* Destructor for the pong racket
*
* NAME: ~Pong
*
* @param none
* @return none
*
**/
Pong::~Pong()
{

}
