#include "Player.h"
#include "System.h"
#include "Constants.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "KeyboardController.h"
#else
#include "JoystickController.h"
#endif

#include "BulletManager.h"



Player::Player(void):mShooter(NULL)
{
}


Player::~Player(void)
{
}

Player *Player::playWithBatchNode(CCSpriteBatchNode *spriteBatch) 
{
	Player *player = new Player();
	if (player && player->init(spriteBatch))
	{
		player->autorelease();
		return player;
	}
	else
	{
		CC_SAFE_DELETE(player);
		return NULL;
	}

}

bool Player::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
	do
	{
		CCNode *parent = spriteBatch->getParent();
		CC_BREAK_IF(! Entity::init(parent));
		CCSprite *sprite = CCSprite::createWithSpriteFrameName("beetleship.png");
		CC_BREAK_IF(! sprite);

		sprite->setPosition(System::PointMake(80, 160));
		spriteBatch->addChild(sprite);

		setVisual(sprite);

		
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		KeyboardController *controller = KeyboardController::controllerWithParentNode(parent);
#else
		JoystickController *controller = JoystickController::controllerWithParentNode(parent);
#endif
		CC_BREAK_IF(! controller);

		setController(controller);

		setRadius(System::GetRealSize(50));

		bRet = true;

	} while (0);
	return bRet;
}

void Player::updatePosition(float dt, float xDelta, float yDelta)
{
	Entity::updatePosition(dt, xDelta, yDelta);

	CCPoint pos = getPosition();

	pos = ccpClamp(pos, System::PointMake(0,0), System::PointMake(ANDROID_G7_WIDTH, ANDROID_G7_HEIGHT));

	setPosition(pos);
}

void Player::firePrimary()
{
	if(mShooter)
	{
		CCPoint pos = getPosition();
		pos.x += System::GetRealSize(100);

		mShooter->shoot(pos);
	}
}

void Player::setShooter(Shooter *shooter) 
{
	mShooter = shooter;
}