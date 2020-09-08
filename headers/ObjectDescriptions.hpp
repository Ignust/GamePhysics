#if !defined(_OBJECTDESCRIPTIONS_H)
#define _OBJECTDESCRIPTIONS_H

#include <stdint.h>


namespace Description {
    enum EDirection {
        UP = 0,
        DOWN ,
        RIGHT,
        LEFT
    };
}

struct ObjectDescriptions {
    uint8_t mPositionX;
    uint8_t mPositionY;
    uint8_t mSpeed;
    Description::EDirection mDirection;
};

#endif  //_OBJECTDESCRIPTIONS_H
