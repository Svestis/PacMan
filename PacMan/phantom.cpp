#include "phantom.h"
#include "menu.h"

void Phantom::updateM()
{

}

void Phantom::updateMulti()
{
	if (graphics::getKeyState(graphics::SCANCODE_UP) && movement[2])
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f;
		updateUpM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_DOWN) && movement[3])
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_LEFT) && movement[0])
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RIGHT) && movement[1])
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightM();
	}

	if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 39) pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 39;
	if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 35) pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 35;
	if (pos.y < (CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2)) pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2;
	if (pos.y > (CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2) - 57) pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 - 57;
}

void Phantom::updateLeftM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = LEFT1;
	}
	else if (timer < 2500 / speed)
	{
		rot = LEFT2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateRightM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 1500 / speed)
	{
		rot = RIGHT2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateUpM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = UP1;
	}
	else if (timer < 2500 / speed)
	{
		rot = UP2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateDownM()
{
	timer += graphics::getDeltaTime();
	if (timer < 1250 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 2500 / speed)
	{
		rot = DOWN2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateC()
{
}

void Phantom::updateLeftC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = LEFT1;
	}
	else if (timer < 1500 / speed)
	{
		rot = LEFT2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateRightC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 1500 / speed)
	{
		rot = RIGHT2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateUpC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = UP1;
	}
	else if (timer < 1500 / speed)
	{
		rot = UP2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::updateDownC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 1500 / speed)
	{
		rot = DOWN2;
	}
	else
	{
		timer = 0;
	}
}

void Phantom::update()
{
	if (!menu.paused)
	{
		if (!multi && !start)
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
		else if (multi && !start)
		{
			updateMulti();
		}
	}
}

void Phantom::drawInitM()
{
	switch(phantom)
	{
	case(BLINKY):
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
		break;
	case(PINKY):
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
		break;
	case(INKY):
		brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_1);
		break;
	case(CLYDE):
		brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_1);
		break;
	}
	start = false;
}

void Phantom::drawInitC()
{
	switch (phantom)
	{
	case(BLINKY):
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
		break;
	case(PINKY):
		brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
		break;
	case(INKY):
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
		break;
	case(CLYDE):
		brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
		break;
	}
	start = false;
}

void Phantom::drawPhantomC()
{
	switch (phantom)
	{
	case(PINKY):
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_LEFT_2);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_DOWN_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_DOWN_2);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_UP_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_UP_2);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(PINKY_C_RIGHT_2);
			break;
		}
		break;
	case(INKY):
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_LEFT_2);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_DOWN_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_DOWN_2);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_UP_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_UP_2);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(INKY_C_RIGHT_2);
			break;
		}
		break;
	case(BLINKY):
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_LEFT_2);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_DOWN_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_DOWN_2);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_UP_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_UP_2);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_C_RIGHT_2);
			break;
		}
		break;
	case(CLYDE):
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_LEFT_2);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_DOWN_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_DOWN_2);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_UP_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_UP_2);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_C_RIGHT_2);
			break;
		}
		break;
	}
	
}

void Phantom::drawPhantomM()
{
	if (!collid)
	{
		switch (phantom)
		{
		case(PINKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(PINKY_M_RIGHT_2);
				break;
			}
			break;
		case(INKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(INKY_M_RIGHT_2);
				break;
			}
			break;
		case(BLINKY):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(BLINKY_M_RIGHT_2);
				break;
			}
			break;
		case(CLYDE):
			switch (rot)
			{
			case(LEFT1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_1);
				break;
			case(LEFT2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_LEFT_2);
				break;
			case(DOWN1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_1);
				break;
			case(DOWN2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_DOWN_2);
				break;
			case(UP1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_UP_1);
				break;
			case(UP2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_UP_2);
				break;
			case(RIGHT1):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_1);
				break;
			case(RIGHT2):
				brush.texture = std::string(ASSET_PATH) + std::string(CLYDE_M_RIGHT_2);
				break;
			}
			break;
		}
	}
	else
	{
		switch (rot)
		{
		case(LEFT1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_LEFT_1);
			break;
		case(LEFT2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_LEFT_2);
			break;
		case(DOWN1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_DOWN_1);
			break;
		case(DOWN2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_DOWN_2);
			break;
		case(UP1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_UP_1);
			break;
		case(UP2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_UP_2);
			break;
		case(RIGHT1):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_RIGHT_1);
			break;
		case(RIGHT2):
			brush.texture = std::string(ASSET_PATH) + std::string(WHITE_M_RIGHT_2);
			break;
		}
	}
}

Disk Phantom::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	disk.radius = 12.5f;
	return disk;
}


void Phantom::draw()
{
	brush.outline_opacity = 0.f;
	if (start && !modern)
	{
		drawInitC();
	}
	else if (!start && !modern)
	{
		drawPhantomC();
	}
	else if (start && modern)
	{
		drawInitM();
	}
	else if (!start && modern)
	{
		drawPhantomM();
	}

	graphics::Brush br;
	brush.outline_opacity = 0.f;
	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.5f;
	br.gradient = false;
	disk = getCollisionHull();
	graphics::drawDisk(disk.cx, disk.cy, disk.radius, br);

	graphics::drawRect(pos.x, pos.y, 25, 25, brush);
}

void Phantom::init()
{
	phantom = menu.getPhantom();
	modern = menu.getModern();
	multi = menu.getMulti();
	if (multi)
	{
		pos.y = pos.y - 90;
	}
}

Phantom::Phantom(const Menu& ingame)
	: GameElement(ingame)
{
	init();
}

Phantom::~Phantom()
{
}