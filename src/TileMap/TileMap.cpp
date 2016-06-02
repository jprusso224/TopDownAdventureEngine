#include "TileMap.h"

TileMap::TileMap()
{
    //ctor
}

TileMap::~TileMap()
{
    //dtor
}

bool TileMap::loadTileSheet(const char* filename)
{

    bool success = true;

	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* mapElement;
	//const tinyxml2::XMLAttribute* attribute;

    if(doc.LoadFile(filename) == tinyxml2::XML_NO_ERROR)
    {
    	//load map
    	mapElement = doc.FirstChildElement("map");
    	if(mapElement){

    		m_mapWidth = mapElement->IntAttribute("width");
    		m_mapHeight = mapElement->IntAttribute("height");
    		m_tileWidth = mapElement->IntAttribute("tilewidth");
    		m_tileHeight = mapElement->IntAttribute("tileheight");

    		std::vector<int> firstGID;
    		tinyxml2::XMLElement* tileSetElement = mapElement->FirstChildElement("tileset");

    		while(tileSetElement)
    		{
    			firstGID.push_back(tileSetElement->IntAttribute("firstgid"));
    			tileSetElement = tileSetElement->NextSiblingElement("tileset");
    			std::cout << firstGID.back() << std::endl;
    		}

    	}

	}
	else
	{
		std::cout<< "Failed to load XML" << std::endl;
		success = false;
	}

	return success;

}
