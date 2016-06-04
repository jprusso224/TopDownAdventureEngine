#include "GameLayer/MapLayer.h"
#include "TileConstants.h"

MapLayer::MapLayer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
    m_tileMap = new TileMap();
}

MapLayer::~MapLayer()
{

}

bool MapLayer::init()
{
    bool success = true;

    success = m_tileMap->loadTileSheet(TileSheet::TILESHEET_NAME);

    return success;
}

void MapLayer::update()
{

    //Handle business logic
}

void MapLayer::draw()
{
    //nothing for now
}
