#include <iostream>
#include "GameEngine.hpp"
#include "ObjectPoint.hpp"


int main()
{
    ObjectPoint mPoint1(1,0,1,Description::DOWN);
    ObjectPoint mPoint2(0,0,1,Description::RIGHT);
    GameEngine mGameEngine;
    mGameEngine.addObcet(&mPoint1);
    mGameEngine.addObcet(&mPoint2);
    mGameEngine.starGameLoop();


    return 0;
}
