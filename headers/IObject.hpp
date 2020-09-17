#if !defined(_IOBJECT_H)
#define _IOBJECT_H

#include"ObjectDescriptions.hpp"

class IObject {
public:
    virtual ObjectDescriptions getObjectDescriptions() = 0;
    virtual ObjectDescriptions getOldObjectDescriptions() = 0;
    virtual void updatePhysics() = 0;
    virtual void checkCollision(IObject* object) = 0;

    virtual void processingCollision(IObject* object) = 0;
    virtual uint8_t getPrintSymbol() = 0;
};

#endif  //_IOBJECT_H
