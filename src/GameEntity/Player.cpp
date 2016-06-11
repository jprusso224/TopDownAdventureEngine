#include "Player.h"

Player::Player(SDL_Renderer* renderer,int x, int y)
{
    m_Renderer = renderer; // Maybe singleton this guy. There can only be one.

    m_x = x;
    m_y = y;
    m_dx = 0;
    m_dy = 0;
    m_direction = WindowDirection::DOWN;
}

Player::~Player()
{
    //dtor
}

bool Player::init()
{
    return true;
}

void Player::update()
{
    //look at controller state and set direction....
    int maxDirectionInput = 2;
    int numDirectionInput = 0;

    int numKeys;
   // SDL_GetKey
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(&numKeys);

     /** Key Checking, Update Velocity **/
    if(keyState[SDL_SCANCODE_W])
    {

        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_dy=-3;
            m_direction = WindowDirection::UP;
        }
    }
    if(keyState[SDL_SCANCODE_S])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_dy=3;
            m_direction = WindowDirection::DOWN;
        }
    }
    if(keyState[SDL_SCANCODE_D])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_dx=3;
            m_direction = WindowDirection::RIGHT;
        }
    }
    if(keyState[SDL_SCANCODE_A])
    {
        numDirectionInput++;
        if(numDirectionInput <= maxDirectionInput)
        {
            m_dx=-3;
            m_direction = WindowDirection::LEFT;
        }
    }

    /** Update Position **/
    m_x+=m_dx;
    m_y+=m_dy;

    m_dy = 0;
    m_dx = 0;


    /** Boundary Checking **/
    if(m_y > SCREEN_HEIGHT)
    {
        m_y = SCREEN_HEIGHT;
    }
    else if(m_y < 0)
    {
        m_y = 0;
    }
    if(m_x > SCREEN_WIDTH)
    {
        m_x = SCREEN_WIDTH;
    }
    else if(m_x < 0)
    {
        m_x = 0;
    }

}

void Player::draw()
{
    int x1, x2, x3, y1, y2, y3;
    bool draw = false;

    switch(m_direction)
    {
        case WindowDirection::UP:
            x1 = m_x;
            y1 = m_y-7;
            x2 = m_x-5;
            y2 = m_y+7;
            x3 = m_x+5;
            y3 = m_y+7;
            draw = true;
        break;
        case WindowDirection::DOWN:
            x1 = m_x;
            y1 = m_y+7;
            x2 = m_x-5;
            y2 = m_y-7;
            x3 = m_x+5;
            y3 = m_y-7;
            draw = true;
        break;
        case WindowDirection::RIGHT:
            x1 = m_x+7;
            y1 = m_y;
            x2 = m_x-7;
            y2 = m_y-5;
            x3 = m_x-7;
            y3 = m_y+5;
            draw = true;
        break;
        case WindowDirection::LEFT:
            x1 = m_x-7;
            y1 = m_y;
            x2 = m_x+7;
            y2 = m_y-5;
            x3 = m_x+7;
            y3 = m_y+5;
            draw = true;
        break;
        default:
            break;
    }

    if(draw)
    {
        filledTrigonRGBA(m_Renderer,x1,y1, x2, y2, x3, y3,250,0,0,254);
    }
}
