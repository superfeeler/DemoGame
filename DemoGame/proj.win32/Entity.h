#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "Controller.h"
#include "Collision.h"

class Entity :
	public CCNode, public ControllerListener, public Collidable
{
public:
	Entity(void);
	~Entity(void);
	virtual bool init(CCNode *parent);

	void setVisual(CCSprite *sprite);
	void setController(Controller *controller);

	void setRadius(float radius);

	void setPosition(const CCPoint &point);

	void setActive(bool flag);

	bool isActive();

	//Controller Listener
	virtual void updatePosition(float dt, float xDelta, float yDelta);
	virtual void firePrimary();
	virtual void fireSecondary();

	// Collidable
	virtual bool collidedWith(Collidable *target);
	virtual const CCPoint& getPosition();
	virtual float getRadius();

private:
	bool mActive;
	CCSprite* mSprite;
	float mRadius;
	Controller *mController;
};

#endif