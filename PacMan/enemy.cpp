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
