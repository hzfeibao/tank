#ifndef __BULLET__H__
#define __BULLET__H__

#include "cocos2d.h"
#include "Tank.h"

using namespace cocos2d;

class Bullet : public CCSprite
{
public:
    Bullet();
    ~Bullet();

    static Bullet* createBulletWithTank(Tank* tank);
    void initBulletWithTank(Tank* tank);
    void fire();
    virtual void update(float delta);
    void bulletBoom();
private:
    bool isFlying;
    Tank* mTank;
    TileMapInfo* mTileMapInfo;
    float stepX, stepY;
};
#endif
