#include "TileSet.h"
#include "TileConstants.h"

#include "SDL2/SDL_image.h"

TileSet::TileSet()
{
    m_firstGid = 0;
    m_numGids = 0;
    m_name = std::string();
    m_tileWidth = 0;
    m_tileHeight = 0;
    m_width = 0;
    m_height = 0;
    m_imageName = std::string();
}

TileSet::~TileSet()
{
    //clean up map... need to free surfaces then empty
    for(unsigned int i = 0;i < m_tileSetImageMap.size();i++)
    {
        SDL_FreeSurface(m_tileSetImageMap[i]);
    }
}

bool TileSet::loadImage()
{
    bool success = true;

    std::string fullpath = TileSheet::TILESHEET_PATH+m_imageName;

    printf("Loading tileset: %s\n",fullpath.c_str());

    SDL_Surface* tileSetSurface = IMG_Load(fullpath.c_str());

    if(tileSetSurface == nullptr)
    {
        printf( "Failed to load tileset! SDL_image Error: %s\n", IMG_GetError() );
        success = false;
    }
    else
    {
        success = loadImageToSubmap(tileSetSurface);
    }

    SDL_FreeSurface(tileSetSurface);

    return success;
}

bool TileSet::loadImageToSubmap(SDL_Surface* tileSetSurface)
{
    bool success = true;
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.w = m_tileWidth;
    srcRect.h = m_tileHeight;
    srcRect.y = 0;

    destRect.w = m_tileWidth;
    destRect.h = m_tileHeight;
    destRect.x = 0;
    destRect.y = 0;

    unsigned int column = 0;

    for(unsigned int i = 0; i <= m_numGids; i++)
    {
        srcRect.x += column*m_tileWidth;

        //copy image
        SDL_Surface* subSurface = new SDL_Surface;
        SDL_BlitSurface(tileSetSurface,&srcRect,subSurface,&destRect);

        m_tileSetImageMap[i] = subSurface;

        column++;
        if(column < m_numCols)
        {
            column = 0;
            srcRect.y+=m_tileHeight;
            srcRect.x = 0;
        }
    }

    return success;
}

SDL_Surface* TileSet::getTileFromGid(unsigned int gid)
{
    SDL_Surface* tile = NULL;

    if(gid > 0 && gid <= m_numGids)
    {
        tile = m_tileSetImageMap[gid];
    }

    return tile;
}
