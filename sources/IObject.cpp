#include "ObjectPoint.hpp"

//------------------------------------------------------------------------------------------
ObjectPoint::ObjectPoint(double x, double y, double speed, Description::EDirection direction)
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
