#ifndef __BULLET_MANAGER_H__
#define __BULLET_MANAGER_H__

#include "cocos2d.h"

#include "Collision.h"

using namespace cocos2d;

#define MAX_BULLET	100

class BulletListener
{
public:
	virtual bool collideWithBullet(Collidable *bullet) = 0;
};

class Shooter
{
public:
	virtual void shoot(const CCPoint &fromPosition) = 0;
};

class BulletManager
	:public CCNode, public Shooter
{
public:
	BulletManager(void);
	~BulletManager(void);
	
	static BulletManager *initWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteNode);

	virtual void update(float dt);

	void setBulletListener(BulletListener *listener);

	virtual void shoot(const CCPoint &fromPoint);

private:

	CCArray *mBulletList;
	int mCurrentIndex;

	BulletListener *mBulletListener;

};

#endif