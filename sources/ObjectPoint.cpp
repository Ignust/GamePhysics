#include "ObjectPoint.hpp"

//------------------------------------------------------------------------------------------
ObjectPoint::ObjectPoint(double x, double y, double speed, Description::EDirection direction, uint8_t printSymbol,uint32_t mass)
    : MovingObject::MovingObject(x,y,speed,direction, printSymbol,mass)
//------------------------------------------------------------------------------------------
{
    /*
    mObjectDescriptions.mPositionX = x;
    mObjectDescriptions.mPositionY = y;
    mObjectDescriptions.mSpeed = speed;
    mObjectDescriptions.mDirection = direction;
    mObjectDescriptions.mPrintSymbol = printSymbol;
    */
}

//------------------------------------------------------------------------------------------
ObjectPoint::~ObjectPoint()
//------------------------------------------------------------------------------------------
{

}






