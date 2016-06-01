#ifndef GAMELAYER_H
#define GAMELAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class GameLayer
{

    public:

        GameLayer(){};
        ~GameLayer(){};

        virtual bool init() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:

        SDL_Renderer* m_Renderer;

};

#endif // GAMELAYER_H
