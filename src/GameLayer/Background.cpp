#include "GameLayer/Background.h"
#include "GameConstants.h"

Background::Background(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
    //m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED );
}

Background::~Background()
{

}

bool Background::init()
{
    bool success = true;

    //nothing yet

    return success;
}

void Background::update()
{

    //Handle business logic
}

void Background::draw()
{
    SDL_SetRenderDrawColor( m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_Rect fillRect = { 0, 0 ,SCREEN_WIDTH , SCREEN_HEIGHT };
    SDL_RenderFillRect( m_Renderer, &fillRect );
}
