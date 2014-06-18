#include "ChoiceScene.h"

CCScene *ChoiceScene::scene()
{
    CCScene *scene = CCScene::create();
    ChoiceScene *layer = ChoiceScene::create();
    //???
    if(scene && layer)
    {
	scene->addChild(layer);
    }
    return scene;
}


