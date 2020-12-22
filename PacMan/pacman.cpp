#include "pacman.h"
#include "graphics.h"

// updating images for left state
void PacMan::updateLeftC()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000/speed)
	{
		rot = CENTER;
	}
	else if (timer < 2000/speed)
	{
		rot = LEFT1;
	}
	else if (timer < 3000/speed)
	{
		rot = LEFT2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateRightC()
{	timer += graphics::getDeltaTime();
	if (timer < 1000/speed)
	{
		rot = CENTER;
	}
	else if (timer < 2000/speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 3000/speed)
	{
		rot = RIGHT2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateUpC()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000 / speed)
	{
		rot = CENTER;
	}
	else if (timer < 2000 / speed)
	{
		rot = UP1;
	}
	else if (timer < 3000 / speed)
	{
		rot = UP2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateDownC()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000 / speed)
	{
		rot = CENTER;
	}
	else if (timer < 2000 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 3000 / speed)
	{
		rot = DOWN2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateLeftM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000 / speed)
	{
		rot = LEFT1;
	}
	else if (timer < 2000 / speed)
	{
		rot = LEFT2;
	}
	else if (timer < 3000 / speed)
	{
		rot = LEFT3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateRightM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000 / speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 2000 / speed)
	{
		rot = RIGHT2;
	}
	else if (timer < 3000 / speed)
	{
		rot = RIGHT3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateUpM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000 / speed)
	{
		rot = UP1;
	}
	else if (timer < 2000 / speed)
	{
		rot = UP2;
	}
	else if (timer < 3000 / speed)
	{
		rot = UP3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateDownM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1000 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 2000 / speed)
	{
		rot = DOWN2;
	}
	else if (timer < 3000 / speed)
	{
		rot = DOWN3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::drawInitM()
{
	if (start) timer += graphics::getDeltaTime();
	if (timer < 200 && start)
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

void PacMan::updateM()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
	{
		pos.y -= speed * graphics::getDeltaTime() / 30.f;
		updateUpM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		pos.y += speed * graphics::getDeltaTime() / 30.f;
		updateDownM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		pos.x -= speed * graphics::getDeltaTime() / 30.f;
		updateLeftM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		pos.x += speed * graphics::getDeltaTime() / 30.f;
		updateRightM();
	}

	if (pos.x < 0) pos.x = 0;
	if (pos.x > CANVAS_WIDTH) pos.x = CANVAS_WIDTH;
	if (pos.y < 0) pos.y = 0;
	if (pos.y > CANVAS_HEIGHT) pos.y = CANVAS_HEIGHT;
}

void PacMan::updateC()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
	{
		pos.y -= speed * graphics::getDeltaTime() / 30.f;
		updateUpC();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		pos.y += speed * graphics::getDeltaTime() / 30.f;
		updateDownC();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		pos.x -= speed * graphics::getDeltaTime() / 30.f;
		updateLeftC();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		pos.x += speed * graphics::getDeltaTime() / 30.f;
		updateRightC();
	}

	if (pos.x < 0) pos.x = 0;
	if (pos.x > CANVAS_WIDTH) pos.x = CANVAS_WIDTH;
	if (pos.y < 0) pos.y = 0;
	if (pos.y > CANVAS_HEIGHT) pos.y = CANVAS_HEIGHT;
}

void PacMan::update()
{
	if (!multi)
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
	else
	{
		updateMulti();
	}
}

// Setting drawing for start
void PacMan::drawInitC()
{
	if (start) timer += graphics::getDeltaTime();
	if (timer < 200 && start)
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

void PacMan::updateMulti()
{
}

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

	graphics::drawRect(pos.x, pos.y, 30, 30, brush);
}

void PacMan::init()
{
}

PacMan::PacMan()
{
}

PacMan::~PacMan()
{
}