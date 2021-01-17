/**
* FILE: util.h
* TITLE: util
*
* PURPOSE:
*
* Including all utility functions
*
*FUNCTIONS:
*
* rand0to1
*	normalizing rand values in values between 0 and 1
*
* height_to_y
*	screen height to actual y
*
* width_to_x
*	screen width to actual y
*
* INCLUDED FILES:
*
* random
*
* @file util.h
**/

#pragma once

#include <random>

float rand0to1(); // random values to values between 0 to 1
float height_to_y(float height, float numerator); // screen heigh to actual y
float width_to_x(float width, float numerator); // screne width to actual x

typedef enum { PINKY, BLINKY, INKY, CLYDE } character; // character enum values
