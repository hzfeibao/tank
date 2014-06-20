#include "CityScene.h"
#include "Tank.h"

using namespace cocos2d;

CityScene::CityScene()
{
    
}

CityScene::~CityScene()
{
    
}

bool CityScene::init()
{
    CCTMXTiledMap *tmxFile = CCTMXTiledMap::create("Round1.tmx");
    //将地图放到屏幕中间
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize size = tmxFile->getContentSize();
    tmxFile->setPosition(ccp((winSize.width - size.width)/2, (winSize.height - size.height)/2));
    this->addChild(tmxFile);

    //将坦克缩放到合适大小，然后放到地图中合适位置
    CCSize tileSize = tmxFile->getTileSize();
    Tank* tank = Tank::createTankWithTankType("player2U.png");
    CCSize tankSize = tank->getContentSize();
    tank->setScaleX(tileSize.width*2/tankSize.width);
    tank->setScaleY(tileSize.height*2/tankSize.height);
    tank->setPosition(ccp(winSize.width/2 - tileSize.width*2, tileSize.height));
    this->addChild(tank);

    return true;
}

CCScene *CityScene::scene()
{
    CCScene* scene = CCScene::create();
    CityScene* layer = CityScene::create();
    scene->addChild(layer);
    return scene;
}

CCScene *CityScene::scene(int round)
{
    CCScene* scene = CCScene::create();
    CityScene* layer = CityScene::create(round);
    scene->addChild(layer);
    return scene;
}

CityScene *CityScene::create(int round)
{
    CityScene* pRet = new CityScene();
    if(pRet)
    {
	pRet->setRound(round);
	if(pRet->init())
	{
	    pRet->autorelease();
	    return pRet;
	}
    }
    return NULL;
}
