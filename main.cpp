#include <iostream>
#include "GameEngine.hpp"
#include "ObjectPoint.hpp"
#include <memory>

int main()
{
    ObjectPoint mPoint1(99,0,0.3,Description::LEFT);
    ObjectPoint mPoint2(0,0,0.3,Description::RIGHT);
    ObjectPoint mPoint3(33,0,0.9,Description::LEFT);
    ObjectPoint mPoint4(66,0,0.6,Description::RIGHT);


    GameEngine mGameEngine;
    mGameEngine.addObcet(&mPoint1);
    mGameEngine.addObcet(&mPoint2);
    mGameEngine.addObcet(&mPoint3);
    mGameEngine.addObcet(&mPoint4);
    mGameEngine.starGameLoop();


    return 0;
}
