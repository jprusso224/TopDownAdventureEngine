#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <GameLayer/GameLayer.h>
#include <Player.h>


class ObjectLayer : public GameLayer
{
    public:
        ObjectLayer(SDL_Renderer* renderer);
        virtual ~ObjectLayer();

        bool init() override;
        void update() override;
        void draw() override;

    protected:

    private:

        Player * m_player;
};

#endif // OBJECTLAYER_H
