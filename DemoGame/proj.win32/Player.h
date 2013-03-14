#ifndef __PLAYER_H__
#define __PLAYeR_H__

#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;


class Shooter;

class Player :
	public Entity
{
public:
	Player(void);
	~Player(void);
	
	static Player *playWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void updatePosition(float dt, float xDelta, float yDelta);
	virtual void firePrimary();

	void setShooter(Shooter *shooter);

private:
	Shooter *mShooter;
};

#endif