#if !defined(_GAMEENGINE_H)
#define _GAMEENGINE_H

#include "ConsoleOutput.hpp"
#include "MicroStopwatch.hpp"
#include"IObject.hpp"
#include "Tools.hpp"

#include <list>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void starGameLoop();
    void addObcet(IObject* obj);

private:
    void renderField();
    void drawObject(IObject obj);

    uint8_t** mFildArray;
    std::list<IObject*> mObjectList;
    const uint8_t mFieldSizeY = FIELD_SIZE_Y;
    const uint8_t mFieldSizeX = FIELD_SIZE_X;
};

#endif  //_GAMEENGINE_H
