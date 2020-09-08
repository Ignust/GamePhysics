#include <iostream>
#include "GameEngine.hpp"
#include "ObjectPoint.hpp"


int main()
{
    ObjectPoint mPoint1(0,0);
    ObjectPoint mPoint2(0,9);
    GameEngine mGameEngine;
    mGameEngine.addObcet(&mPoint1);
    mGameEngine.addObcet(&mPoint2);
    mGameEngine.starGameLoop();


    return 0;
}
