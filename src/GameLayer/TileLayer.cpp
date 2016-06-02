#include "GameLayer/TileLayer.h"
#include "TileConstants.h"

TileLayer::TileLayer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
    m_tileMap = new TileMap();
}

TileLayer::~TileLayer()
{

}

bool TileLayer::init()
{
    bool success = true;

    success = m_tileMap->loadTileSheet(TileSheet::TILESHEET_NAME);

    return success;
}

void TileLayer::update()
{

    //Handle business logic
}

void TileLayer::draw()
{
    //nothing for now
}
