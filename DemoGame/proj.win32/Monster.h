#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Entity.h"
#include "cocos2d.h"

using namespace cocos2d;

#define LEFT_LIMIT -50
#define RIGHT_LIMIT 800

class Monster :
	public Entity
{
public:
	Monster(void);
	~Monster(void);

	static Monster *monsterWithBatchNode(CCSpriteBatchNode *spriteNode);

	bool init(CCSpriteBatchNode *spriteNode);

	virtual void updatePosition(float dt, float xDelta, float yDelta);

private:

};

#endif