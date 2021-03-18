#if !defined(_OBJECTPOINT_H)
#define _OBJECTPOINT_H

#include "IObject.hpp"
#include "MovingObject.hpp"

class ObjectPoint : public MovingObject {
public:
    ObjectPoint(double x, double y, double speed = 1, Description::EDirection direction = Description::DOWN, uint8_t printSymbol = 'X', uint32_t mass = 1);
    ~ObjectPoint();
};

#endif  //_OBJECTPOINT_H
