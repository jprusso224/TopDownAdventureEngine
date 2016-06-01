#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>

#include "xbox_controller.h"

enum class ProcessEventType
{
    NO_EVENT = 0,
    CONTROL_EVENT,
    CLOSE_EVENT
};

class InputHandler
{
    public:

        InputHandler();
        virtual ~InputHandler();

        bool init();

        ProcessEventType processEvent();

        void close();

    protected:

    private:

        SDL_Joystick* m_controller;
};

#endif // INPUTHANDLER_H
