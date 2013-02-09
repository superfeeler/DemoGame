#include "GameManager.h"
#include "cocos2d.h"
#include "System.h"
#include "GameMenu.h"
#include "GameScene.h"

using namespace cocos2d;

GameManager *GameManager::mSharedGameManager = NULL;

GameManager *GameManager::sharedGameManager()
{
	if (mSharedGameManager == NULL)
	{
		mSharedGameManager = new GameManager();
		if (!mSharedGameManager || !mSharedGameManager->init())
		{
			CC_SAFE_DELETE(mSharedGameManager);
		}
	}
	return mSharedGameManager;
}


void GameManager::purgeGameManager()
{
	CC_SAFE_DELETE(mSharedGameManager);
}

bool GameManager::init() 
{
	bool bRet = false;
	do
	{
		CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();

		if (System::isPad())
		{
			cache->addSpriteFramesWithFile("images-hd.plist", "images-hd.png");
		}
		else
		{
			CCDirector::sharedDirector()->enableRetinaDisplay(true);
			cache->addSpriteFramesWithFile("images.plist", "images.png");
		}
		bRet = true;
	} while (0);
	return bRet;
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::runSceneWithId(SceneId id)
{
	CCScene *newScene = NULL;
	switch(id)
	{
	case SCENE_MENU:
		newScene = GameMenu::scene();
		break;
	case SCENE_PLAY:
		newScene = GameScene::create();
		break;
	}

	if (newScene)
	{
		if (CCDirector::sharedDirector()->getRunningScene() == NULL)
		{
			CCDirector::sharedDirector()->runWithScene(newScene);
		}
		else
		{
			CCDirector::sharedDirector()->replaceScene(newScene);
		}
	}
}