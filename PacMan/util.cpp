#include "util.h"

float rand0to1()
{
	return rand() / (float)RAND_MAX;
}

float width_to_x(float width, float numerator)
{
	return width * numerator / 100.f;
}

float height_to_y(float height, float numerator)
{
	return height * numerator / 100.f;
}