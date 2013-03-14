#include "Entity.h"
#include "System.h"

Entity::Entity(void) 
	: mSprite(NULL), mController(NULL), mActive(true), mRadius(1.0f)
{
	mSprite = NULL;
}


Entity::~Entity(void)
{
}

bool Entity::init(CCNode* parent)
{
	bool bRet = false;
	do
	{
		bRet = true;
	} while (0);
	return bRet;
}

void Entity::setVisual(CCSprite *sprite)
{
	mSprite = sprite;
}

void Entity::setActive(bool flag)
{
	mActive = flag;
	if (mSprite)
	{
		mSprite->setVisible(flag);
	}
	if (mActive)
	{
		if (mController)
		{
			mController->scheduleUpdate();
		}
	}
	else
	{
		if (mController)
		{
			mController->unscheduleUpdate();
		}
	}
}

bool Entity::isActive()
{
	return mActive;
}

void Entity::setController(Controller *controller)
{
	this->addChild(controller);

	controller->setControllerListener(this);

	mController = controller;
}


const CCPoint& Entity::getPosition()
{
	if (mSprite)
	{
		return mSprite->getPosition();
	}
	return CCPointZero;
}

void Entity::setPosition(const CCPoint &point)
{
	if(mSprite)
		mSprite->setPosition(point);
}

void Entity::setRadius(float radius)
{
	mRadius = radius;
}

float Entity::getRadius()
{
	return mRadius;
}

bool Entity::collidedWith(Collidable *target)
{
	if (mSprite)
	{
		CCPoint targetPos = target->getPosition();
		float targetRadius = target->getRadius();

		CCPoint pos = getPosition();

		float dx = pos.x - targetPos.x;
		float dy = pos.y - targetPos.y;
		float radiusSum = mRadius + targetRadius;

		if ((dx*dx) + (dy*dy) < radiusSum*radiusSum)
		{
			return true;
		}
	}
	return false;
}

void Entity::updatePosition(float dt, float xDelta, float yDelta)
{
	if (mSprite)
	{
		CCPoint pos = mSprite->getPosition();

		pos.x += xDelta * dt;
		pos.y += yDelta * dt;
		mSprite->setPosition(pos);
	}
}


void Entity::firePrimary()
{

}

void Entity::fireSecondary()
{

}

