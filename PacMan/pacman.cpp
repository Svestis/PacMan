#include "pacman.h"
#include "graphics.h"

// updating images for left state
void PacMan::updateLeft()
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

void PacMan::updateRight()
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

void PacMan::updateUp()
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

void PacMan::updateDown()
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

void PacMan::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
	{
		pos.y -= speed * graphics::getDeltaTime() / 30.f;
		updateUp();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		pos.y += speed * graphics::getDeltaTime() / 30.f;
		updateDown();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		pos.x -= speed * graphics::getDeltaTime() / 30.f;
		updateLeft();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		pos.x += speed * graphics::getDeltaTime() / 30.f;
		updateRight();
	}

	if (pos.x < 0) pos.x = 0;
	if (pos.x > CANVAS_WIDTH) pos.x = CANVAS_WIDTH;
	if (pos.y < 0) pos.y = 0;
	if (pos.y > CANVAS_HEIGHT) pos.y = CANVAS_HEIGHT;
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

void PacMan::draw()
{
	if (start) drawInitC(); // TODO: Change for modern - this is classic
	else drawPacmanC();

	graphics::drawRect(pos.x, pos.y, 30, 30, brush);
}

void PacMan::init()
{
}
