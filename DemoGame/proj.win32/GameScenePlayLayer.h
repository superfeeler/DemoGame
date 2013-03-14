#ifndef __GAMEPLAY_LAYER_H__
#define __GAMEPLAY_LAYER_H__
#include "cocos2d.h"
#include "Collision.h"

class MonsterManager;
class BulletManager;

class GameScenePlayLayer :
	public CCLayer, public CollisionListener
{
public:
	GameScenePlayLayer(void);
	~GameScenePlayLayer(void);

	virtual bool init();

	CREATE_FUNC(GameScenePlayLayer);

	virtual void CollisionDetected(Collidable *source, Collidable *target);
private:
	void AddParticle();

	MonsterManager *mMonsterManager;
	BulletManager *mBulletManager;
};

#endif