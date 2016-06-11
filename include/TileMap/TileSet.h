#ifndef TILESET_H
#define TILESET_H

#include "SDL2/SDL.h"

#include <string>
#include <map>

class TileSet
{
    public:
        TileSet(SDL_Renderer* renderer);
        virtual ~TileSet();

        /** Getters & Setters */
        unsigned int Get_firstGid() { return m_firstGid; }
        void Set_firstGid(unsigned int val) { m_firstGid = val; }
        unsigned int Get_numGids() { return m_numGids; }
        void Set_numGids(unsigned int val) { m_numGids = val; }
        unsigned int Get_numCols() { return m_numCols; }
        void Set_numCols(unsigned int val) { m_numCols = val; }
        std::string Get_name() { return m_name; }
        void Set_name(std::string val){m_name = val;}
        uint8_t Get_tileWidth() { return m_tileWidth; }
        void Set_tileWidth(uint8_t val) { m_tileWidth = val; }
        uint8_t Get_tileHeight() { return m_tileHeight; }
        void Set_tileHeight(uint8_t val) { m_tileHeight = val; }
        uint16_t Get_width() { return m_width; }
        void Set_width(uint16_t val) { m_width = val; }
        uint16_t Get_height() { return m_height; }
        void Set_height(uint16_t val) { m_height = val; }
        std::string Get_imageName() { return m_imageName; }
        void Set_imageName(std::string val) { m_imageName = val; }
        /** End Getters & Setters */

        bool loadImage();

        bool loadImageToSubmap(SDL_Surface* tileSetSurface);
        SDL_Texture* getTileFromGid(unsigned int gid);

    protected:

    private:
        SDL_Renderer* m_Renderer;
        unsigned int m_firstGid;
        unsigned int m_numGids;
        unsigned int m_numCols;
        std::string m_name;
        uint8_t m_tileWidth;
        uint8_t m_tileHeight;
        uint16_t m_width;
        uint16_t m_height;
        std::string m_imageName;

        std::map<int,SDL_Texture*> m_tileSetImageMap;
};

#endif // TILESET_H
