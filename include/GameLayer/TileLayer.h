#ifndef TILELAYER_H
#define TILELAYER_H

#include <GameLayer/GameLayer.h>

#include "TileMap.h"

class TileLayer : public GameLayer
{
    public:
        TileLayer(SDL_Renderer* renderer);
        virtual ~TileLayer();

        bool init() override;
        void update() override;
        void draw() override;

    protected:

    private:
        TileMap* m_tileMap;

};

#endif // TILELAYER_H
