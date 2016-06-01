
namespace XBOX_CONTROLLER
{

    enum class ControllerAxe{

    LEFT_STICK_X_AXIS = 0,
    LEFT_STICK_Y_AXIS = 1,

    LEFT_TRIGGER = 2,
    RIGHT_TRIGGER = 3,

    RIGHT_STICK_X_AXIS = 4,
    RIGHT_STICK_y_AXIS = 5

    };

    static const uint8_t DPAD_UP = 0x01;
    static const uint8_t DPAD_RIGHT = 0x02;
    static const uint8_t DPAD_DOWN = 0x04;
    static const uint8_t DPAD_LEFT = 0x08;

    enum class Button{

        BUTTON_A = 0,
        BUTTON_B = 1,
        BUTTON_X = 2,
        BUTTON_Y = 3,
        BUTTON_LEFT_BUMPER = 4,
        BUTTON_RIGHT_BUMPER = 5,
        BUTTON_BACK = 6,
        BUTTON_START = 7,
        BUTTON_HOME = 8,
        BUTTON_LEFT_STICK = 9,
        BUTTON_RIGHT_STICK = 10

    };

}
