#ifndef TILELAYER_H
#define TILELAYER_H

#include <stdint.h>
#include <string>
#include <vector>

#include "Tile.h"

class TileLayer
{
    public:
        TileLayer();
        virtual ~TileLayer();

        /** Getters & Setters */
        uint16_t Get_width() { return m_width; }
        void Set_width(uint16_t val) { m_width = val; }
        uint16_t Get_height() { return m_height; }
        void Set_height(uint16_t val) { m_height = val; }
        std::string Get_name() { return m_name; }
        void Set_name(std::string val) { m_name = val; }
        std::vector<uint16_t> Get_data() { return m_data; }
        void Set_data(std::vector<uint16_t> val) { m_data = val; }
        std::vector<Tile*> Get_tiles() { return m_tileVector; }
        void Set_tiles(std::vector<Tile*> val) { m_tileVector = val; }

        bool setupLayer();
        std::vector<Tile*> getTilesInView(int x, int y);

    protected:

    private:
        uint16_t m_width;
        uint16_t m_height;
        std::string m_name;
        std::vector<uint16_t> m_data;
        std::vector<Tile*> m_tileVector;

};

#endif // TILELAYER_H
