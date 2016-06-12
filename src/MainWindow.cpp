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
    delete m_mapLayer;
    delete m_objectLayer;
    delete m_Player;
    delete m_HUD;
}

bool MainWindow::init()
{
    //Initialization flag
    bool success = true;

    //Create window
    gWindow = SDL_CreateWindow( "Game Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

            m_mapLayer = new MapLayer(m_Renderer);
            if(m_mapLayer->init() == false)
            {
                printf("Tile layer failed to init.\n");
                success = false;
            }

            m_objectLayer = new ObjectLayer(m_Renderer);
            if(m_objectLayer->init() == false)
            {
                printf("Object layer failed to init.\n");
                success = false;
            }

            m_Player = new Player(m_Renderer,SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
            if(m_Player->init() == false)
            {
                printf("Player failed to init");
                success = false;
            }

            m_HUD = new HUD(m_Renderer);
            if(m_HUD->init() == false)
            {
                printf("HUD failed to init.\n");
                success = false;
            }

        }

    }

    return success;
}

void MainWindow::processInput()
{
    //look at controller state and set direction....
    int maxDirectionInput = 2;
    int numDirectionInput = 0;

    int numKeys;
   // SDL_GetKey
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(&numKeys);

     /** Key Checking **/
    if(keyState[SDL_SCANCODE_W])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_Player->ProcessActionSignal(PlayerActionSignal::PLAYER_MOVE_UP);
            m_mapLayer->processActionSignal(MapActionSignal::SCROLL_UP);
        }
    }
    if(keyState[SDL_SCANCODE_S])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_Player->ProcessActionSignal(PlayerActionSignal::PLAYER_MOVE_DOWN);
            m_mapLayer->processActionSignal(MapActionSignal::SCROLL_DOWN);
        }
    }
    if(keyState[SDL_SCANCODE_D])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_Player->ProcessActionSignal(PlayerActionSignal::PLAYER_MOVE_RIGHT);
            m_mapLayer->processActionSignal(MapActionSignal::SCROLL_RIGHT);
        }
    }
    if(keyState[SDL_SCANCODE_A])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_Player->ProcessActionSignal(PlayerActionSignal::PLAYER_MOVE_LEFT);
            m_mapLayer->processActionSignal(MapActionSignal::SCROLL_LEFT);
        }
    }
}

void MainWindow::update()
{

    processInput();
    m_background->update();
    m_mapLayer->update();
    m_objectLayer->update();
    m_Player->update();
    m_HUD->update();
}

void MainWindow::draw()
{
    m_background->draw();
    m_mapLayer->draw();
    m_objectLayer->draw();
    m_Player->draw();
    m_HUD->draw();

    SDL_RenderPresent( m_Renderer );
}

void MainWindow::close()
{

    SDL_DestroyRenderer(m_Renderer);

    //Destroy window
    SDL_DestroyWindow( gWindow );


}
