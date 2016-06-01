#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState
{
    public:
        GameState();
        virtual ~GameState();

        int getState();
        void setState(int state);

    protected:

        int m_state;
    private:

};

#endif // GAMESTATE_H
