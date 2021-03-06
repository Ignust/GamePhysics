//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : GamePhysics.hpp
//  @ Date : 06.08.2020
//  @ Author : 
//
//


#if !defined(_GAMEPHYSICS_H)
#define _GAMEPHYSICS_H

#include "ConsoleOutput.hpp"
#include "ObjectPoint.hpp"

#include <list>

class GamePhysics {

public:
    GamePhysics();
    ~GamePhysics();
    void starGameLoop();
    void addObcet(IObject* obj);


private:
    void updateObects();
    void renderField();

    uint8_t** mFildArray;
    std::list<IObject*> mObjectList;
    const uint8_t ySize = 25;
    const uint8_t xSize = 100;
    //ConsoleOutput mConsoleOutput;
};

#endif  //_GAMEPHYSICS_H
