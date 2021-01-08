#include "pacdot.h"
#include "config.h"
#include "menu.h"

void Pacdot::update()
{
}

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
		graphics::drawRect(pos.x, pos.y, 20, 20, brush);
	}

	/*graphics::Brush br;
	brush.outline_opacity = 0.f;
	br.fill_color[0] = 0.5f;
	br.fill_color[1] = 1.f;
	br.fill_color[2] = 0.f;
	br.fill_opacity = 0.5f;
	br.gradient = false;
	disk = getCollisionHull();
	graphics::drawDisk(disk.cx, disk.cy, disk.radius, br);*/
}

void Pacdot::init()
{
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


