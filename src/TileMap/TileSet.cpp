#include "TileSet.h"
#include "TileConstants.h"

#include "SDL2/SDL_image.h"

TileSet::TileSet(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
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
    //clean up map... need to destroy textures
    for(unsigned int i = 0;i < m_tileSetImageMap.size();i++)
    {
        SDL_DestroyTexture(m_tileSetImageMap[i]);
    }
}

bool TileSet::loadImage()
{
    bool success = true;

    std::string fullpath = TileSheet::TILESHEET_PATH+m_imageName;

    printf("Loading tileset: %s\n",fullpath.c_str());

    SDL_Surface* tileSetSurface = IMG_Load("config/TileSheets/space.png");

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
    SDL_Rect srcRect = {0,0,m_tileWidth,m_tileHeight};
    SDL_Rect destRect = {0,0,m_tileWidth,m_tileHeight};

    unsigned int column = 0;

    SDL_Surface *tile = new SDL_Surface();

    for(unsigned int i = 0; i < m_numGids; i++)
    {
        srcRect.x += column*m_tileWidth;

        tile = SDL_ConvertSurface(tileSetSurface,tileSetSurface->format,0);

        SDL_BlitSurface(tileSetSurface,&srcRect,tile,&destRect);

        printf("Blitting surface: x,y to x2,y2: %d,%d to %d,%d\n",srcRect.x,srcRect.y,destRect.x,destRect.y);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer,tile);

        m_tileSetImageMap[i+1] = texture;

        column++;
        if(column >= m_numCols)
        {
            column = 0;
            srcRect.y+=m_tileHeight;
            srcRect.x = 0;
        }
    }

    SDL_FreeSurface(tile);

    return success;
}

SDL_Texture* TileSet::getTileFromGid(unsigned int gid)
{
    SDL_Texture* tile = NULL;

    if(gid > 0 && gid <= m_numGids)
    {
        tile = m_tileSetImageMap[gid];
    }

    return tile;
}
