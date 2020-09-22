#include <iostream>
#include "GameEngine.hpp"
#include "ObjectPoint.hpp"
#include <memory>

int main()
{
    ObjectPoint mPoint1(FIELD_FINISH_X,FIELD_START_Y,0.3,Description::LEFT,'1');
    ObjectPoint mPoint2(FIELD_START_X+3,FIELD_START_Y,0.5,Description::RIGHT,'2');
    ObjectPoint mPoint3(33,0,0.3,Description::LEFT,'3');
    ObjectPoint mPoint4(66,0,0.3,Description::RIGHT,'4');
    ObjectPoint mPoint5(FIELD_START_X+1,FIELD_START_Y+1,0.3,Description::DOWN,'5');
    ObjectPoint mPoint6(FIELD_START_X+1,FIELD_FINISH_Y,0.3,Description::UP,'6');
    ObjectPoint mPoint7(FIELD_START_X+3,FIELD_FINISH_Y-2,0.05,Description::DOWN,'7');


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
