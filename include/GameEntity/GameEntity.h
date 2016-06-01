#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <SDL2/SDL2_gfxPrimitives.h>

class GameEntity
{
    public:
        GameEntity();

        virtual ~GameEntity();

        int Get_x() { return m_x; }
        void Set_x(int val) { m_x = val; }
        int Get_y() { return m_y; }
        void Set_y(int val) { m_y = val; }
        int Get_dx() { return m_dx; }
        void Set_dx(int val) { m_dx = val; }
        int Get_dy() { return m_dy; }
        void Set_dy(int val) { m_dy = val; }

        virtual bool init() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:
        int m_x;
        int m_y;
        int m_dx;
        int m_dy;

    private:

};

#endif // GAMEENTITY_H
