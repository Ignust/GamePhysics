#include "ObjectPoint.hpp"

//------------------------------------------------------------------------------------------
ObjectPoint::ObjectPoint(uint8_t x, uint8_t y, uint8_t speed, Description::EDirection direction)
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionX = x;
    mObjectDescriptions.mPositionY = y;
    mObjectDescriptions.mSpeed = speed;
    mObjectDescriptions.mDirection = direction;
}

//------------------------------------------------------------------------------------------
ObjectPoint::~ObjectPoint()
//------------------------------------------------------------------------------------------
{

}
