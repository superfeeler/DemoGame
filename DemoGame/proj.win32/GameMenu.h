#ifndef __GAME_MENU_H__
#define __GAME_MENU_H__
#include "cocos2d.h"
class GameMenu : public cocos2d::CCLayer
{
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	virtual void menuPlayCallback(CCObject* pSender);

	virtual void menuExitCallback(CCObject* pSender);

	CREATE_FUNC(GameMenu);
};

#endif

