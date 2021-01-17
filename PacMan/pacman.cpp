/**
* FILE: pacman.cpp
* TITLE: pacman class cpp file
*
* PURPOSE:
*
* This is the class for the pacman.
*
*	FUNCTIONS:
*
*	 init
*		general init function
*
*	 drawPacmanC
*		drawing pacman in classig game mode
*
*	 drawPacmanM
*		drawing pacman in modern game mode
*
*	 updateLeftC
*		updating left movement classic
*
*	updateRightC
*		updating right movement classic
*
*	 updateUpC
*		updating up movmeent classic
*
*	 updateDownC
*		updating down movement classic
*
*	 updateLeftM
*		updating left movement modern
*
*	 updateRightM
*		updating right movement modern
*
*	 updateUpM
*		updating up movement modern
*
*	 updateDownM
*		updating down movement modern
*
*	 updateC
*		general update for classic
*
*	 updateM
*		general update for modern
*
*	 drawInitM
*		init for modern ame
*
*	 drawInitC
*		init for classic game
*
*	 updateMulti
*		updating for multiplayer
*
*	 update
*		general update
*
*	 draw
*		general draw
*
*	 getCollisionHull
*		returning collision area
*
*	 getCollidable
*		returning bool on if the pacman can die
*
*	 setCollidable
*		changing the value to set if pacman can die or not
*
*	 setSpeed
*		setting pacman speed
*
*	 getPosition
*		getting pacman position
*
* INCLUDED FILES:
*
* pacman.h
* menu.h
* graphics.h
*
* @file pacman.cpp
**/

#include "pacman.h"
#include "graphics.h"
#include "menu.h"

/**
* Update left move for classic pacman
*
* NAME: updateLeftC
*
* @param none
* @return none
*
**/
void PacMan::updateLeftC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750/speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500/speed)
	{
		rot = LEFT1;
	}
	else if (timer < 2250/speed)
	{
		rot = LEFT2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update right move for clasic pacman
*
* NAME: updateRightC
*
* @param none
* @return none
*
**/
void PacMan::updateRightC()
{	timer += graphics::getDeltaTime();
	if (timer < 750/speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500/speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 2250/speed)
	{
		rot = RIGHT2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update up move for classic pacman
*
* NAME: updateUpC
*
* @param none
* @return none
*
**/
void PacMan::updateUpC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500 / speed)
	{
		rot = UP1;
	}
	else if (timer < 2250 / speed)
	{
		rot = UP2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update down move for classic pacman
*
* NAME: updateDownC
*
* @param none
* @return none
*
**/
void PacMan::updateDownC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 2250 / speed)
	{
		rot = DOWN2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update left move for modern pacman
*
* NAME: updateLeftM
*
* @param none
* @return none
*
**/
void PacMan::updateLeftM()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = LEFT1;
	}
	else if (timer < 1500 / speed)
	{
		rot = LEFT2;
	}
	else if (timer < 2250 / speed)
	{
		rot = LEFT3;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update right move for modern pacman
*
* NAME: updateRightM
*
* @param none
* @return none
*
**/
void PacMan::updateRightM()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 1500 / speed)
	{
		rot = RIGHT2;
	}
	else if (timer < 2250 / speed)
	{
		rot = RIGHT3;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update up move for modern pacman
*
* NAME: updateUpM
*
* @param none
* @return none
*
**/
void PacMan::updateUpM()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = UP1;
	}
	else if (timer < 1500 / speed)
	{
		rot = UP2;
	}
	else if (timer < 2250 / speed)
	{
		rot = UP3;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update down move for modern pacman
*
* NAME: updatedownM
*
* @param none
* @return none
*
**/
void PacMan::updateDownM()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 1500 / speed)
	{
		rot = DOWN2;
	}
	else if (timer < 2250 / speed)
	{
		rot = DOWN3;
	}
	else
	{
		timer = 0;
	}
}

/**
* Draw pacman initial state for classic game
*
* NAME: drawInitC
*
* @param none
* @return none
*
**/
void PacMan::drawInitC()
{
	if (start) timer += graphics::getDeltaTime();
	if (timer < 200)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_START);
		rot = CENTER;
	}
	else if (timer < 400)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_1);
		rot = LEFT1;
	}
	else if (timer < 600)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_2);
		rot = LEFT2;
	}
	else
	{
		timer = 0;
		start = false;
	}

	brush.outline_opacity = 0.f;
}

/**
* Draw pacman initial state for modern game
*
* NAME: drawInitM
*
* @param none
* @return none
*
**/
void PacMan::drawInitM()
{
	if (start) timer += graphics::getDeltaTime();
	if (timer < 200)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_1);
		rot = LEFT1;
	}
	else if (timer < 400)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_2);
		rot = LEFT2;
	}
	else if (timer < 600)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_3);
		rot = LEFT3;
	}
	else
	{
		timer = 0;
		start = false;
	}

	brush.outline_opacity = 0.f;
}

/**
* Update pacman for modern game
*
* NAME: updateM
*
* @param none
* @return none
*
**/
void PacMan::updateM()
{
	if ((graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP)) && movement[2])
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f;
		updateUpM();
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN)) && movement[3])
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownM();
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT)) && movement[0])
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftM();
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT)) && movement[1])
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightM();
	}

	if (menu.maze)
	{
		if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 39) pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 39;
		if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 35) pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 35;
		if (pos.y < (CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2)) pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2;
		if (pos.y > (CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2) - 57) pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 - 57;
	}	
}

