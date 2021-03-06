#ifndef __CITYSCENE__H__
#define __CITYSCENE__H__

#include "cocos2d.h"
#include "Tank.h"
#include "Panel.h"

class CityScene : public cocos2d::CCLayer
{
public:
    CityScene();
    ~CityScene();
    virtual bool init();
    virtual void onEnter();
    virtual void update(float delta);

    static cocos2d::CCScene *scene();
    static cocos2d::CCScene *scene(int round);
    CREATE_FUNC(CityScene);
    static CityScene *create(int round);

    CC_SYNTHESIZE(int, m_nRound, Round);
private:
    Panel* mLayerPanel;
    Tank* mPlayerTank[2];
};
#endif
