#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "GamePhysics.hpp"
#include "ConsoleOutput.hpp"

class GameEngine
{
public:
    GameEngine();
    void starGameLoop();
    void addObcet(IObject* obj);

private:
    void renderField();

    GamePhysics mGamePhysics;
    ConsoleOutput mConsoleOutput;
    uint8_t** mField;
};

#endif // GAME_ENGINE_HPP
