#include <iostream>
#include "GamePhysics.hpp"
#include "ObjectPoint.hpp"


int main()
{
    ObjectPoint mPoint1(0,0);
    ObjectPoint mPoint2(0,9);
    GamePhysics mGamePhysics;
    mGamePhysics.addObcet(&mPoint1);
    mGamePhysics.addObcet(&mPoint2);
    mGamePhysics.starGameLoop();


    return 0;
}
