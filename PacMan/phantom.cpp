/**
* FILE: phantom.cpp
* TITLE: phantom class cpp file
*
* PURPOSE:
*
* This is the class for the phantoms (enemies of pacman)
*
*	FUNCTIONS:
*	
*	init
*		init function
*
*	drawPhantomC
*		drawing classic phantom
*
*	drawPhantomM
*		drawing modern phantom
*
*	updateLeftC
*		updating left classic
*
*	updateRightC
*		updating right classic
*
*	updateUpC
*		updating up classic
*
*	updateDownC
*		updating down clasic
*
*	updateLeftM
*		updating left modern
*
*	updateRightM
*		updating right modern
*
*	updateUpM
*		updating up modern
*
*	updateDownM
*		updating down modern
*
*	updateC
*		updating classic
*
*	updateM
*		updating modern
*
*	updateChaseM
*		updating modern chawse mode
*
*	updateChaseC
*		updating classic chase mode
*
*	updateMulti
*		updating multi
*
*	chase
*		chasing function
*
*	update
*		general update
*
*	draw
*		general draw
*
*	getCollisionHull
*		returning collision points
*
*	getCollidable
*		returning if phantom can die or not
*
*	setCollidable
*		changing if the phantom can die or not
*
*	setStart
*		setting start state of phantom
*
*	getStart
*		returning if phantom has started
*
*	setSpeed
*		setting phantom speed
*
* INCLUDED FILES:
*
* pacman.h
* menu.h
* graphics.h
*
* @file phantom.cpp
**/

#include "pacman.h"
#include "menu.h"
#include "graphics.h"

/**
* Chase mode functionan
*
* NAME: chase
*
* @param none
* @return none
*
**/
void Phantom::chase()
{
	float distXLeft = 0.f;
	float distXRight = 0.f;
	float distYUp = 0.f;
	float distYDown = 0.f;

	if (menu.pacman)
	{
		distXLeft = sqrt(pow(pos.x - 1 - menu.pacman->getPosition().x, 2) + pow(pos.y - menu.pacman->getPosition().y, 2));
		distXRight = sqrt(pow(pos.x + 1 - menu.pacman->getPosition().x, 2) + pow(pos.y - menu.pacman->getPosition().y, 2));
		distYUp = sqrt(pow(pos.x - menu.pacman->getPosition().x, 2) + pow(pos.y - 1 - menu.pacman->getPosition().y, 2));
		distYDown = sqrt(pow(pos.x - menu.pacman->getPosition().x, 2) + pow(pos.y + 1 - menu.pacman->getPosition().y, 2));
	}

	if (distXLeft <= distXRight && distXLeft <= distYUp && distXLeft <= distYDown)
	{
		if (movement[0])
		{
			pos.x -= speed * graphics::getDeltaTime() / 50.f;
			updateLeftM();
		}
		else if (movement[2] && distYUp < distYDown)
		{
			pos.y -= speed * graphics::getDeltaTime() / 50.f;
			updateUpM();
		}
		else if (movement[3])
		{
			pos.y += speed * graphics::getDeltaTime() / 50.f;
			updateDownM();
		}
	}
	else if (distXRight <= distXLeft && distXRight <= distYUp && distXRight <= distYDown)
	{
		if (movement[1])
		{
			pos.x += speed * graphics::getDeltaTime() / 50.f;
			updateRightM();
		}
		else if (movement[2] && distYUp < distYDown)
		{
			pos.y -= speed * graphics::getDeltaTime() / 50.f;
			updateUpM();
		}
		else if (movement[3])
		{
			pos.y += speed * graphics::getDeltaTime() / 50.f;
			updateDownM();
		}

	}
	else if (distYUp <= distYDown && distYUp <= distXLeft && distYUp <= distXRight)
	{
		if (movement[2])
		{
			pos.y -= speed * graphics::getDeltaTime() / 50.f;
			updateUpM();
		}
		else if (movement[0] && distXLeft < distXRight)
		{
			pos.x -= speed * graphics::getDeltaTime() / 50.f;
			updateLeftM();
		}
		else if (movement[1])
		{
			pos.x += speed * graphics::getDeltaTime() / 50.f;
			updateRightM();
		}
	}
	else if (distYDown <= distYUp && distYDown <= distXLeft && distYDown <= distXRight)
	{
		if (movement[3])
		{
			pos.y += speed * graphics::getDeltaTime() / 50.f;
			updateDownM();
		}
		else if (movement[0] && distXLeft < distXRight)
		{
			pos.x -= speed * graphics::getDeltaTime() / 50.f;
			updateLeftM();
		}
		else if (movement[1])
		{
			pos.x += speed * graphics::getDeltaTime() / 50.f;
			updateRightM();
		}
	}
}

