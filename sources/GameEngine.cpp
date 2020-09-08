#include "GameEngine.hpp"

//#include <iostream>
#include <thread>
#include <chrono>
#include "MicroStopwatch.hpp"


//------------------------------------------------------------------------------------------
GameEngine::GameEngine()
//------------------------------------------------------------------------------------------
{
    mFildArray = new uint8_t*[ySize];
    for(uint8_t a = 0; a < ySize; ++a){
        mFildArray[a] = new uint8_t[xSize];
    }

    for(uint8_t y = 0; y < ySize; ++y){
        for(uint8_t x = 0; x < xSize; ++x){
            mFildArray[y][x] = '_';
        }
    }
}

//------------------------------------------------------------------------------------------
GameEngine::~GameEngine()
//------------------------------------------------------------------------------------------
{
    for(int a = 0; a < ySize; ++a){
            delete [] mFildArray[a];
        }
        delete [] mFildArray;
}
