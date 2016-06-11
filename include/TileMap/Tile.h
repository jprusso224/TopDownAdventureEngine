#ifndef TILE_H
#define TILE_H


class Tile
{
    public:
        Tile();
        virtual ~Tile();

        unsigned int Get_x(){return m_x;}
        void Set_x(unsigned int val){m_x = val;}
        unsigned int Get_y(){return m_y;}
        void Set_y(unsigned int val){m_y = val;}
        unsigned int Get_gid(){return m_gid;}
        void Set_gid(unsigned int val){m_gid = val;}

    protected:

    private:
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_gid;

};

#endif // TILE_H
