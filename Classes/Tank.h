#ifndef __TANK__H__
#define __TANK__H__

#include "cocos2d.h"
#include "Panel.h"
#include "TileMapInfo.h"

using namespace cocos2d;

class Tank : public CCSprite
{
public:
    Tank();
    ~Tank();

    static Tank* createTankWithTankType(const char* tankType, TileMapInfo* tileMapInfo);
    void initTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo);
    void command(enumOrder order);
private:
    CC_SYNTHESIZE(TileMapInfo*, mTileMapInfo, TileMapInfo);
};
#endif
