#pragma once

#include <random>

float rand0to1();
float height_to_y(float height, float numerator);
float width_to_x(float width, float numerator);

typedef enum { PINKY, BLINKY, INKY, CLYDE } character;

/*struct Disk
{
	float cx, cy;
	float radius;
};*/

//TODO: Add util function to initialize all images before used (to be used for all brushes / pass a brush pointer)
