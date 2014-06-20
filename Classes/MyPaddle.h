#ifndef __MY__PADDLE__H__
#define __MY__PADDLE__H__

#include "Paddle.h"
#include "ChoiceScene.h"

#define ROUNDS 20

//事件类型
enum enum_evt{
    evt_start,
    evt_pressA,
    evt_pressB,
    evt_text
};

class MyPaddle : public Paddle
{
    CC_SYNTHESIZE(enum_evt, m_evttyp, evttyp);
    CC_SYNTHESIZE(ChoiceScene*, m_pScene, pScene);

public:
    MyPaddle();
    ~MyPaddle();

    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);;

    static MyPaddle* paddleWithTexture(CCTexture2D* pTexture);;
private:
    bool bFlag;//是否点击
};
#endif
