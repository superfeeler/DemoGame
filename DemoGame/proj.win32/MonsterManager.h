#ifndef __MONSTER_MANAGER_H__
#define __MONSTER_MANAGER_H__
#include "cocos2d.h"
#include "BulletManager.h"


using namespace cocos2d;

#define MAX_MONSTER 50
#define SPAWN_TIME	0.8f

class Collidable;
class CollisionListener;

class MonsterManager :
	public CCNode, public BulletListener
{
public:
	MonsterManager(void);
	~MonsterManager(void);

	static MonsterManager *initWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void update(float dt);

	void setAttackingTarget(Collidable *target);
	void setCollisionListener(CollisionListener *listener);

	virtual bool collideWithBullet(Collidable *bullet);

private:

	CCArray *mMonsterList;
	int mCurrentIndex;

	float mTimer;

	Collidable *mAttackingTarget;
	CollisionListener *mCollisionListener;

};

#endif