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
        directUp();
        break;
    case Description::DOWN:
        directDown();
        break;
    case Description::LEFT:
        directLeft();
        break;
    case Description::RIGHT:
        directRight();
        break;

    }
}

//------------------------------------------------------------------------------------------
void MovingObject::directUp()
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionY -= mObjectDescriptions.mSpeed;
    if (mObjectDescriptions.mPositionY <= FIELD_START_Y) {
        mObjectDescriptions.mPositionY = FIELD_START_Y;
        mObjectDescriptions.mDirection = Description::DOWN;
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::directDown()
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionY += mObjectDescriptions.mSpeed;
    if (mObjectDescriptions.mPositionY >= FIELD_FINISH_Y) {
        mObjectDescriptions.mPositionY = FIELD_FINISH_Y;
        mObjectDescriptions.mDirection = Description::UP;
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::directLeft()
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionX -= mObjectDescriptions.mSpeed;
    if (mObjectDescriptions.mPositionX <= FIELD_START_X) {
        mObjectDescriptions.mPositionX = FIELD_START_X;
        mObjectDescriptions.mDirection = Description::RIGHT;
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::directRight()
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionX += mObjectDescriptions.mSpeed;
    if (mObjectDescriptions.mPositionX >= FIELD_FINISH_X) {
        mObjectDescriptions.mPositionX = FIELD_FINISH_X;
        mObjectDescriptions.mDirection = Description::LEFT;
    }
}



