#include "GameState.h"

GameState::GameState()
{
    //ctor
}

GameState::~GameState()
{
    //dtor
}

int GameState::getState()
{
    return m_state;
}

void GameState::setState(int state)
{
    m_state = state;
}
