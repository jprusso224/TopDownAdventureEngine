#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include "GameConstants.h"
#include <SDL2/SDL.h>

enum class PlayerActionSignal
{
    PLAYER_IDLE = 0,
    PLAYER_MOVE_UP,
    PLAYER_MOVE_DOWN,
    PLAYER_MOVE_RIGHT,
    PLAYER_MOVE_LEFT,
    PLAYER_ROLL,
    PLAYER_JUMP,
    PLAYER_FIRE_WEAPON,
    PLAYER_MELEE,
};

class Player : public GameEntity
{
    public:
        Player(SDL_Renderer* renderer,int x, int y);
        virtual ~Player();

        virtual bool init() override;
        virtual void update() override;
        virtual void draw() override;

        void ProcessActionSignal(PlayerActionSignal sig);

        WindowDirection getDirection();
        void setDirection(WindowDirection direction);

    protected:

    private:

        WindowDirection m_direction;
        SDL_Renderer* m_Renderer;

};

#endif // PLAYER_H
