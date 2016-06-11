#include "TileMap/TileMap.h"
#include "TileMap/Tile.h"


TileMap::TileMap(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

TileMap::~TileMap()
{
    m_tileLayerList.clear();
    m_tileSetList.clear();
}

bool TileMap::loadTileSheet(const char* filename)
{

    bool success = true;

	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* mapElement;

    if(doc.LoadFile(filename) == tinyxml2::XML_NO_ERROR)
    {
    	//load map
    	mapElement = doc.FirstChildElement("map");
    	if(mapElement){

    		m_mapWidth = mapElement->IntAttribute("width");
    		m_mapHeight = mapElement->IntAttribute("height");
    		m_tileWidth = mapElement->IntAttribute("tilewidth");
    		m_tileHeight = mapElement->IntAttribute("tileheight");

    		tinyxml2::XMLElement* tileSetElement = mapElement->FirstChildElement("tileset");
    		while(tileSetElement != nullptr)
    		{
                auto tileSet = new TileSet(m_Renderer);
                tileSet->Set_firstGid(tileSetElement->IntAttribute("firstgid"));
                tileSet->Set_name(std::string(tileSetElement->Attribute("name")));
                tileSet->Set_tileWidth(tileSetElement->IntAttribute("tilewidth"));
                tileSet->Set_tileHeight(tileSetElement->IntAttribute("tileheight"));
                tileSet->Set_numGids(tileSetElement->IntAttribute("tilecount"));
                tileSet->Set_numCols(tileSetElement->IntAttribute("columns"));

                tinyxml2::XMLElement* img = tileSetElement->FirstChildElement("image");
                if(img != nullptr)
                {
                    tileSet->Set_imageName(std::string(img->Attribute("source")));
                    tileSet->Set_width(img->IntAttribute("width"));
                    tileSet->Set_height(img->IntAttribute("height"));
                }
                else
                {
                    success = false;
                }

                m_tileSetList.push_back(tileSet);
    			tileSetElement = tileSetElement->NextSiblingElement("tileset");
    		}

            tinyxml2::XMLElement* tileLayerElement = mapElement->FirstChildElement("layer");
    		while(tileLayerElement != nullptr)
    		{
                TileLayer* tileLayer = new TileLayer();
                tileLayer->Set_name(tileLayerElement->Attribute("name"));
                tileLayer->Set_width(tileLayerElement->IntAttribute("width"));
                tileLayer->Set_height(tileLayerElement->IntAttribute("height"));

                tinyxml2::XMLElement* data = tileLayerElement->FirstChildElement("data");
                if(data != nullptr)
                {
                    tinyxml2::XMLElement* tile = data->FirstChildElement("tile");
                    std::vector<uint16_t> tileList;
                    while(tile != nullptr)
                    {
                        tileList.push_back(tile->IntAttribute("gid"));
                        tile = tile->NextSiblingElement("tile");
                    }
                    tileLayer->Set_data(tileList);
                }
                else
                {
                    success = false;
                }

                m_tileLayerList.push_back(tileLayer);
    			tileLayerElement = tileLayerElement->NextSiblingElement("layer");
    		}

    	}


        printf("Loaded tilemap!\n");
	}
	else
	{
		printf("Failed to load tile map!\n");
		success = false;
	}

	return success;

}

bool TileMap::loadTileSets()
{
    bool success = true;

    //iterate through tileset list and return false if ANY fail.
    for(TileSet* tileSet : m_tileSetList)
    {
        success &= tileSet->loadImage();
    }

    for(auto layer : m_tileLayerList )
    {
        success &= layer->setupLayer();
    }

    return success;
}

/**determine positions, etc*/
void TileMap::update()
{

}

/**Get the images and rendercopy*/
void TileMap::draw()
{

   for(TileLayer* layer : m_tileLayerList)
    {
        std::vector<Tile*> tiles = layer->Get_tiles();
        unsigned int numTiles = layer->Get_width() * layer->Get_height();

        int tileWidth = 0;
        int tileHeight = 0;

        for (unsigned int i = 0; i < numTiles; i++)
        {

            int gid = tiles[i]->Get_gid();
            SDL_Texture* tile = nullptr;


            for( TileSet* tileSet : m_tileSetList)
            {
                tile = tileSet->getTileFromGid(gid);
                if(tile != nullptr)
                {
                    tileHeight = tileSet->Get_tileHeight();
                    tileWidth = tileSet->Get_tileWidth();
                    break;
                }
            }

            if(tile != nullptr)
            {

                int x = tiles[i]->Get_x();
                int y = tiles[i]->Get_y();

                SDL_Rect tileRect = {0,0,tileWidth,tileHeight};
                SDL_Rect windowRect = {x*tileWidth,y*tileHeight,tileWidth,tileHeight};

                SDL_RenderCopy(m_Renderer,tile,&tileRect,&windowRect);

            }

        }

        tiles.clear();

    }


}
