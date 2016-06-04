#ifndef TILESET_H
#define TILESET_H

#include <string>

class TileSet
{
    public:
        TileSet();
        virtual ~TileSet();

        /** Getters & Setters */
        unsigned int Get_firstGid() { return m_firstGid; }
        void Set_firstGid(unsigned int val) { m_firstGid = val; }
        const char* Get_name() { return m_name; }
        void Set_name(const char* val){m_name = val;}
        uint8_t Get_tileWidth() { return m_tileWidth; }
        void Set_tileWidth(uint8_t val) { m_tileWidth = val; }
        uint8_t Get_tileHeight() { return m_tileHeight; }
        void Set_tileHeight(uint8_t val) { m_tileHeight = val; }
        uint16_t Get_width() { return m_width; }
        void Set_width(uint16_t val) { m_width = val; }
        uint16_t Get_height() { return m_height; }
        void Set_height(uint16_t val) { m_height = val; }
        const char* Get_imageName() { return m_imageName; }
        void Set_imageName(const char* val) { m_imageName = val; }
        /** End Getters & Setters */

    protected:

    private:
        unsigned int m_firstGid;
        const char* m_name;
        uint8_t m_tileWidth;
        uint8_t m_tileHeight;
        uint16_t m_width;
        uint16_t m_height;
        const char* m_imageName;
};

#endif // TILESET_H
