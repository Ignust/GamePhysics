#include <iostream>
#include "GameEngine.hpp"
#include "ObjectPoint.hpp"
#include <memory>

int main()
{
    ObjectPoint mPoint1(99,0,0.1,Description::LEFT);
    ObjectPoint mPoint2(FIELD_START_X,FIELD_START_Y,0.1,Description::RIGHT);
    ObjectPoint mPoint3(33,0,0.1,Description::LEFT);
    ObjectPoint mPoint4(66,0,0.1,Description::RIGHT);
    ObjectPoint mPoint5(FIELD_START_X+1,FIELD_START_Y+1,0.05,Description::DOWN);
    ObjectPoint mPoint6(FIELD_START_X+1,FIELD_FINISH_Y,0.05,Description::UP);
    ObjectPoint mPoint7(FIELD_START_X+3,FIELD_FINISH_Y-2,0.05,Description::DOWN);


    GameEngine mGameEngine;
    mGameEngine.addObcet(&mPoint1);
    mGameEngine.addObcet(&mPoint2);
    mGameEngine.addObcet(&mPoint3);
    mGameEngine.addObcet(&mPoint4);
    mGameEngine.addObcet(&mPoint5);
    mGameEngine.addObcet(&mPoint6);
    mGameEngine.addObcet(&mPoint7);
    mGameEngine.starGameLoop();


    return 0;
}
