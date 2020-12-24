#include "player.h"
#include "graphics.h"
#include "game.h"
#include <iostream>

Player::Player(const Game& game)
	:GameObject(game)
{

}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_A) /*|| graphics::getKeyState(graphics::SCANCODE_LEFT)*/)
	{
		float xl = speed * graphics::getDeltaTime() / 100.0f;
		pos_x -= xl;
		std::cout << " left " << pos_x << " " << xl << std::endl;
	}

	if (graphics::getKeyState(graphics::SCANCODE_D) /*|| graphics::getKeyState(graphics::SCANCODE_RIGHT)*/)
	{
		float xl = speed * graphics::getDeltaTime() / 100.0f;
		pos_x += xl;
		std::cout << " right  " << pos_x << " " << xl << std::endl;
	}

	if (graphics::getKeyState(graphics::SCANCODE_W) /*|| graphics::getKeyState(graphics::SCANCODE_UP)*/)
	{
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_S) /*|| graphics::getKeyState(graphics::SCANCODE_DOWN)*/)
	{
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}
	
	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		height += 0.01f * graphics::getDeltaTime();
		if (height > 3.0f) height = 3.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		height -= 0.01f * graphics::getDeltaTime();
		if (height < 0.1f) height = 0.1f;
	}

	if (pos_x < 0) pos_x = 0;
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y < 0) pos_y = 0;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT;
}

void Player::draw()
{
	float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime());

	graphics::Brush brush;
	brush.outline_opacity = 0.0f;

	graphics::setOrientation(-90.f);
	graphics::setScale(height, height);
	brush.fill_opacity = 0.2f;

	/* Shawod*/
	brush.texture = std::string(ASSET_PATH) + "spac.png";
	graphics::drawRect(pos_x-10*height, pos_y+30*height*0.3, 100, 100, brush);
	
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + "spac.png";
	graphics::drawRect(pos_x, pos_y, 100, 100, brush);

	
	graphics::resetPose();

	brush.texture = "";
	brush.fill_color[0] = 1.0f;
	brush.fill_color[1] = 0.5f + glow*0.5f;
	brush.fill_color[2] = 0.0f;
	brush.fill_secondary_color[0] = 0.3f;
	brush.fill_secondary_color[1] = 0.1f;
	brush.fill_secondary_color[2] = 0.0f;
	brush.fill_opacity = 1.0f;
	brush.fill_secondary_opacity = 0.0f;
	brush.gradient = true;
	graphics::setScale(height, height);

	graphics::drawDisk(pos_x-50*height, pos_y, 100, brush);
	graphics::resetPose();

	/*
	brush.outline_opacity = 1.f;
	brush.texture = "";
	brush.fill_color[0] = 0.3f;
	brush.fill_color[1] = 1.f;
	brush.fill_color[2] = 0.3f;
	brush.fill_opacity = 0.3f;
	brush.gradient = false;

	Disk hull = getCollisionHull();

	graphics::drawDisk(hull.cx, hull.cy, hull.radius, brush);*/


}

void Player::init()
{

}
/*
Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 55.0f;
	return disk;
}*/