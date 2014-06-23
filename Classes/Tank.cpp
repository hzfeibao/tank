#include "Tank.h"

Tank::Tank()
{

}

Tank::~Tank()
{

}

Tank* Tank::createTankWithTankType(const char* tankType)
{
    CCSpriteFrameCache* pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    pCache->addSpriteFramesWithFile("tank.plist");

    Tank* tank = new Tank();
    tank->initWithSpriteFrameName(tankType);
    tank->autorelease();

    return tank;
}

void Tank::command(enumOrder order)
{
    float stepX = 0.0f;
    float stepY = 0.0f;
    static float fRotation = 0.0f;

    switch(order)
    {
	case cmdNothing:
	    break;
	case cmdGoUP:
	    stepY = 1.0f;
	    CCLOG("up");
	case cmdGoDown:
	    stepY = -1.0f;
	    fRotation = 180.0f;
	    CCLOG("down");
	case cmdGoLeft:
	    stepX = -1.0f;
	    fRotation = 270.0f;
	    CCLOG("left");
	case cmdGoRight:
	    stepX = 1.0f;
	    fRotation = 90.0f;
	    CCLOG("right");
	case cmdFire:
	    break;
	default:
	    break;
    }
    setPositionX(getPositionX()+stepX);
    setPositionY(getPositionY()+stepY);
    setRotation(fRotation);
}
