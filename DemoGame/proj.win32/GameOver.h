#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"
class GameOver :
	public cocos2d::CCLayer
{
public:
	GameOver(void);
	~GameOver(void);

	virtual bool init();

	static cocos2d::CCScene* scene();

	virtual void menuRetryCallBack(CCObject* pSender);
	virtual void menuExitCallBack(CCObject* pSender);

	CREATE_FUNC(GameOver);
};

#endif