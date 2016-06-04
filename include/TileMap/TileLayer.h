#ifndef TILELAYER_H
#define TILELAYER_H

#include <stdint.h>
#include <string>
#include <list>

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
        std::list<uint16_t> Get_data() { return m_data; }
        void Set_data(std::list<uint16_t> val) { m_data = val; }

    protected:

    private:
        uint16_t m_width;
        uint16_t m_height;
        std::string m_name;
        std::list<uint16_t> m_data;
};

#endif // TILELAYER_H
