#if !defined(_MOVINGOBJECT_H)
#define _MOVINGOBJECT_H

#include "ObjectDescriptions.hpp"
#include "IObject.hpp"


class MovingObject : public IObject {
public:
    MovingObject(double x, double y, double speed = 1, Description::EDirection direction = Description::DOWN, uint8_t printSymbol = 'X',uint32_t mass = 1);
    void updatePhysics() override;
    void checkCollision(IObject* object)override;
    ObjectDescriptions getObjectDescriptions()override;
    ObjectDescriptions getOldObjectDescriptions()override;
    virtual uint8_t getPrintSymbol()override;

private:
    void checkCollisionType(IObject* object);
    void updatePosition();
    void directUp();
    void directDown();
    void directLeft();
    void directRight();

protected:
    void processingCollision(IObject* object);

private:
    ObjectDescriptions mOldObjectDescriptions;
    ObjectDescriptions mObjectDescriptions;
};

#endif  //_MOVINGOBJECT_H
