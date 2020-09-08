#if !defined(_MOVINGOBJECT_H)
#define _MOVINGOBJECT_H

#include "ObjectDescriptions.hpp"

class MovingObject {
public:
    void updatePhysics();

    ObjectDescriptions mOldObjectDescriptions;
    ObjectDescriptions mObjectDescriptions;
private:
    void updatePosition();
};

#endif  //_MOVINGOBJECT_H