/**
* Update chase mode for modern game
*
* NAME: updateChaseM
*
* @param none
* @return none
*
**/
void Phantom::updateChaseM()
{
	if (phantom == BLINKY)
	{
		chase();
	}
	else if (phantom == PINKY)
	{
		if (pos.y > CANVAS_HEIGHT / 2 - 90 && !out)
		{
			pos.y -= graphics::getDeltaTime() * speed / 50.f;
			updateUpM();
			if (pos.y <= CANVAS_HEIGHT/2-90) out = true;
		}
		else if (out)
		{
			chase();
		}
	}
	else if (phantom == INKY)
	{
	
		if (pos.x < CANVAS_WIDTH / 2 && !out)
		{
			pos.x += graphics::getDeltaTime() * speed / 50.f;
			updateRightM();
		}
		else if (pos.y > CANVAS_HEIGHT / 2 - 90 && !out)
		{
			pos.y -= graphics::getDeltaTime() * speed / 50.f;
			updateUpM();
			if(pos.y <= CANVAS_HEIGHT / 2 - 90) out = true;
		}
		else
		{
			chase();
		}
	}
	else if (phantom == CLYDE)
	{
		if (pos.x > CANVAS_WIDTH / 2 && !out)
		{
			pos.x -= graphics::getDeltaTime() * speed / 50.f;
			updateLeftM();
		}
		else if (pos.y > CANVAS_HEIGHT / 2 - 90 && !out)
		{
			pos.y -= graphics::getDeltaTime() * speed / 50.f;
			updateUpM();
			if (pos.y <= CANVAS_HEIGHT / 2 - 90) out = true;
		}
		else
		{
			chase();
		}
	}
}

/**
* Update chase mode for classic game
*
* NAME: updateChaseC
*
* @param none
* @return none
*
**/
void Phantom::updateChaseC()
{
	if (phantom == BLINKY)
	{
		chase();
	}
	else if (phantom == PINKY)
	{
		if (pos.y > CANVAS_HEIGHT / 2 - 90 + 55 && !out)
		{
			pos.y -= graphics::getDeltaTime() * speed / 50.f;
			updateUpM();
			if (pos.y <= CANVAS_HEIGHT / 2 - 90 + 55) out = true;
		}
		else if (out)
		{
			chase();
		}
	}
	else if (phantom == INKY)
	{

		if (pos.x < CANVAS_WIDTH / 2 && !out)
		{
			pos.x += graphics::getDeltaTime() * speed / 50.f;
			updateRightM();
		}
		else if (pos.y > CANVAS_HEIGHT / 2 - 90 + 55 && !out)
		{
			pos.y -= graphics::getDeltaTime() * speed / 50.f;
			updateUpM();
			if (pos.y <= CANVAS_HEIGHT / 2 - 90 + 55) out = true;
		}
		else
		{
			chase();
		}
	}
	else if (phantom == CLYDE)
	{
		if (pos.x > CANVAS_WIDTH / 2 && !out)
		{
			pos.x -= graphics::getDeltaTime() * speed / 50.f;
			updateLeftM();
		}
		else if (pos.y > CANVAS_HEIGHT / 2 - 90 + 55 && !out)
		{
			pos.y -= graphics::getDeltaTime() * speed / 50.f;
			updateUpM();
			if (pos.y <= CANVAS_HEIGHT / 2 - 90 + 55) out = true;
		}
		else
		{
			chase();
		}
	}
}

