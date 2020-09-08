#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "GamePhysics.hpp"
#include "ConsoleOutput.hpp"

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();
    void starGameLoop();
    void addObcet(IObject* obj);

private:
    void renderField();

    GamePhysics mGamePhysics;
    uint8_t** mFildArray;
    const uint8_t ySize = 25;
    const uint8_t xSize = 100;
};

#endif // GAME_ENGINE_HPP
