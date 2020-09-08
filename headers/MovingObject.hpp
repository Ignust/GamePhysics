#if !defined(_MOVINGOBJECT_H)
#define _MOVINGOBJECT_H

#include "ObjectDescriptions.hpp"

class MovingObject {
public:
    ObjectDescriptions mOldObjectDescriptions;
    ObjectDescriptions mObjectDescriptions;
    void UpdatePhysics();
};

#endif  //_MOVINGOBJECT_H
