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
void MovingObject::checkCollision(IObject* object)
//------------------------------------------------------------------------------------------
{
    switch (mObjectDescriptions.mDirection) {
    case Description::UP:
        if (static_cast<int>(mObjectDescriptions.mPositionX) == static_cast<int>(object->getObjectDescriptions().mPositionX)
                && static_cast<int>(mObjectDescriptions.mPositionY) -1 == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            processingCollision(object);
            object->processingCollision(this);
        }
        break;
    case Description::DOWN:
        if (static_cast<int>(mObjectDescriptions.mPositionX) == static_cast<int>(object->getObjectDescriptions().mPositionX)
                && static_cast<int>(mObjectDescriptions.mPositionY) +1 == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            processingCollision(object);
            object->processingCollision(this);
        }
        break;
    case Description::LEFT:
        if (static_cast<int>(mObjectDescriptions.mPositionX) -1 == static_cast<int>(object->getObjectDescriptions().mPositionX)
                && static_cast<int>(mObjectDescriptions.mPositionY)  == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            processingCollision(object);
            object->processingCollision(this);
        }
        break;
    case Description::RIGHT:
        if (static_cast<int>(mObjectDescriptions.mPositionX) +1 == static_cast<int>(object->getObjectDescriptions().mPositionX)
                && static_cast<int>(mObjectDescriptions.mPositionY)  == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            processingCollision(object);
            object->processingCollision(this);
        }
        break;
    }
}



//------------------------------------------------------------------------------------------
ObjectDescriptions MovingObject::getObjectDescriptions()
//------------------------------------------------------------------------------------------
{
    return mObjectDescriptions;
}
//------------------------------------------------------------------------------------------
ObjectDescriptions MovingObject::getOldObjectDescriptions()
//------------------------------------------------------------------------------------------
{
    return mOldObjectDescriptions;
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
        mObjectDescriptions.mPositionY = static_cast<int>(mObjectDescriptions.mPositionY);
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
        mObjectDescriptions.mPositionY = static_cast<int>(mObjectDescriptions.mPositionY);
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
        mObjectDescriptions.mPositionX = static_cast<int>(mObjectDescriptions.mPositionX);
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
        mObjectDescriptions.mPositionX = static_cast<int>(mObjectDescriptions.mPositionX);
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::processingCollision(IObject* object)
//------------------------------------------------------------------------------------------
{
    switch (mObjectDescriptions.mDirection) {
    case Description::UP:
        mObjectDescriptions.mDirection = Description::DOWN;
        mObjectDescriptions.mPositionY = static_cast<int>(mObjectDescriptions.mPositionY);
        break;
    case Description::DOWN:
        mObjectDescriptions.mDirection = Description::UP;
        mObjectDescriptions.mPositionY = static_cast<int>(mObjectDescriptions.mPositionY);
        break;
    case Description::LEFT:
        mObjectDescriptions.mDirection = Description::RIGHT;
        mObjectDescriptions.mPositionX = static_cast<int>(mObjectDescriptions.mPositionX);
        break;
    case Description::RIGHT:
        mObjectDescriptions.mDirection = Description::LEFT;
        mObjectDescriptions.mPositionX = static_cast<int>(mObjectDescriptions.mPositionX);
        break;
    }
}




