#include "Tank.h"

Tank::Tank()
{

}

Tank::~Tank()
{

}

Tank* Tank::createTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo)
{
	CCSpriteFrameCache* pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	pCache->addSpriteFramesWithFile("tank.plist");

	Tank* tank = new Tank();
	tank->initTankWithTankType(tankTypeName, tileMapInfo);
	tank->autorelease();

	return tank;
}

void Tank::initTankWithTankType(const char* tankTypeName, TileMapInfo* tileMapInfo)
{
	initWithSpriteFrameName(tankTypeName);
	mTileMapInfo = tileMapInfo;

	mTileMapInfo->getTileMap()->addChild(this);

	CCTMXTiledMap* tmxTileMap = mTileMapInfo->getTileMap();
	CCSize tileSize = tmxTileMap->getTileSize();
	CCSize tankSize = getContentSize();

	setScale((tileSize.height * 2-4) / (tankSize.height));
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
	    fRotation = 0.0f;
	    CCLOG("up");
	    break;
	case cmdGoDown:
	    stepY = -1.0f;
	    fRotation = 180.0f;
	    CCLOG("down");
	    break;
	case cmdGoLeft:
	    stepX = -1.0f;
	    fRotation = 270.0f;
	    CCLOG("left");
	    break;
	case cmdGoRight:
	    stepX = 1.0f;
	    fRotation = 90.0f;
	    CCLOG("right");
	    break;
	case cmdFire:
	    break;
	default:
	    break;
    }
	CCRect rect = this->boundingBox();
	if (!mTileMapInfo->collisionTest(CCRectMake(rect.getMinX() + stepX, 
		rect.getMinY() + stepY, rect.size.width, rect.size.height)))
	{
		setPositionX(getPositionX() + stepX);
		setPositionY(getPositionY() + stepY);
	}
    setRotation(fRotation);
}
