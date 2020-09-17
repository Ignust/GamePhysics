#include "ObjectPoint.hpp"

//------------------------------------------------------------------------------------------
ObjectPoint::ObjectPoint(double x, double y, double speed, Description::EDirection direction, uint8_t printSymbol)
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionX = x;
    mObjectDescriptions.mPositionY = y;
    mObjectDescriptions.mSpeed = speed;
    mObjectDescriptions.mDirection = direction;
    mObjectDescriptions.mPrintSymbol = printSymbol;
}

//------------------------------------------------------------------------------------------
ObjectPoint::~ObjectPoint()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
uint8_t ObjectPoint::getPrintSymbol()
//------------------------------------------------------------------------------------------
{
    return mObjectDescriptions.mPrintSymbol;
}





