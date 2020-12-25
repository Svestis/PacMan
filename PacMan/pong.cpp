#include "pong.h"
#include <iostream>
#include "menu.h"
#include "util.h"

void Pong::update()
{
	if (ai)
	{
		pos.y = menu.pong_ball->getY() + rand0to1();
	}
	else
	{
		if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
		{
			pos.y -= menu.getPongSpeed() * graphics::getDeltaTime() / 30.f;
		}
		else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
		{
			pos.y += menu.getPongSpeed() * graphics::getDeltaTime() / 30.f;;
		}
	}
	if (pos.y < (400 / menu.getPongLevel() * 0.5) / 2 - 10) pos.y = (400 / menu.getPongLevel()* 0.5) / 2 - 10;
	if (pos.y > CANVAS_HEIGHT - (400 / menu.getPongLevel() * 0.5) / 2 + 10) pos.y = CANVAS_HEIGHT - (400 / menu.getPongLevel() * 0.5) / 2 + 10;
}

void Pong::draw()
{
	rectangle = getCollisionHull();
	if (ai)
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PONG_AI);
		graphics::drawRect(pos.x, pos.y, 30, 400/ menu.getPongLevel() *0.5, brush);
		/*graphics::Brush br;
		br.outline_opacity = 1.f;
		br.texture = PACDOT_M;
		br.fill_color[0] = 1.f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.8f;
		br.gradient = false;


		graphics::drawRect(rectangle.cx, rectangle.cy, rectangle.w, rectangle.h, br);*/
	}
	else
	{
		brush.outline_opacity = 0.f;
		brush.texture = std::string(ASSET_PATH) + std::string(PONG_P);
		graphics::drawRect(pos.x, pos.y, 30, 400/menu.getPongLevel()*0.5, brush);
		/*graphics::Brush br;
		br.outline_opacity = 1.f;
		br.texture = PACDOT_M;
		br.fill_color[0] = 1.f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.8f;
		br.gradient = false;

		graphics::drawRect(rectangle.cx, rectangle.cy, rectangle.w, rectangle.h, br);*/
	}
}

void Pong::init()
{
	if (ai)
	{
		pos.x = CANVAS_WIDTH - 80;
	}
}

Rectangle Pong::getCollisionHull() const
{
	Rectangle rect;
	rect.cx = pos.x;
	rect.cy = pos.y;
	rect.w = 1;
	rect.h = (float)(400.f / (float)menu.getPongLevel() * 0.5f)-20.f;
	return rect;
}

Pong::Pong(const Menu& ingame, bool is_ai)
	:menu(ingame)
{
	ai = is_ai;

	init();
}

Pong::~Pong()
{
}
