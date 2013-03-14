#include "GameScene.h"
#include "System.h"
#include "GameSceneBgLayer.h"
#include "GameScenePlayLayer.h"

using namespace cocos2d;

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCScene::init());

		GameSceneBgLayer *bgLayer = GameSceneBgLayer::create();
		CC_BREAK_IF(!bgLayer);

		this->addChild(bgLayer);

		
		GameScenePlayLayer *playLayer = GameScenePlayLayer::create();
		CC_BREAK_IF(!playLayer);
		this->addChild(playLayer);

		bRet = true;

	} while (0);
	return bRet;
}