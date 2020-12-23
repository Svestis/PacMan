#include "pong.h"

void Pong::update()
{
	if (ai) // change this with ai
	{


	}
	else
	{
		if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
		{
			pos.y -= speed * graphics::getDeltaTime() / 30.f;
		}
		else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
		{
			pos.y += speed * graphics::getDeltaTime() / 30.f;
		}
	}
	if (pos.y < (400 / level * 0.5) / 2 - 10) pos.y = (400 / level * 0.5) / 2 - 10;
	if (pos.y > CANVAS_HEIGHT - (400 / level * 0.5) / 2 + 10) pos.y = CANVAS_HEIGHT - (400 / level * 0.5) / 2 + 10;	
}

void Pong::draw()
{
	if (ai)
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PONG_AI);
		graphics::drawRect(pos.x, pos.y, 30, 400/level*0.5, brush);
	}
	else
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PONG_P);
		graphics::drawRect(pos.x, pos.y, 30, 400/level*0.5, brush);
	}
}

void Pong::init()
{
	if (ai)
	{
		pos.x = CANVAS_WIDTH - 80;
	}
}

Pong::Pong(const Menu& ingame, bool is_ai)
	:menu(ingame)
{
	if (is_ai)
	{
		ai = true;
	}
	else
	{
		ai = false;
	}

	init();
}

Pong::~Pong()
{
}
