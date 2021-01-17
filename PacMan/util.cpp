/**
* FILE: util.cpp
* TITLE: util cpp file
*
* PURPOSE:
*
* This is contains general utility functions to be used accross different functions of the game
*
**FUNCTIONS:
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
* util.h
*
* @file util.cpp
**/
#include "util.h"

/**
* Random values normalized between 0 and 1
*
* NAME: rand0to1
*
* @param none
* @return a random number between 0 and 1
* @rtype float
*
**/
float rand0to1()
{
	return rand() / (float)RAND_MAX;
}

/**
* return a number of calculated percentage on x axis
*
* NAME: width_to_x
*
* @param width (the width that we want to modify)
* @param_type float
* @param numerator the percentage
* @param_type float
* @return the points of the modified width
* @rtype float
*
**/
float width_to_x(float width, float numerator)
{
	return width * numerator / 100.f;
}

/**
* return a number of calculated percentage on y axis
*
* NAME: height_to_y
*
* @param height (the height that we want to modify)
* @param_type float
* @param numerator the percentage
* @param_type float
* @return the points of the modified height
* @rtype float
*
**/
float height_to_y(float height, float numerator)
{
	return height * numerator / 100.f;
}