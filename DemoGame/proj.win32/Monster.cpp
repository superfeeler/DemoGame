#include "System.h"

#include "Monster.h"
#include "SimpleMoveController.h"

Monster::Monster(void)
{
}


Monster::~Monster(void)
{
}

Monster *Monster::monsterWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	Monster *monster = new Monster();
	if (monster && monster->init(spriteBatch))
	{
		monster->autorelease();
		return monster;
	}
	else
	{
		CC_SAFE_DELETE(monster);
		return NULL;
	}
}

bool Monster::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
	do
	{
		CCNode *parent = spriteBatch->getParent();

		CC_BREAK_IF(! Entity::init(parent));

		CCSprite *sprite = CCSprite::createWithSpriteFrameName("enemyBug.png");
		CC_BREAK_IF(! sprite);

		sprite->setFlipX(true);
		sprite->setPosition(System::PointMake(RIGHT_LIMIT, 160));
		spriteBatch->addChild(sprite);
		setVisual(sprite);

		SimpleMoveController *controller = SimpleMoveController::controllerWithParentNode(parent);
		CC_BREAK_IF(! controller);

		float speed = -(80 + (float)(rand() % 20));
		controller->setSpeed(speed);

		setController(controller);

		setRadius(System::GetRealSize(35));

		bRet = true;
	} while (0);
	return bRet;
}

void Monster::updatePosition(float dt, float xDelta, float yDelta) 
{
	Entity::updatePosition(dt, xDelta, yDelta);
	CCPoint pos = getPosition();
	
	if (pos.x < LEFT_LIMIT)
	{
		setActive(false);
	}
}