#ifndef TILELAYER_H
#define TILELAYER_H

#include <GameLayer/GameLayer.h>

#include "TileMap/TileMap.h"

class MapLayer : public GameLayer
{
public:
    MapLayer(SDL_Renderer* renderer);
    virtual ~MapLayer();

    bool init() override;
    void update() override;
    void draw() override;

protected:

private:
    TileMap* m_tileMap;

};

#endif // TILELAYER_H
