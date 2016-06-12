#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <GameLayer/GameLayer.h>


class Background : public GameLayer
{
    public:
        Background(SDL_Renderer* renderer);
        virtual ~Background();

        bool init() override;
        void update() override;
        void draw() override;

    protected:

    private:

        SDL_Texture* m_bg;
        float m_scroller;
};

#endif // BACKGROUND_H
