#ifndef TILELAYER_H
#define TILELAYER_H

#include <GameLayer/GameLayer.h>

#include "TileMap/TileMap.h"

enum class MapActionSignal
{
    NO_SCROLL = 0,
    SCROLL_UP,
    SCROLL_DOWN,
    SCROLL_RIGHT,
    SCROLL_LEFT
};

class MapLayer : public GameLayer
{
public:
    MapLayer(SDL_Renderer* renderer);
    virtual ~MapLayer();

    void processActionSignal(MapActionSignal sig);

    bool init() override;
    void update() override;
    void draw() override;

protected:

private:
    TileMap* m_tileMap;

};

#endif // TILELAYER_H
