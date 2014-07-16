#include "CityScene.h"

using namespace cocos2d;

CityScene::CityScene()
{
    mPlayerTank[0] = NULL;
    mPlayerTank[1] = NULL;
}

CityScene::~CityScene()
{
    
}

bool CityScene::init()
{
	TileMapInfo* tileMapInfo = TileMapInfo::createMapInfoWithFile("Round1.tmx");
	CCTMXTiledMap* tmxTileMap = tileMapInfo->getTileMap();
	this->addChild(tmxTileMap);

	mPlayerTank[0] = Tank::createTankWithTankType("player2U.png", tileMapInfo);
    //将地图放到屏幕中间
    CCSize tileSize = tmxTileMap->getTileSize();
	CCSize mapSize = tmxTileMap->getContentSize();
	mPlayerTank[0]->setPosition(ccp(mapSize.width / 2 - tileSize.width * 3, tileSize.height));

    //将坦克缩放到合适大小，然后放到地图中合适位置
    /*CCSize tileSize = tmxFile->getTileSize();
    Tank* tank = Tank::createTankWithTankType("player2U.png");
    mPlayerTank[0] = tank;
    CCSize tankSize = tank->getContentSize();
    tank->setScaleX(tileSize.width*2/tankSize.width);
    tank->setScaleY(tileSize.height*2/tankSize.height);
    tank->setPosition(ccp(winSize.width/2 - tileSize.width*2, tileSize.height));
    this->addChild(tank);*/

    //添加手柄
    mLayerPanel = Panel::create();
	addChild(mLayerPanel, 3);

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

void CityScene::onEnter()
{
    CCLayer::onEnter();
    this->scheduleUpdate();
}

void CityScene::update(float delta)
{
    CCLayer::update(delta);
    //mPlayerTank[0]->setPositionY(mPlayerTank[0]->getPositionY()+1);
    mPlayerTank[0]->command(mLayerPanel->getOrder());
}
