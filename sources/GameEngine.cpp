#include "GameEngine.hpp"

#include <thread>
#include <chrono>

//------------------------------------------------------------------------------------------
GameEngine::GameEngine()
//------------------------------------------------------------------------------------------
{
    mFildArray = new uint8_t*[mFieldSizeY];
    for(uint8_t a = 0; a < mFieldSizeY; ++a){
        mFildArray[a] = new uint8_t[mFieldSizeX];
    }

    for(uint8_t y = 0; y < mFieldSizeY; ++y){
        for(uint8_t x = 0; x < mFieldSizeX; ++x){
            mFildArray[y][x] = OBJECT_EMPTY;
        }
    }
}

//------------------------------------------------------------------------------------------
GameEngine::~GameEngine()
//------------------------------------------------------------------------------------------
{
    for(int a = 0; a < mFieldSizeY; ++a){
            delete [] mFildArray[a];
        }
        delete [] mFildArray;
}

//------------------------------------------------------------------------------------------
void GameEngine::starGameLoop()
//------------------------------------------------------------------------------------------
{
    MicroStopwatch mTimer;
    while (true) {
        mTimer.Start();

        for (auto & object : mObjectList){
            object->updatePhysics();
            for (auto & objectForCheck : mObjectList){
                if(objectForCheck != object) {
                    object->checkCollision(objectForCheck);
                }
            }
            drawObject(object);
        }

        renderField();
        std::this_thread::sleep_for(std::chrono::milliseconds((FPS) - mTimer.Now()));
    }

}
//------------------------------------------------------------------------------------------
void GameEngine::addObcet(IObject* obj)
//------------------------------------------------------------------------------------------
{
    if(obj != nullptr){
            mObjectList.push_back(obj);
        }
}

//------------------------------------------------------------------------------------------
void GameEngine::renderField()
//------------------------------------------------------------------------------------------
{
    ConsoleOutput::init().print(mFildArray, mFieldSizeX, mFieldSizeY);
}

//------------------------------------------------------------------------------------------
void GameEngine::drawObject(IObject* obj)
//------------------------------------------------------------------------------------------
{
    if (obj->getObjectDescriptions().mPositionX != obj->getOldObjectDescriptions().mPositionX ||
            obj->getObjectDescriptions().mPositionY !=obj->getOldObjectDescriptions().mPositionY) {

        mFildArray[static_cast<int>(obj->getOldObjectDescriptions().mPositionY) ]
                [static_cast<int>(obj->getOldObjectDescriptions().mPositionX)] = OBJECT_EMPTY;

        mFildArray[static_cast<int>(obj->getObjectDescriptions().mPositionY)]
                [static_cast<int>(obj->getObjectDescriptions().mPositionX)] = OBJECT_SYMBOL;

    }
}

