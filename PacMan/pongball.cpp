#include "pongball.h"
#include "config.h"
#include <iostream>
#include "menu.h"

void PongBall::update()
{
	pos.x -= dir * menu.getPongSpeed() * angleX * graphics::getDeltaTime() / 20;

	if (pos.y < 0 || pos.y > CANVAS_HEIGHT)
	{
		angleY = -angleY;
		if (menu.playSound())
		{
			graphics::playSound(std::string(ASSET_PATH) + std::string(PONGHIT), 1.f, false);
		}
	}
	pos.y -= angleY;
}

void PongBall::draw()
{
	brush.outline_opacity = 0.f;
	brush.texture = std::string(ASSET_PATH) + std::string(PONG_BALL);
	graphics::drawRect(pos.x, pos.y, 35, 35, brush);
	disk = getCollisionHull();
}

void PongBall::init()
{
}

Disk PongBall::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	disk.radius = 10.0f;
	return disk;
}

void PongBall::changeDirection()
{
	dir = -dir; 
	if (menu.playSound()) graphics::playSound(std::string(ASSET_PATH) + std::string(PONGHIT), 1.f, false);
}

void PongBall::setAngle(Rectangle& rect)
{
	float relativeY = rect.cy - pos.y;

	float normY = (rect.cy - pos.y) / rect.h / 2.f;
	angleY = 10*sin(normY);
	angleX = cos(normY);
}

PongBall::PongBall(const Menu& ingame)
	:menu(ingame)
{
	init();
}

PongBall::~PongBall()
{
}
