#include "HelloWorldScene.h"
#include "ChoiceScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    setKeypadEnabled(true);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    //
    CCMenuItemImage *pItemPlay = CCMenuItemImage::create("playgameNormal.png", "playgameClose.png", this, menu_selector(HelloWorld::menuPlayGameCallback));
    pItemPlay->setPosition(ccp(visibleSize.width/2, visibleSize.height*1.0f/4.0f));
    pItemPlay->setScaleX(visibleSize.width/600);
    pItemPlay->setScaleY(visibleSize.height/400);

    CCMenu *pMenuPlay = CCMenu::create(pItemPlay, NULL);
    pMenuPlay->setPosition(CCPointZero);
    this->addChild(pMenuPlay, 1);

    //
    CCSprite *pSprite = CCSprite::create("ScenceStart.png");
    pSprite->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    CCSize sz = pSprite->getContentSize();
    pSprite->setScaleX(visibleSize.width/sz.width);
    pSprite->setScaleY(visibleSize.height/sz.height);
    this->addChild(pSprite, 0);
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void HelloWorld::menuPlayGameCallback(CCObject* pSender)
{
    CCScene* pScene = ChoiceScene::scene();
    CCDirector::sharedDirector()->pushScene(pScene);
    return;
}

void HelloWorld::keyBackClicked()
{
    CCLayer::keyBackClicked();
    CCDirector::sharedDirector()->end();
}

void HelloWorld::keyMenuClicked()
{
    CCLayer::keyMenuClicked();
}
