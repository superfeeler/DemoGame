#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene :
	public cocos2d::CCScene
{
public:
	virtual bool init();


	CREATE_FUNC(GameScene);
};

#endif