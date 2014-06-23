#ifndef __TANK__H__
#define __TANK__H__

#include "cocos2d.h"
#include "Panel.h"

using namespace cocos2d;

class Tank : public CCSprite
{
public:
    Tank();
    ~Tank();

    static Tank* createTankWithTankType(const char* tankType);
    void command(enumOrder order);
};
#endif
