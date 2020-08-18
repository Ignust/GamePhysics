//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : ObjectPoint.hpp
//  @ Date : 06.08.2020
//  @ Author : 
//
//


#if !defined(_OBJECTPOINT_H)
#define _OBJECTPOINT_H

#include "IObject.hpp"
#include "ObjectDescriptions.hpp"

class ObjectPoint : public IObject {
public:
    ObjectPoint(uint8_t x, uint8_t y, uint8_t speed = 0, Description::EDirection direction = Description::UP);
    ~ObjectPoint();
    void setDescriptionsn(ObjectDescriptions descriptions)override;
    ObjectDescriptions getDescriptions()override;
private:
    ObjectDescriptions mObjectDescriptions;
};

#endif  //_OBJECTPOINT_H
