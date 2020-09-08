#if !defined(_OBJECTPOINT_H)
#define _OBJECTPOINT_H

#include "IObject.hpp"

class ObjectPoint : public IObject {
public:
    ObjectPoint(uint8_t x, uint8_t y, uint8_t speed = 0, Description::EDirection direction = Description::UP);
    ~ObjectPoint();
};

#endif  //_OBJECTPOINT_H
