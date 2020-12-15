#include "player.h"
#include "graphics.h"

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		pos_x -= speed * graphics::getDeltaTime() / 10.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		pos_x += speed * graphics::getDeltaTime() / 10.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
	{
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
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
	brush.fill_opacity = 0.2f;
	/* Shawod*/
	brush.texture = std::string(ASSET_PATH) + "spac.png";
	graphics::drawRect(pos_x-10, pos_y+30, 100, 100, brush);
	
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + "spac.png";
	graphics::drawRect(pos_x, pos_y, 100, 100, brush);
	graphics::setOrientation(0.f);

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

	graphics::drawDisk(pos_x-30, pos_y, 100, brush);
}

void Player::init()
{

}