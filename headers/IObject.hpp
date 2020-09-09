#if !defined(_IOBJECT_H)
#define _IOBJECT_H

#include "MovingObject.hpp"

class IObject : public MovingObject {
public:
    virtual ObjectDescriptions getObjectDescriptions() = 0;
    virtual ObjectDescriptions getOldObjectDescriptions() = 0;
};

#endif  //_IOBJECT_H
