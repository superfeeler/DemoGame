#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "cocos2d.h"

using namespace cocos2d;

class Collidable
{
public:
	virtual bool collidedWith(Collidable *target) = 0;
	virtual const CCPoint& getPosition() = 0;
	virtual float getRadius() = 0;
};

class CollisionListener
{
public:
	virtual void CollisionDetected(Collidable *source, Collidable *target) = 0;
};

#endif