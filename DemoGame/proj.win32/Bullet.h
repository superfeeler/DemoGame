#ifndef __BULLET_H__
#define __BULLET_H__
#include "entity.h"
#include "cocos2d.h"

using namespace cocos2d;

#define BULLET_RIGHT_LIMIT 800

class Bullet :
	public Entity
{
public:
	Bullet(void);
	~Bullet(void);
	static Bullet *bulletWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void updatePosition(float dt, float xDelta, float yDelta);

private:

};

#endif