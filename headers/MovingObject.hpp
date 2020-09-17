#if !defined(_MOVINGOBJECT_H)
#define _MOVINGOBJECT_H

#include "ObjectDescriptions.hpp"
#include "IObject.hpp"


class MovingObject : public IObject {
public:
    void updatePhysics() override;
    void checkCollision(IObject* object)override;
    ObjectDescriptions getObjectDescriptions()override;
    ObjectDescriptions getOldObjectDescriptions()override;
    virtual uint8_t getPrintSymbol() = 0;

protected:
    ObjectDescriptions mOldObjectDescriptions;
    ObjectDescriptions mObjectDescriptions;

private:
    void checkCollisionType(IObject* object);
private:
    void updatePosition();
    void directUp();
    void directDown();
    void directLeft();
    void directRight();
protected:
    void processingCollision(IObject* object);
};

#endif  //_MOVINGOBJECT_H
