#include "enemy.h"
#include "config.h"
#include "util.h"
#include "game.h"

void Enemy::update()
{
	pos_x -= speed * graphics::getDeltaTime();
	rotation += 0.05f * graphics::getDeltaTime();
	rotation = fmodf(rotation, 360);
	if (pos_x < -size) active = false;
}

void Enemy::draw()
{
	graphics::setOrientation(rotation);
	brush.fill_opacity = 0.2f;
	brush.texture = std::string(ASSET_PATH) + std::string(PAC0);
	graphics::drawRect(pos_x-10, pos_y+30, size, size, brush);
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + std::string(PAC0);
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	graphics::resetPose();

	/*
	graphics::Brush br;
	br.outline_opacity = 1.f;
	br.texture = "";
	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;

	Disk hull = getCollisionHull();

	graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);*/
}

void Enemy::init()
{
	speed = 0.1f;
	pos_x = CANVAS_WIDTH + 1.1f * size;
	pos_y = CANVAS_HEIGHT * rand0to1();
	size = 50 + 100 * rand0to1();
	rotation = 360 * rand0to1();
	brush.outline_opacity = 0.0f;
}

Enemy::Enemy(const Game& game)
	:GameObject(game)
{
	init();
}

Enemy::~Enemy()
{
}

/*Disk Enemy::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size*0.55;
	return disk;
}
*/