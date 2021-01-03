#include "pacman.h"
#include "graphics.h"
#include "menu.h"

// updating images for left state
void PacMan::updateLeftC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750/speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500/speed)
	{
		rot = LEFT1;
	}
	else if (timer < 2250/speed)
	{
		rot = LEFT2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateRightC()
{	timer += graphics::getDeltaTime();
	if (timer < 750/speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500/speed)
	{
		rot = RIGHT1;
	}
	else if (timer < 2250/speed)
	{
		rot = RIGHT2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateUpC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500 / speed)
	{
		rot = UP1;
	}
	else if (timer < 2250 / speed)
	{
		rot = UP2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateDownC()
{
	timer += graphics::getDeltaTime();
	if (timer < 750 / speed)
	{
		rot = CENTER;
	}
	else if (timer < 1500 / speed)
	{
		rot = DOWN1;
	}
	else if (timer < 2250 / speed)
	{
		rot = DOWN2;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateLeftM()
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
	else if (timer < 2250 / speed)
	{
		rot = LEFT3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateRightM()
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
	else if (timer < 2250 / speed)
	{
		rot = RIGHT3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateUpM()
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
	else if (timer < 2250 / speed)
	{
		rot = UP3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::updateDownM()
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
	else if (timer < 2250 / speed)
	{
		rot = DOWN3;
	}
	else
	{
		timer = 0;
	}
}

void PacMan::drawDeath()
{
	timer += graphics::getDeltaTime();
	if (timer < 75)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_1);
	}
	else if (timer < 150)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_2);
	}
	else if (timer < 225)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_3);
	}
	else if (timer < 300)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_4);
	}
	else if (timer < 375)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_5);
	}
	else if (timer < 450)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_6);
	}
	else if (timer < 525)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_7);
	}
	else if (timer < 600)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_8);
	}
	else if (timer < 675)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_9);
	}
	else if (timer < 750)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_10);
	}
	else if (timer < 825)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_C_DEATH_11);
	}
	else
	{
		timer = 0;
	}
}

void PacMan::drawInitM()
{
	if (start) timer += graphics::getDeltaTime();
	if (timer < 200)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_1);
		rot = LEFT1;
	}
	else if (timer < 400)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_2);
		rot = LEFT2;
	}
	else if (timer < 600)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_3);
		rot = LEFT3;
	}
	else
	{
		timer = 0;
		start = false;
	}

	brush.outline_opacity = 0.f;
}

void PacMan::updateM()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f;
		updateUpM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightM();
	}

	if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 39) pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 39;
	if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 35) pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 35;
	if (pos.y < (CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2)) pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2;
	if (pos.y > (CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2) - 57) pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 - 57;
	
}

void PacMan::updateC()
{
	if ((graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP)) && moveUp)
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f ;
		updateUpC();
		dir = UP;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN)) && moveDown)
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownC();
		dir = DOWN;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT)) && moveLeft)
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftC();
		dir = LEFT;
	}
	else if ((graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT)) && moveRight)
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightC();
		dir = RIGHT;
	}

	if (pos.y < 317 && pos.y > 311 && (pos.x > CANVAS_WIDTH /2 + menu.maze->getWidth() /2 - 154 || pos.x < CANVAS_WIDTH /2 - menu.maze->getWidth() /2 + 154)) // Tube
	{
		moveUp = false;
		moveDown = false;
		pos.y = 314;
		if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 15) // right
		{	
			pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 15 + 1;
		}
		else if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 15) // left
		{
			pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 15 - 1;
		}
	}
	else if ((pos.y > 220 && pos.y <= 311) || (pos.y >= 317 && pos.y < 407)) // bump
	{
		if (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155) // right
		{
			pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155;
		}
		else if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155)) // left
		{
			pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155;
		}
		moveUp = true;
		moveDown = true;
	}
	else // other
	{
		if (pos.y <= 220 && pos.y >= 218 && (pos.x >  CANVAS_WIDTH /2 + menu.maze->getWidth() / 2 - 155 || pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155)) // Right and left upper part
		{
			pos.y = 219;
			moveDown = false;
		}
		else moveDown = true;

		if (pos.y >= 407 && pos.y <= 409 && (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 155 || pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 155)) // Right and left down part
		{
			pos.y = 408;
			moveUp = false;
		}
		else moveUp = true;

		if (pos.x > CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 27) // right
		{
			pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 27;
		}
		else if (pos.x < CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 27) // left
		{
			pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 27;
		}
	}
	
	if (pos.y > CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 + 7) // down
	{
	
		pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 + 7;
	}

	if (pos.y < CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2 + 54) // up
	{
		pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2 + 54;
	}

		
	if (pos.y < 0) pos.y = 0;
	if (pos.y > CANVAS_HEIGHT) pos.y = CANVAS_HEIGHT;
}

