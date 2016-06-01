#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include "GameConstants.h"
#include <SDL2/SDL.h>

class Player : public GameEntity
{
    public:
        Player(SDL_Renderer* renderer,int x, int y);
        virtual ~Player();

        virtual bool init() override;
        virtual void update() override;
        virtual void draw() override;

        WindowDirection getDirection();
        void setDirection(WindowDirection direction);

    protected:

    private:

        WindowDirection m_direction;
        SDL_Renderer* m_Renderer;

};

#endif // PLAYER_H
