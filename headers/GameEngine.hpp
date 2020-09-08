#if !defined(_GAMEENGINE_H)
#define _GAMEENGINE_H

#include "ConsoleOutput.hpp"
#include "MicroStopwatch.hpp"
#include <list>
#include"IObject.hpp"


class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void starGameLoop();
    void addObcet(IObject* obj);
private:
    uint8_t** mFildArray;
    std::list<IObject*> mObjectList;
    const uint8_t mFieldSizeY = 25;
    const uint8_t mFieldSizeX = 100;
    void renderField();
};

#endif  //_GAMEENGINE_H
