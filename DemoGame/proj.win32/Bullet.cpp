#include "Bullet.h"

#include "System.h"
#include "SimpleMoveController.h"



Bullet::Bullet(void)
{

}


Bullet::~Bullet(void)
{

}

Bullet *Bullet::bulletWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	Bullet *bullet = new Bullet();
	if (bullet && bullet->init(spriteBatch))
	{
		bullet->autorelease();
		return bullet;
	}
	else
	{
		CC_SAFE_DELETE(bullet);
		return NULL;
	}
}

bool Bullet::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
	do
	{
		CCNode *parent = spriteBatch->getParent();

		CC_BREAK_IF(! Entity::init(parent));

		CCSprite *sprite = CCSprite::createWithSpriteFrameName("gemGreen.png");
		CC_BREAK_IF( !sprite);

		spriteBatch->addChild(sprite);

		setVisual(sprite);

		SimpleMoveController *controller = SimpleMoveController::controllerWithParentNode(parent);
		CC_BREAK_IF(! controller);

		float speed = 200;
		controller->setSpeed(speed);

		setController(controller);

		setRadius(System::GetRealSize(15));

		bRet = true;
	} while (0);
	return bRet;
}

void Bullet::updatePosition(float dt, float xDelta, float yDelta) 
{
	Entity::updatePosition(dt, xDelta, yDelta);

	CCPoint pos = getPosition();

	if (pos.x > BULLET_RIGHT_LIMIT)
	{
		setActive(false);
	}
}