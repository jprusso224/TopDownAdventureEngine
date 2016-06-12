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

void Player::ProcessActionSignal(PlayerActionSignal sig)
{
    switch(sig)
    {
        case PlayerActionSignal::PLAYER_IDLE:
        break;
        case PlayerActionSignal::PLAYER_MOVE_UP:
            m_direction = WindowDirection::UP;
        break;
        case PlayerActionSignal::PLAYER_MOVE_DOWN:
            m_direction = WindowDirection::DOWN;
        break;
        case PlayerActionSignal::PLAYER_MOVE_RIGHT:
            m_direction = WindowDirection::RIGHT;
        break;
        case PlayerActionSignal::PLAYER_MOVE_LEFT:
            m_direction = WindowDirection::LEFT;
        break;
        //UNIMPLEMENTED:
        case PlayerActionSignal::PLAYER_JUMP:
        case PlayerActionSignal::PLAYER_MELEE:
        case PlayerActionSignal::PLAYER_FIRE_WEAPON:
        case PlayerActionSignal::PLAYER_ROLL:
        default:
            break;
    }
}


void Player::update()
{


    /** Update Position **/
//    m_x+=m_dx;
 //   m_y+=m_dy;

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
