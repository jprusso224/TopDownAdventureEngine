#ifndef TILEMAP_H
#define TILEMAP_H

#include <stdint.h>
#include <vector>
#include <iostream>
#include <list>

#include "TinyXML/tinyxml2.h"

#include "TileMap.h"
#include "TileLayer.h"
#include "TileSet.h"

//TODO: Why do I have to forward declare this???
class TileLayer;
class TileSet;

class TileMap
{
    public:
        TileMap();
        virtual ~TileMap();

        bool loadTileSheet(const char* filename);

    protected:

    private:

    uint16_t m_mapWidth;
	uint16_t m_mapHeight;
	uint8_t m_tileWidth;
	uint8_t m_tileHeight;

	std::list<TileSet*> m_tileSetList;
	std::list<TileLayer*> m_tileLayerList;

};

#endif // TILEMAP_H
