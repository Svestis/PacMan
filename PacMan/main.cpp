/**
* FILE: main.cpp
* TITLE: main function
*
* PURPOSE: 
* 
* This is the main function, initializing the main programme class (Menu) and creating the window. Needed functions are also defined here by calling
* the associated functios of the main programme class (Menu)
*
* FUNCTIONS:
*
* resize
*   resing the window according to the dragging of the user (or the use of full screen button) by calling the resize function of a Menu instance
*
* update
*   calling the update function of a Menu instance
*
* draw
*   calling the draw function of a Menu instance
*
* main
*   creating an instance of the Menu class, creating the window and calling the resize, update and draw functions of main.cpp
*
* INCLUDED FILES:
*
* graphics.h
* config.h
* menu.h
*
* @file main.cpp 
**/

#include "graphics.h"
#include "config.h"
#include "menu.h"

/**
* Defining the function that will be used in order to resize the window
*
* NAME: resize
*
* @param w the width to resize to
* @param_type int
* @param h the height to resize to
* @param_type int
* @return none
*
**/
void resize(int w, int h)
{
    Menu* menu = reinterpret_cast<Menu*>(graphics::getUserData()); // Defining the menu
    menu->setWindowDimensions((unsigned short int)w, (unsigned short int)h); // Defining the menu resize function
}

/**
* Defining the function that will be used in order to update the window
*
* NAME: update
*
* @param ms the time interval for window update (in ms)
* @param_type float
* @return none
*
**/
void update(float ms)
{
    Menu* menu = reinterpret_cast<Menu*>(graphics::getUserData()); // Defining the menu
    menu->update(); // Defining the menu update function
}

/**
* Defining the function that will be used in order to draw the window
*
* NAME: update
*
* @param none
* @return none
*
**/
void draw()
{
    Menu* menu = reinterpret_cast<Menu*>(graphics::getUserData()); // Defining the menu
    menu->draw(); // Defining the menu draw function
}

/**
* Main function, creating an instace of the game and handling window
*
* NAME: main
*
* @param none
* @return none
*
**/
int main()
{
    Menu menu;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PacMan"); /* Creating the window */

    graphics::setUserData(&menu); // Setting user data

    graphics::setDrawFunction(draw); // Setting draw function
    graphics::setUpdateFunction(update); // Setting update function
    graphics::setResizeFunction(resize); // Setting the resize function

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT); // Setting the size of the canvas
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT); // Setting the canvas scale mode
    
    menu.init(); // Calling the menu init function

    graphics::startMessageLoop(); // Starting the message pump loop for the application window
    graphics::destroyWindow(); // Destroying window on finish

    return 0;
}