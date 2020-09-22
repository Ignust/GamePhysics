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
    //double nextPositionX;
    //double halfСell = 0.5;

    switch (mObjectDescriptions.mDirection) {
    case Description::UP:
        /*if (static_cast<int>(mObjectDescriptions.mPositionX) == static_cast<int>(object->getObjectDescriptions().mPositionX)
                && static_cast<int>(mObjectDescriptions.mPositionY) -1 == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            processingCollision(object);
            object->processingCollision(this);
        }*/
        if (static_cast<int>(mObjectDescriptions.mPositionX) == static_cast<int>(object->getObjectDescriptions().mPositionX)
                        && mObjectDescriptions.mPositionY > object->getObjectDescriptions().mPositionY
                && object->getObjectDescriptions().mPositionY >= mObjectDescriptions.mPositionY - HALF_CELL) {
                    checkCollisionType(object);
                    processingCollision(object);
                }
        break;
    case Description::DOWN:
        /*if (static_cast<int>(mObjectDescriptions.mPositionX) == static_cast<int>(object->getObjectDescriptions().mPositionX)
                && static_cast<int>(mObjectDescriptions.mPositionY) +1 == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            processingCollision(object);
            object->processingCollision(this);
        }*/
        if (static_cast<int>(mObjectDescriptions.mPositionX) == static_cast<int>(object->getObjectDescriptions().mPositionX)
                        && mObjectDescriptions.mPositionY < object->getObjectDescriptions().mPositionY
                && object->getObjectDescriptions().mPositionY <= mObjectDescriptions.mPositionY + HALF_CELL) {
                    checkCollisionType(object);
                    processingCollision(object);
                }
        break;
    case Description::LEFT:
        if ( mObjectDescriptions.mPositionX > object->getObjectDescriptions().mPositionX
             && object->getObjectDescriptions().mPositionX >= (mObjectDescriptions.mPositionX - HALF_CELL)
                && static_cast<int>(mObjectDescriptions.mPositionY)  == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            checkCollisionType(object);
            processingCollision(object);
        }
        break;
    case Description::RIGHT:
        if ( mObjectDescriptions.mPositionX < object->getObjectDescriptions().mPositionX
             && object->getObjectDescriptions().mPositionX <= (mObjectDescriptions.mPositionX + HALF_CELL)
                && static_cast<int>(mObjectDescriptions.mPositionY)  == static_cast<int>(object->getObjectDescriptions().mPositionY) ) {
            checkCollisionType(object);
            processingCollision(object);
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
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::directDown()
//------------------------------------------------------------------------------------------
{
    mObjectDescriptions.mPositionY += mObjectDescriptions.mSpeed;
    if (mObjectDescriptions.mPositionY >= FIELD_FINISH_Y+1) {
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
    if (mObjectDescriptions.mPositionX >= FIELD_FINISH_X+1) {
        mObjectDescriptions.mPositionX = FIELD_FINISH_X;
        mObjectDescriptions.mDirection = Description::LEFT;
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::checkCollisionType(IObject* object)
//------------------------------------------------------------------------------------------
{
    switch (mObjectDescriptions.mDirection) {
    case Description::UP:
        if (object->getObjectDescriptions().mDirection == Description::DOWN){
            object->processingCollision(this);
        }
        break;
    case Description::DOWN:
        if (object->getObjectDescriptions().mDirection == Description::UP){
            object->processingCollision(this);
        }
        break;
    case Description::LEFT:
        if (object->getObjectDescriptions().mDirection == Description::RIGHT){
            object->processingCollision(this);
        }
        break;
    case Description::RIGHT:
        if (object->getObjectDescriptions().mDirection == Description::LEFT){
            object->processingCollision(this);
        }
        break;
    }
}

//------------------------------------------------------------------------------------------
void MovingObject::processingCollision(IObject* object)
//------------------------------------------------------------------------------------------
{
    switch (mObjectDescriptions.mDirection) {
    case Description::UP:
        mObjectDescriptions.mDirection = Description::DOWN;
        break;
    case Description::DOWN:
        mObjectDescriptions.mDirection = Description::UP;
        break;
    case Description::LEFT:
        mObjectDescriptions.mDirection = Description::RIGHT;
        break;
    case Description::RIGHT:
        mObjectDescriptions.mDirection = Description::LEFT;
        break;
    }
}




