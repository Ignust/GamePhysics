#include "MovingObject.hpp"

#include "Tools.hpp"

//------------------------------------------------------------------------------------------
void MovingObject::updatePhysics()
//------------------------------------------------------------------------------------------
{
    mOldObjectDescriptions = mObjectDescriptions;
    updatePosition();
}

//------------------------------------------------------------------------------------------
void MovingObject::updatePosition()
//------------------------------------------------------------------------------------------
{
    switch (mObjectDescriptions.mDirection) {
    case Description::UP:
        mObjectDescriptions.mPositionY -= mObjectDescriptions.mSpeed;
        break;
    case Description::DOWN:
        mObjectDescriptions.mPositionY += mObjectDescriptions.mSpeed;
        break;
    case Description::LEFT:
        mObjectDescriptions.mPositionX -= mObjectDescriptions.mSpeed;
        break;
    case Description::RIGHT:
        mObjectDescriptions.mPositionX += mObjectDescriptions.mSpeed;
        break;

    }
}
