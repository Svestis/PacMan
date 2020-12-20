#pragma once

#include <random>

float rand0to1();

struct Disk
{
	float cx, cy;
	float radius;
};
//TODO: Add util function to initialize all images before used (to be used for all brushes / pass a brush pointer)