/**
* Update multiplayer game
*
* NAME: updateMulti
*
* @param none
* @return none
*
**/
void Phantom::updateMulti()
{
	if (graphics::getKeyState(graphics::SCANCODE_UP) && movement[2])
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f;
		updateUpM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_DOWN) && movement[3])
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_LEFT) && movement[0])
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RIGHT) && movement[1])
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
* Update classic game before exit from ghost house
*
* NAME: updateC
*
* @param none
* @return none
*
**/
void Phantom::updateC()
{
	if (phantom == PINKY)
	{
		if (pos.y < 300)
		{
			dir = -1;
			updateUpM();
		}
		else if (pos.y > 325)
		{
			dir = 1;
			updateDownM();;
		}

		pos.y -= dir * graphics::getDeltaTime() * speed / 50.f;
	}
	else if (phantom == CLYDE)
	{
		if (pos.y < 305)
		{
			dir = -1;
			updateUpM();
		}
		else if (pos.y > 325)
		{
			dir = 1;
			updateDownM();
		}

		pos.y -= dir * graphics::getDeltaTime() * speed / 50.f;
	}
	else if (phantom == INKY)
	{
		if (pos.y < 305)
		{
			dir = -1;
			updateUpM();
		}
		else if (pos.y > 325)
		{
			dir = 1;
			updateDownM();

		}

		pos.y -= dir * graphics::getDeltaTime() * speed / 50.f;
	}
	else if (phantom == BLINKY)
	{
		start = false;
	}
}

/**
* Update modern mode for modern game (before exit from ghost house)
*
* NAME: updateChaseM
*
* @param none
* @return none
*
**/
void Phantom::updateM()
{
	if (phantom == PINKY)
	{
		if (pos.y < 240)
		{
			dir = -1;
			updateUpM();
		}
		else if (pos.y > 265)
		{
			dir = 1;
			updateDownM();;
		}
			
		pos.y -= dir * graphics::getDeltaTime() * speed / 50.f;
	}
	else if (phantom == CLYDE)
	{
		if (pos.y < 240)
		{
			dir = -1;
			updateUpM();
		}
		else if (pos.y > 265)
		{
			dir = 1;
			updateDownM();
		}

		pos.y -= dir * graphics::getDeltaTime() * speed / 50.f;
	}
	else if (phantom == INKY)
	{
		if (pos.y < 240)
		{
			dir = -1;
			updateUpM();
		}
		else if (pos.y > 265)
		{
			dir = 1;
			updateDownM();

		}

		pos.y -= dir * graphics::getDeltaTime() * speed / 50.f;
	}
	else if (phantom == BLINKY)
	{
		start = false;
	}
}

/**
* Update left move for modern ghost
*
* NAME: updateLeftM
*
* @param none
* @return none
*
**/
void Phantom::updateLeftM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = LEFT1;
	}
	else if (timer < 2500 / speed)
	{
		rot = LEFT2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update right move for modern ghost
*
* NAME: updateRightM
*
* @param none
* @return none
*
**/
void Phantom::updateRightM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 1500 / speed)
	{
		rot = RIGHT2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update up move for modern ghost
*
* NAME: updateUpM
*
* @param none
* @return none
*
**/
void Phantom::updateUpM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = UP1;
	}
	else if (timer < 2500 / speed)
	{
		rot = UP2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update down move for modern ghost
*
* NAME: updateDownM
*
* @param none
* @return none
*
**/
void Phantom::updateDownM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 2500 / speed)
	{
		rot = DOWN2;
	}
	else
	{
		timer = 0;
	}
}

/**
* Update left move for classic pacman
*
* NAME: updateLeftC
*
* @param none
* @return none
*
**/
void Phantom::updateLeftC()
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
	else
	{
		timer = 0;
	}
}

/**
* Update right move for classic pacman
*
* NAME: updateRightC
*
* @param none
* @return none
*
**/
void Phantom::updateRightC()
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
void Phantom::updateUpC()
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
void Phantom::updateDownC()
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
	else
	{
		timer = 0;
	}
}

/**
* General update function
*
* NAME: update
*
* @param none
* @return none
*
**/
void Phantom::update()
{
	if (!menu.paused)
	{
		if (!multi && !start)
		{
			if (modern)
			{
				updateChaseM();
			}
			else
			{
				updateChaseC();
			}
		}
		else if (!multi && start)
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
		else if (multi)
		{
			updateMulti();
		}
	}
}

