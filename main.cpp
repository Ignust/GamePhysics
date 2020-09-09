#include <iostream>
#include "GameEngine.hpp"
#include "ObjectPoint.hpp"
#include <memory>

int main()
{
    ObjectPoint mPoint1(99,0,0.3,Description::LEFT);
    ObjectPoint mPoint2(0,0,0.3,Description::RIGHT);


    GameEngine mGameEngine;
    mGameEngine.addObcet(&mPoint1);
    mGameEngine.addObcet(&mPoint2);
    mGameEngine.starGameLoop();


    return 0;
}
