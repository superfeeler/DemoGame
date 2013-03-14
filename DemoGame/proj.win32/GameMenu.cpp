#include "GameMenu.h"
#include "GameManager.h"

using namespace cocos2d;

CCScene* GameMenu::scene() 
{
	CCScene* scene = NULL;
	do
	{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		GameMenu *layer = GameMenu::create();
		CC_BREAK_IF(!layer);

		scene->addChild(layer);
	} while (0);
	
	return scene;
}

bool GameMenu::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(! CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite *bg = CCSprite::createWithSpriteFrameName("background.png");
		CC_BREAK_IF(!bg);

		bg->setPosition(ccp(size.width / 2, size.height / 2));
		bg->setScale(1.6);
		this->addChild(bg);

		CCLabelTTF* pLabel = CCLabelTTF::create("Main Menu", "Arial", 30);
		CC_BREAK_IF(!pLabel);
		pLabel->setColor(ccORANGE);
		pLabel->setPosition(ccp(size.width/2, size.height-50));
		this->addChild(pLabel);

		pLabel = CCLabelTTF::create("Play Game", "Arial", 24);
		CC_BREAK_IF(!pLabel);
		
		CCMenuItemLabel *pPlayItem = CCMenuItemLabel::create(
			pLabel, this, menu_selector(GameMenu::menuPlayCallback));
		CC_BREAK_IF(!pPlayItem);

		pPlayItem->setPosition(ccp(size.width/2, size.height/2));


		pLabel = CCLabelTTF::create("Exit", "Arial", 24);
		CC_BREAK_IF(!pLabel);
		
		CCMenuItemLabel *pExitItem = CCMenuItemLabel::create(
			pLabel, this, menu_selector(GameMenu::menuExitCallback));
		CC_BREAK_IF(!pExitItem);

		pExitItem->setPosition(ccp(size.width/2, size.height/2 - 40));


		CCMenu *pMenu = CCMenu::create(pPlayItem, pExitItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(!pMenu);

		this->addChild(pMenu, 1);
		
		bRet = true;
	} while (0);
	return bRet;
}

void GameMenu::menuPlayCallback(CCObject* pSender) 
{
	GameManager::sharedGameManager()->runSceneWithId(GameManager::SCENE_PLAY);
}

void GameMenu::menuExitCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}