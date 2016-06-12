#include "TileLayer.h"
#include "GameConstants.h"

TileLayer::TileLayer()
{

}

TileLayer::~TileLayer()
{
    //dtor
}

bool TileLayer::setupLayer()
{

    unsigned int row = 0;
    unsigned int column = 0;

    for(unsigned int i = 0; i < m_data.size(); i++)
    {

        Tile* tile = new Tile();
        tile->Set_gid(m_data[i]);
        tile->Set_x(column);
        tile->Set_y(row);

        printf("X, Y, GID: %d,%d,%d \n",column,row,m_data[i]);

        m_tileVector.push_back(tile);

        column++;
        if(column >= m_width)
        {
            column = 0;
            row++;
        }

    }

    return true;
}

std::vector<Tile*> TileLayer::getTilesInView(int x, int y)
{
    //return the subset of tiles in viewport (on screen)
    std::vector<Tile*> inView;



    return inView;

}
