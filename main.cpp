#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <unistd.h>
#include "MainWindow.h"
#include "InputHandler.h"

int main ( int argc, char** argv )
{

    InputHandler* inputHandler = new InputHandler();
    MainWindow* mainWindow = new MainWindow();

    Mix_Music *music = nullptr;
    //Start up SDL and create window

    if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        bool done = false;

        if( !mainWindow->init() )
        {
            printf( "Failed to initialize main window!\n" );
            done = true;
        }

        if(inputHandler->init() == false)
        {
            printf("SDL could not initialize controller, using keyboard/mouse.\n");
        }

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        }

        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
                //Load music
        music = Mix_LoadMUS( "config/Sounds/Db_Phrigian.wav" );
        if( music == NULL )
        {
            printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        }

        Mix_PlayMusic(music,-1);

        /********* THIS IS THE MAIN GAME LOOP ********************/
        printf("Entering main loop! Good luck! \n");

        while (!done)
        {
            // message processing loop
            if(inputHandler->processEvent() == ProcessEventType::CLOSE_EVENT)
            {
                done = true;
                break;
            }

            mainWindow->update();
            mainWindow->draw();

        }
        /*********END MAIN LOOP***********************************/

    }

    //Clean up
    mainWindow->close();
    inputHandler->close();

    SDL_Quit();
    IMG_Quit();

    delete inputHandler;
    delete mainWindow;

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;

}
