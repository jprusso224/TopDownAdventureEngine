#include "InputHandler.h"
using namespace XBOX_CONTROLLER;

InputHandler::InputHandler() : m_controller(nullptr)
{

}

InputHandler::~InputHandler()
{
    //dtor
}

bool InputHandler::init()
{
    bool success = false;

    //Check for joysticks
    printf("Num sticks: %d\n",SDL_NumJoysticks());

    if( SDL_NumJoysticks() < 1 )
    {
        printf( "Warning: No joysticks connected!\n" );
    }
    else
    {
        //Load joystick
        m_controller = SDL_JoystickOpen(0);
        if( m_controller == nullptr )
        {
            printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            success = true;
        }
    }

    return success;

}

ProcessEventType InputHandler::processEvent()
{
    ProcessEventType results = ProcessEventType::NO_EVENT;
    SDL_Event event;

    SDL_PollEvent(&event);
    // check for messages
    switch (event.type)
    {
  //  case SDL_QUIT:
    //    results = ProcessEventType::CLOSE_EVENT;
   //     break;

        // check for keypresses
    case SDL_KEYDOWN:
        {
            // exit if ESCAPE is pressed
            if (event.key.keysym.sym == SDLK_ESCAPE)
                results = ProcessEventType::CLOSE_EVENT;
            break;
        }
    default:

//        processControllerInput();
        break;
    } // end switch

    return results;
}

void InputHandler::close()
{
    SDL_JoystickClose(m_controller);
}
