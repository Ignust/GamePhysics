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
    double mPositionX;
    double mPositionY;
    double mSpeed;
    Description::EDirection mDirection;
    uint8_t mPrintSymbol;
    uint32_t mMass;
};

#endif  //_OBJECTDESCRIPTIONS_H
