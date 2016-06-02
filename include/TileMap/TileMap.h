#ifndef TILEMAP_H
#define TILEMAP_H

#include <stdint.h>
#include "TinyXML/tinyxml2.h"
#include <vector>
#include <iostream>

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

};

#endif // TILEMAP_H
