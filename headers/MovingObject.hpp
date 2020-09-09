#if !defined(_MOVINGOBJECT_H)
#define _MOVINGOBJECT_H

#include "ObjectDescriptions.hpp"

class MovingObject {
public:
    void updatePhysics();

protected:
    ObjectDescriptions mOldObjectDescriptions;
    ObjectDescriptions mObjectDescriptions;
private:
    void updatePosition();
    void directUp();
    void directDown();
    void directLeft();
    void directRight();
};

#endif  //_MOVINGOBJECT_H
