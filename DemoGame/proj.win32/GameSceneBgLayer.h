#ifndef __BG_LAYER_H__
#define __BG_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class GameSceneBgLayer :
	public cocos2d::CCLayer
{
public:
	virtual bool init();

	CREATE_FUNC(GameSceneBgLayer);

	virtual void update(float dt);

private:

	cocos2d::CCSprite* mBg1;
	cocos2d::CCSprite* mBg2;
	cocos2d::CCSprite* mBg3;

	float mX1;
	float mX2;
	float mX3;
	float mSpeed;
};

#endif