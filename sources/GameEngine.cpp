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

        for (auto & object: mObjectList){
            object->updatePhysics();
            drawObject(*object);
        }

        renderField();

        std::this_thread::sleep_for(std::chrono::milliseconds((FPS) - mTimer.Now()));
        //std::cout << " time: " << mTimer.Now() << std::endl;

        //system("pause");
    }

}
//------------------------------------------------------------------------------------------
void GameEngine::addObcet(IObject* obj)
//------------------------------------------------------------------------------------------
{
    if(obj != nullptr){
            std::shared_ptr<IObject> tmpPtr = std::make_shared<IObject>(*obj);
            mObjectList.push_back(tmpPtr);
        }
}

//------------------------------------------------------------------------------------------
void GameEngine::renderField()
//------------------------------------------------------------------------------------------
{
    /*for (auto & object: mObjectList){
            mFildArray[object->mObjectDescriptions.mPositionX][object->mObjectDescriptions.mPositionY] = 'x';
        }*/
        ConsoleOutput::init().print(mFildArray, mFieldSizeX, mFieldSizeY);
        //system("pause");
}

//------------------------------------------------------------------------------------------
void GameEngine::drawObject(IObject obj)
//------------------------------------------------------------------------------------------
{
    if (obj.mObjectDescriptions.mPositionX !=obj.mOldObjectDescriptions.mPositionX ||
            obj.mObjectDescriptions.mPositionY !=obj.mOldObjectDescriptions.mPositionY) {
        mFildArray[static_cast<int>(obj.mOldObjectDescriptions.mPositionY) ][static_cast<int>(obj.mOldObjectDescriptions.mPositionX)] = OBJECT_EMPTY;
        mFildArray[static_cast<int>(obj.mObjectDescriptions.mPositionY)][static_cast<int>(obj.mObjectDescriptions.mPositionX)] = OBJECT_SYMBOL;
    }
}

