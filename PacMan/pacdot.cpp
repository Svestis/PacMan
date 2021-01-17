#include "pacdot.h"
#include "config.h"
#include "menu.h"

void Pacdot::draw()
{
	brush.outline_opacity = 0.f;
	if (modern)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_M);
		if (!big)
		{
			graphics::drawRect(pos.x, pos.y, 25, 25, brush);
		}
		else
		{
			graphics::drawRect(pos.x, pos.y, 35, 35, brush);
		}
	}
	else
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACDOT_C);
		if (!big)
		{
			graphics::drawRect(pos.x, pos.y, 15, 15, brush);
		}
		else
		{
			graphics::drawRect(pos.x, pos.y, 25, 25, brush);
		}
	}
}

Pacdot::Pacdot(const Menu& ingame, int x, int y, bool is_big)
	:menu(ingame)
{
	modern = menu.getModern();
	pos.x = x;
	pos.y = y;
	big = is_big;
}

Pacdot::~Pacdot()
{

}

Disk Pacdot::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	if (!big) disk.radius = 8.f;
	else disk.radius = 10.5f;
	return disk;
}


