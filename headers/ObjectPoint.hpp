#if !defined(_OBJECTPOINT_H)
#define _OBJECTPOINT_H

#include "IObject.hpp"

class ObjectPoint : public IObject {
public:
    ObjectPoint(double x, double y, double speed = 1, Description::EDirection direction = Description::DOWN);
    ~ObjectPoint();
    ObjectDescriptions getObjectDescriptions()override;
    ObjectDescriptions getOldObjectDescriptions()override;
};

#endif  //_OBJECTPOINT_H