void PacMan::update()
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
	else if (modern && !start)
	{
		updateMulti();
	}
}

// Setting drawing for start
void PacMan::drawInitC()
{
	if (start) timer += graphics::getDeltaTime();
	if (timer < 200)
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

void PacMan::updateMulti()
{
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		pos.y -= speed * graphics::getDeltaTime() / 50.f;
		updateUpM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		pos.y += speed * graphics::getDeltaTime() / 50.f;
		updateDownM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		pos.x -= speed * graphics::getDeltaTime() / 50.f;
		updateLeftM();
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		pos.x += speed * graphics::getDeltaTime() / 50.f;
		updateRightM();
	}

	if (pos.x < (CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2) + 39) pos.x = CANVAS_WIDTH / 2 - menu.maze->getWidth() / 2 + 39;
	if (pos.x > (CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2) - 35) pos.x = CANVAS_WIDTH / 2 + menu.maze->getWidth() / 2 - 35;
	if (pos.y < (CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2)) pos.y = CANVAS_HEIGHT / 2 - menu.maze->getHeight() / 2;
	if (pos.y > (CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2) - 57) pos.y = CANVAS_HEIGHT / 2 + menu.maze->getHeight() / 2 - 57;
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

void PacMan::drawPacmanM()
{
	if (rot == LEFT1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_1);
	}
	else if (rot == LEFT2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_2);
	}
	else if (rot == LEFT3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_LEFT_3);
	}
	else if (rot == DOWN1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_DOWN_1);
	}
	else if (rot == DOWN2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_DOWN_2);
	}
	else if (rot == DOWN3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_DOWN_3);
	}
	else if (rot == UP1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_UP_1);
	}
	else if (rot == UP2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_UP_2);
	}
	else if (rot == UP3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_UP_3);
	}
	else if (rot == RIGHT1)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_1);
	}
	else if (rot == RIGHT2)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_2);
	}
	else if (rot == RIGHT3)
	{
		brush.texture = std::string(ASSET_PATH) + std::string(PACMAN_M_RIGHT_3);
	}
}

Disk PacMan::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos.x;
	disk.cy = pos.y;
	disk.radius = 12.5f;
	return disk;
}

void PacMan::draw()
{
	if (start && !modern)
	{
		drawInitC();
	}
	else if (!start && !modern)
	{
		drawPacmanC();
	}
	else if (start && modern)
	{
		drawInitM();
	}
	else if (!start && modern)
	{
		drawPacmanM();
	}

	graphics::Brush br;
	brush.outline_opacity = 0.f;
	br.fill_color[0] = 0.5f;
	br.fill_color[1] = 1.f;
	br.fill_color[2] = 0.f;
	br.fill_opacity = 0.5f;
	br.gradient = false;
	disk = getCollisionHull();
	graphics::drawDisk(disk.cx, disk.cy, disk.radius, br);

	graphics::drawRect(pos.x, pos.y, 25, 25, brush);

	std::cout << pos.x << " " << pos.y << std::endl;
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	std::cout << mouse.cur_pos_x << " " << mouse.cur_pos_y << std::endl;
}

void PacMan::init()
{
}

PacMan::PacMan(const Menu& ingame)
	:GameElement(ingame)
{
	modern = menu.getModern(); // Getter in order not to do back to back calls (initialized and then remainds unchanged
	multi = menu.getMulti(); //  Getter in order not to do back to back calls (initialized and then remainds unchanged
	pos_grid = std::make_tuple(19, 23);
}

PacMan::~PacMan()
{
}
