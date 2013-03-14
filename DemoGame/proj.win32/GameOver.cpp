#include "GameOver.h"
#include "System.h"
#include "GameManager.h"
#include "Constants.h"

using namespace cocos2d;

GameOver::GameOver(void)
{
}


GameOver::~GameOver(void)
{
}

CCScene* GameOver::scene()
{
	CCScene *scene = NULL;
	do
	{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		GameOver *layer = GameOver::create();
		CC_BREAK_IF(!layer);

		scene->addChild(layer);

	} while (0);
	return scene;
}

bool GameOver::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCSprite *bg = CCSprite::createWithSpriteFrameName("background.png");
		CC_BREAK_IF(!bg);

		bg->setPosition(System::PointMake(size.width/2, size.height/2));
		bg->setScale(1.6);
		this->addChild(bg);

		CCSprite *girl = CCSprite::createWithSpriteFrameName("girl4.png");
		girl->setPosition(System::PointMake(110, 110));
		this->addChild(girl);

		CCLabelTTF* pLabel = CCLabelTTF::create("GAME OVER", "Arial", 30);
		CC_BREAK_IF(! pLabel);

		pLabel->setColor(ccRED);
		pLabel->setPosition(System::PointMake(size.width/2, size.height - 50));

		this->addChild(pLabel);

		pLabel = CCLabelTTF::create("Retry", "Arial", 24);
		CC_BREAK_IF(! pLabel);

		CCMenuItemLabel *pRetryItem = CCMenuItemLabel::create(
			pLabel, this, menu_selector(GameOver::menuRetryCallBack));
		CC_BREAK_IF(! pRetryItem);

		pRetryItem->setPosition(System::PointMake(size.width/2, size.height/2 + 20));


		pLabel = CCLabelTTF::create("Exit", "Arial", 24);
		CC_BREAK_IF(! pLabel);

		CCMenuItemLabel *pExitItem = CCMenuItemLabel::create(
			pLabel, this, menu_selector(GameOver::menuExitCallBack));
		CC_BREAK_IF(! pExitItem);

		pExitItem->setPosition(System::PointMake(size.width/2, size.height/2 -20));

		CCMenu* pMenu = CCMenu::create(pRetryItem, pExitItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		this->addChild(pMenu, 1);
		
		bRet = true;
	} while (0);
	return bRet;
}

void GameOver::menuExitCallBack(CCObject* pSender)
{
	GameManager::sharedGameManager()->runSceneWithId(GameManager::SCENE_MENU);
}

void GameOver::menuRetryCallBack(CCObject* pSender)
{
	GameManager::sharedGameManager()->runSceneWithId(GameManager::SCENE_PLAY);
}