/**
* Update pacman for classic game
*
* NAME: updateC
*
* @param none
* @return none
*
**/
void PacMan::updateC()
{
	if ((graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP)) && movement[2] && moveUp)
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f ;
		updateUpC();
		dir = UP;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN)) && movement[3] && moveDown)
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownC();
		dir = DOWN;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT)) && movement[0] && moveLeft)
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftC();
		dir = LEFT;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT)) && movement[1] && moveRight)
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightC();
		dir = RIGHT;
	}

	if (menu.maze)
	{
		if (pos.y < 317 && pos.y > 311 && (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 154 || pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 154)) // Tube
		{
			moveUp = false;
			moveDown = false;
			pos.y = 314;
			if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 15) // right
			{
				pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 15 + 1;
			}
			else if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 15) // left
			{
				pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 15 - 1;
			}
		}
		else if ((pos.y > 220 && pos.y <= 311) || (pos.y >= 317 && pos.y < 407)) // bump
		{
			if (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155) // right
			{
				pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155;
			}
			else if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155)) // left
			{
				pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155;
			}
			moveUp = true;
			moveDown = true;
		}
		else // other
		{
			if (pos.y <= 220 && pos.y >= 218 && (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155 || pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155)) // Right and left upper part
			{
				pos.y = 219;
				moveDown = false;
			}
			else moveDown = true;

			if (pos.y >= 407 && pos.y <= 409 && (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155 || pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155)) // Right and left down part
			{
				pos.y = 408;
				moveUp = false;
			}
			else moveUp = true;

			if (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 27) // right
			{
				pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 27;
			}
			else if (pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 27) // left
			{
				pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 27;
			}
		}

		if (pos.y > CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 + 7) // down
		{

			pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 + 7;
		}

		if (pos.y < CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2 + 54) // up
		{
			pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2 + 54;
		}
	}
			
	if (pos.y < 0) pos.y = 0;
	if (pos.y > CANVAS_HEIGHT) pos.y = CANVAS_HEIGHT;
}

/**
* Update pacman general function
*
* NAME: update
*
* @param none
* @return none
*
**/
void PacMan::update()
{
	if (!menu.paused)
	{
		if (!multi && !start)
		{
			if (modern)
			{
				updateM();
			}
			else
			{
				updateC();
			}
		}
		else if (modern && !start)
		{
			updateMulti();
		}
	}
}

/**
* Update pacman for multi game
*
* NAME: updateMulti
*
* @param none
* @return none
*
**/
void PacMan::updateMulti()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) && movement[2])
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f;
		updateUpM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S) && movement[3])
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_A) && movement[0])
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D) && movement[1])
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightM();
	}

	if (menu.maze)
	{
		if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 39) pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 39;
		if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 35) pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 35;
		if (pos.y < (CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2)) pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2;
		if (pos.y > (CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2) - 57) pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 - 57;
	}
}

/**
* draw pacman for classic game
*
* NAME: drawPacmanC
*
* @param none
* @return none
*
**/
void PacMan::drawPacmanC()
{
	if (rot == CENTER) 
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_START);
	}
	else if(rot == LEFT1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_1);
	}
	else if(rot == LEFT2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_LEFT_2);
	}
	else if(rot == DOWN1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DOWN_1);
	}
	else if(rot == DOWN2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DOWN_2);
	}
	else if(rot == UP1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_UP_1);
	}
	else if(rot == UP2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_UP_2);
	}
	else if (rot == RIGHT1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_RIGHT_1);
	}
	else if (rot == RIGHT2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_RIGHT_2);
	}	
}

/**
* draw pacman for modern game
*
* NAME: drawPacmanM
*
* @param none
* @return none
*
**/
void PacMan::drawPacmanM()
{
	if (rot == LEFT1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_1);
	}
	else if (rot == LEFT2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_2);
	}
	else if (rot == LEFT3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_3);
	}
	else if (rot == DOWN1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_DOWN_1);
	}
	else if (rot == DOWN2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_DOWN_2);
	}
	else if (rot == DOWN3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_DOWN_3);
	}
	else if (rot == UP1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_UP_1);
	}
	else if (rot == UP2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_UP_2);
	}
	else if (rot == UP3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_UP_3);
	}
	else if (rot == RIGHT1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_1);
	}
	else if (rot == RIGHT2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_2);
	}
	else if (rot == RIGHT3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_3);
	}
}

/**
* Returns the collision space of pacman
*
* NAME: getCollisionHull
*
* @param none
* @return a disk shape indicating the rectangle area of collision of pacman
* @rtype Disk
*
**/
Disk PacMan::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	disk.radius = 12.5f;
	return disk;
}

/**
* General draw function
*
* NAME: draw
*
* @param none
* @return none
*
**/
void PacMan::draw()
{
	if (start && !modern)
	{
		drawInitC();
	}
	else if (!start && !modern)
	{
		drawPacmanC();
	}
	else if (start && modern)
	{
		drawInitM();
	}
	else if (!start && modern)
	{
		drawPacmanM();
	}

	graphics::drawRect(pos.x, pos.y, 25, 25, brush);
}

/**
* General init function
*
* NAME: init
*
* @param none
* @return none
*
**/
void PacMan::init()
{
	if (!modern)
	{
		pos.y += 63;
	}
}

/**
* Construcctor for pacman
*
* NAME: PacMan
*
* @param ingame
* @param_type Menu reference
* @return an instance of the pacman class initialized with a reference to the Menu running instance
* @rtype Pacman instance
*
**/
PacMan::PacMan(const Menu& ingame)
	:GameElement(ingame)
{
	modern = menu.getModern(); // Getter in order not to do back to back calls (initialized and then remainds unchanged
	multi = menu.getMulti(); //  Getter in order not to do back to back calls (initialized and then remainds unchanged
	init();
}

/**
* Destructor for pacman
*
* NAME: ~PacMan
*
* @param none
* @return none
*
**/
PacMan::~PacMan()
{
}