/**
* drawing classic phantom
*
* NAME: drawPhantomC
*
* @param none
* @return none
*
**/
void Phantom::drawPhantomC()
{
	if (!collid)
	{
		switch (phantom)
		{
		case(PINKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_2);
				break;
			}
			break;
		case(INKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_2);
				break;
			}
			break;
		case(BLINKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_2);
				break;
			}
			break;
		case(CLYDE):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_2);
				break;
			}
			break;
		}
	}
	else
	{
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_C_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_C_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_C_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_C_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLUE_C_1);
			break;
		}
	}
}

/**
* drawing modern phantom
*
* NAME: drawPhantomC
*
* @param none
* @return none
*
**/
void Phantom::drawPhantomM()
{
	if (!collid)
	{
		switch (phantom)
		{
		case(PINKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_2);
				break;
			}
			break;
		case(INKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_2);
				break;
			}
			break;
		case(BLINKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_2);
				break;
			}
			break;
		case(CLYDE):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_2);
				break;
			}
			break;
		}
	}
	else
	{
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_LEFT_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_LEFT_2);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_DOWN_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_DOWN_2);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_UP_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_UP_2);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_RIGHT_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_RIGHT_2);
			break;
		}
	}
}

/**
* Returns the collision space of ghost
*
* NAME: getCollisionHull
*
* @param none
* @return a disk shape indicating the rectangle area of collision of ghost
* @rtype Disk
*
**/
Disk Phantom::getCollisionHull() const
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
void Phantom::draw()
{
	brush.outline_opacity = 0.f;
	if (!modern)
	{
		drawPhantomC();
	}
	else
	{
		drawPhantomM();
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
void Phantom::init()
{
	modern = menu.getModern();
	multi = menu.getMulti();
	if (multi)
	{
		phantom = menu.getPhantom();
	}
	else if (!multi && modern)
	{
		if (phantom == BLINKY)
		{
			pos.y = pos.y;
			pos.x = pos.x;
			rot = LEFT1;
			speed = 4.f;
		}
		else if (phantom == PINKY)
		{
			pos.y = pos.y + 45;
			pos.x = pos.x;
			rot = UP1;
			speed = 4.f;
		}
		else if (phantom == INKY)
		{
			pos.y = pos.y + 45;
			pos.x = pos.x - 50;
			rot = DOWN1;
			dir = -1;
			speed = 4.f;
		}
		else if (phantom == CLYDE)
		{
			pos.y = pos.y + 45;
			pos.x = pos.x + 50;
			rot = DOWN1;
			dir = -1;
			speed = 4.f;
		}
	}
	else if (!multi && !modern)
	{
		if (phantom == BLINKY)
		{
			pos.y = pos.y + 55;
			pos.x = pos.x;
			rot = LEFT1;
			speed = 4.f;
		}
		else if (phantom == PINKY)
		{
			pos.y = pos.y + 100;
			pos.x = pos.x;
			rot = UP1;
			speed = 4.f;
		}
		else if (phantom == INKY)
		{
			pos.y = pos.y + 100;
			pos.x = pos.x - 50;
			rot = DOWN1;
			dir = -1;
			speed = 4.f;
		}
		else if (phantom == CLYDE)
		{
			pos.y = pos.y + 100;
			pos.x = pos.x + 50;
			rot = DOWN1;
			dir = -1;
			speed = 4.f;
		}
	}
}

/**
* Construcctor for pacman
*
* NAME: Phantom
*
* @param ingame
* @param_type Menu reference
* @return an instance of the phantom class initialized with a reference to the Menu running instance
* @rtype Phantom instance
*
**/
Phantom::Phantom(const Menu& ingame)
	: GameElement(ingame)
{
	init();
}

/**
* Construcctor for pacman
*
* NAME: Phantom
*
* @param ingame
* @param_type Menu reference
* @param charac the character of the ghost (pinky, inky, blinky, clyde)
* @param_type character
* @return an instance of the phantom class initialized with a reference to the Menu running instance
* @rtype Phantom instance
*
**/
Phantom::Phantom(const Menu& ingame, character charac)
	: GameElement(ingame)
{
	phantom = charac;
	init();
}

/**
* Destructor for phantom
*
* NAME: ~Phantom
*
* @param none
* @return none
*
**/
Phantom::~Phantom()
{
}