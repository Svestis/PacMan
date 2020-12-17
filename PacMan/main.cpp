#include "graphics.h"
#include "game.h"
#include "config.h"
#include "console.h"

/* Setting the main update function */
void update(float ms)
{
    /*Game* game = reinterpret_cast<Game *>(graphics::getUserData());
    game->update();*/
    Console* console = reinterpret_cast<Console *>(graphics::getUserData());
    console->update();
}

/* Setting the main draw function */
void draw()
{
    /*Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->draw();*/
    Console* console = reinterpret_cast<Console *>(graphics::getUserData());
    console->draw();
}

/* Main function, creating an instace of the game and handling window*/
int main()
{
    /*Game game;*/ /* Creating a game class instance */

    Console console; /* Creating a menu class instance*/

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PacMan"); /* Creating the window */
    /*graphics::setFullScreen(1);*/ /* Setting the window to full screen */
    //TODO: User selection is neccessary

    /*graphics::setUserData(&game);*/ /* Setting user data */

    graphics::setUserData(&console); /* Setting user data */

    graphics::setDrawFunction(draw); /* Setting draw function */
    graphics::setUpdateFunction(update); /* Setting update function */

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT); /* Setting the size of the canvas */
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT); /* Setting the canvas scale mode */

    /*game.init();*/ /*Initializing game*/

    console.init(); /* Initializing the game */

    graphics::startMessageLoop(); /* Starting the message pump loop for the application window */
    graphics::destroyWindow(); /* Destroying window on finish */

    return 0;
}