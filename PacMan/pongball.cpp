#include "pongball.h"
#include "config.h"
#include <iostream>

void PongBall::update()
{
	pos.x -= dir * speed * graphics::getDeltaTime() / 20;

	if (pos.y < 5 || pos.y > CANVAS_HEIGHT - 5)
	{
		angleY = -angleY;
	}

	pos.y += angleY;;

}

void PongBall::draw()
{
	brush.outline_opacity = 0.f;
	brush.texture = std::string(ASSET_PATH) + std::string(PONG_BALL);
	graphics::drawRect(pos.x, pos.y, 35, 35, brush);
	/*graphics::Brush br;
	brush.outline_opacity = 1.f;
	br.texture = PACDOT_M;
	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.8f;
	br.gradient = false;*/
	disk = getCollisionHull();
	//graphics::drawDisk(disk.cx, disk.cy, disk.radius, br);
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

void PongBall::setAngle(const Rectangle* rectangle)
{
	float relativeY = (rectangle->cy + (400 / level * 0.5) / 2) - pos.y;

	float normY = (relativeY / ((rectangle->cy + (400 / level * 0.5) / 2)));

	angleY = (sin(normY * (6 * 3.140081 / 12))*speed);

	if (pos.y > rectangle->cy)
	{
		angleY = -angleY;
	}

	std::cout << angleY << std::endl;

	
}

PongBall::PongBall(const Menu& ingame)
	:menu(ingame)
{
	init();
}

PongBall::~PongBall()
{
}
