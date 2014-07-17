#ifndef __ENEMY__AI__H__
#define __ENEMY__AI__H__

#include "cocos2d.h"
#include "Tank.h"

using namespace cocos2d;

static const char* enemyTankType[] = {"normalU.png", "speedU.png", "armor1U.png"};

class EnemyAI{
public:
    EnemyAI();
    ~EnemyAI();

    static EnemyAI* createEnemyAIWithTank(Tank* tank);
    void initEnemyAIWithTank(Tank* tank);
    void update(float delta);
private:
    void addTank(float delta);
    void tankAction(float delta);
private:
    CCArray* mEnemyTanks;
    Tank* mTank;
    TileMapInfo* mTileMapInfo;
    CCPoint bornPoint[3];
};
#endif
