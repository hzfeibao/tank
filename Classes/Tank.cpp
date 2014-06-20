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
