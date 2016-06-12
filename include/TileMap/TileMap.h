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
        TileMap(SDL_Renderer* renderer);
        virtual ~TileMap();

        bool loadTileSheet(const char* filename);
        bool loadTileSets();

        /**determine positions, etc*/
        void update();

        /**Get the images and rendercopy*/
        void draw();

        void scrollUp(){m_Ymap-=2;}
        void scrollDown(){m_Ymap+=2;}
        void scrollRight(){m_Xmap+=2;}
        void scrollLeft(){m_Xmap-=2;}

    protected:

    private:

    uint16_t m_mapWidth;
	uint16_t m_mapHeight;
	uint8_t m_tileWidth;
	uint8_t m_tileHeight;

	int m_Xmap;
	int m_Ymap;

	std::vector<TileSet*> m_tileSetList;
	std::vector<TileLayer*> m_tileLayerList;

	SDL_Renderer* m_Renderer;

};

#endif // TILEMAP_H
