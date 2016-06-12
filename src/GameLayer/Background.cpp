#include "GameLayer/Background.h"
#include "GameConstants.h"
#include "SDL2/SDL_image.h"

Background::Background(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
    m_scroller = 0;
    //m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED );
}

Background::~Background()
{
    SDL_DestroyTexture(m_bg);
}

bool Background::init()
{
    bool success = false;

    SDL_Surface* raw_bg = IMG_Load("config/Backgrounds/space_bg.png");

    if(raw_bg != nullptr)
    {
        m_bg = SDL_CreateTextureFromSurface(m_Renderer,raw_bg);
        success = true;
    }

    return success;
}

void Background::update()
{
    //moving background
    m_scroller+=0.5;
    if(m_scroller > SCREEN_WIDTH)
    {
        m_scroller = 0.0;
    }
}

void Background::draw()
{
    SDL_Rect screenRectRight = {(int)m_scroller,0,SCREEN_WIDTH-(int)m_scroller,SCREEN_HEIGHT};
    SDL_Rect screenRectLeft = {0,0,(int)m_scroller,SCREEN_HEIGHT};

    SDL_Rect bgRight = {0,0,SCREEN_WIDTH-(int)m_scroller,SCREEN_HEIGHT};
    SDL_Rect bgLeft = {SCREEN_WIDTH-(int)m_scroller,0,(int)m_scroller,SCREEN_HEIGHT};

    SDL_RenderCopy(m_Renderer,m_bg,&bgRight,&screenRectRight);
    SDL_RenderCopy(m_Renderer,m_bg,&bgLeft,&screenRectLeft);
}
