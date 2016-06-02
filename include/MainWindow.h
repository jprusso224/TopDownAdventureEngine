#ifndef MAINMEDIAHANDLER_H
#define MAINMEDIAHANDLER_H

#include <SDL2/SDL.h>

#include "InputHandler.h"
#include "GameLayer/HUD.h"
#include "GameLayer/Background.h"
#include "GameLayer/ObjectLayer.h"
#include "GameLayer/TileLayer.h"
#include "GameConstants.h"

class MainWindow
{
    public:
        MainWindow();
        virtual ~MainWindow();

        bool init();

        void update();

        void draw();

        void close();

    protected:

    private:

        SDL_Window* gWindow; /**The window we'll be rendering to*/

        SDL_Renderer* m_Renderer; /**The renderer we'll be windowing to*/

        HUD* m_HUD;
        Background* m_background;
        TileLayer* m_tileLayer;
        ObjectLayer* m_objectLayer;
};

#endif // MAINMEDIAHANDLER_H
