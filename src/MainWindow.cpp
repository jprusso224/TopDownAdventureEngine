#include <stdlib.h>
#include <stdio.h>

#include "MainWindow.h"

MainWindow::MainWindow()
{
    //ctor
}

MainWindow::~MainWindow()
{
    delete m_background;
}

bool MainWindow::init()
{
    //Initialization flag
    bool success = true;

    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {

        m_Renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC  );
        if(m_Renderer == nullptr)
        {
            printf("Failed to create renderer\n");
            success = false;
        }
        else
        {
            SDL_SetRenderDrawBlendMode(m_Renderer,SDL_BLENDMODE_BLEND);

            m_background = new Background(m_Renderer);
            if(m_background->init() == false)
            {
                printf("Background failed to init.\n");
                success = false;
            }

            m_HUD = new HUD(m_Renderer);
            if(m_HUD->init() == false)
            {
                printf("HUD failed to init.\n");
                success = false;
            }

            m_objectLayer = new ObjectLayer(m_Renderer);
            if(m_objectLayer->init() == false)
            {
                printf("Object layer failed to init.\n");
                success = false;
            }

        }

    }

    return success;
}

void MainWindow::update()
{
    m_background->update();
    m_objectLayer->update();
    m_HUD->update();

}

void MainWindow::draw()
{
    m_background->draw();
    m_objectLayer->draw();
    m_HUD->draw();

    SDL_RenderPresent( m_Renderer );
}

void MainWindow::close()
{

    SDL_DestroyRenderer(m_Renderer);
    m_Renderer = nullptr;
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;

}
