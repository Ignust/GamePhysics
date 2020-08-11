//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : GamePhysics.cpp
//  @ Date : 06.08.2020
//  @ Author : 
//
//
#include "GamePhysics.hpp"

#include <windows.h>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

//------------------------------------------------------------------------------------------
GamePhysics::GamePhysics()
//------------------------------------------------------------------------------------------
{
    mFildArray = new uint8_t*[ySize];
    for(uint8_t a = 0; a < ySize; ++a){
        mFildArray[a] = new uint8_t[xSize];
    }

    for(uint8_t y = 0; y < ySize; ++y){
        for(uint8_t x = 0; x < xSize; ++x){
            mFildArray[y][x] = 'o';
        }
    }
}

//------------------------------------------------------------------------------------------
GamePhysics::~GamePhysics()
//------------------------------------------------------------------------------------------
{
    for(int a = 0; a < ySize; ++a){
            delete [] mFildArray[a];
        }
        delete [] mFildArray;
}

//------------------------------------------------------------------------------------------
void GamePhysics::starGameLoop()
//------------------------------------------------------------------------------------------
{
    while (true) {
        using namespace std;
            using namespace std::chrono;
        system_clock::time_point now = system_clock::now();

        time_t sec1;
        time_t sec2;
        time(&sec1);
        double start = clock();
        renderField();
        double end = clock();
        system_clock::duration tp = now.time_since_epoch();
        system_clock::time_point now1 = system_clock::now();

        tp -= duration_cast<seconds>(tp);

        time(&sec2);
        double t = (start + 16 - end);
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(t)));

        std::cout<<"start: "<<start<< std::endl;
        std::cout<<"end: "<<end<< std::endl;
        std::cout<<"t: "<<t<< std::endl;
        std::cout<<"sec: "<<difftime(sec1,sec2)<< std::endl;
        cout  << "tp: "<< static_cast<unsigned>(tp / milliseconds(1)) << endl;
        system("pause");
    }


}

//------------------------------------------------------------------------------------------
void GamePhysics::addObcet(IObject* obj)
//------------------------------------------------------------------------------------------
{
    if(obj != nullptr){
        mObjectList.push_back(obj);
    }
}

//------------------------------------------------------------------------------------------
void GamePhysics::updateObects()
//------------------------------------------------------------------------------------------
{
    for (auto & object: mObjectList){
        //do something
    }
}

//------------------------------------------------------------------------------------------
void GamePhysics::renderField()
//------------------------------------------------------------------------------------------
{
    for (auto & object: mObjectList){
        mFildArray[object->getDescriptions().mPositionX][object->getDescriptions().mPositionY] = 'x';
    }
    ConsoleOutput::init().print(mFildArray, xSize, ySize);
    //system("pause");
}

