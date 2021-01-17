/**
* FILE: gameelement.cpp
* TITLE: gamelement class cpp file
*
* PURPOSE:
*
* Base Constructor implementation of gameelement 
*
* INCLUDED FILES:
*
* gamelement.h
* menu.h
*
* @file gameelement.h
**/

#include "gameelement.h"
#include "menu.h"

/**
* Base Construcctor for the game element class
*
* NAME: GameElement
*
* @param ingame
* @param_type Menu reference
* @return an instance of the child class that called the game constructor,  with a reference to the Menu running instance
* @rtype child class instance
*
**/
GameElement::GameElement(const Menu& ingame)
	:menu(ingame)
{
}
