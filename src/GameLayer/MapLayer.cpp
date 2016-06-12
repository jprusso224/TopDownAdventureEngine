#include "GameLayer/MapLayer.h"
#include "TileConstants.h"

MapLayer::MapLayer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
    m_tileMap = new TileMap(m_Renderer);
}

MapLayer::~MapLayer()
{
    delete m_tileMap;
}

bool MapLayer::init()
{
    bool success = false;

    std::string fullpath = TileSheet::TILESHEET_PATH + TileSheet::TILESHEET_NAME;

    if(m_tileMap->loadTileSheet(fullpath.c_str()) == true)
    {
        success = m_tileMap->loadTileSets();
    }

    return success;
}

void MapLayer::processActionSignal(MapActionSignal sig)
{
    switch(sig)
    {
        case MapActionSignal::SCROLL_UP:
            m_tileMap->scrollUp();
        break;
        case MapActionSignal::SCROLL_DOWN:
            m_tileMap->scrollDown();
        break;
        case MapActionSignal::SCROLL_RIGHT:
            m_tileMap->scrollRight();
        break;
        case MapActionSignal::SCROLL_LEFT:
            m_tileMap->scrollLeft();
        break;
        case MapActionSignal::NO_SCROLL:
        default:
            break;
    }
}

void MapLayer::update()
{

    //Handle business logic
}

void MapLayer::draw()
{
    m_tileMap->draw();
}
