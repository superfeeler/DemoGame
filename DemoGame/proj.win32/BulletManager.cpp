#include "BulletManager.h"
#include "Bullet.h"
#include "SoundManager.h"


BulletManager::BulletManager(void)
	:mBulletList(NULL), mCurrentIndex(0), mBulletListener(NULL)
{
}


BulletManager::~BulletManager(void)
{
	CC_SAFE_DELETE(mBulletList);
}

BulletManager *BulletManager::initWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	BulletManager *manager = new BulletManager();
	if(manager && manager->init(spriteBatch))
	{
		manager->autorelease();
		return manager;
	}
	else
	{
		CC_SAFE_DELETE(manager);
		return NULL;
	}
}

bool BulletManager::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
	do
	{
		CCNode *parentNode = spriteBatch->getParent();

		mBulletList = new CCArray(MAX_BULLET);
		mBulletList->retain();

		for (int i = 0; i < MAX_BULLET; i++)
		{
			Bullet *bullet = Bullet::bulletWithBatchNode(spriteBatch);
			bullet->setActive(false);
			mBulletList->addObject(bullet);
			parentNode->addChild(bullet);
		}
		this->scheduleUpdate();
		bRet = true;

	} while (0);
	return bRet;
}

void BulletManager::update(float dt) 
{
	if (mBulletListener)
	{
		CCObject *obj = NULL;
		//CCARRAY_FOREACH(mBulletList, (CCObject *)obj)
		if(mBulletList && mBulletList->data->num >0) {
			for(int i = 0; i < mBulletList->data->num; i++)
			{
				Bullet *bullet = (Bullet*) mBulletList->objectAtIndex(i);
				if (bullet->isActive() && mBulletListener->collideWithBullet(bullet))
				{
					SoundManager::sharedSoundManager()->playHitSFX();
					bullet->setActive(false);
				}
			}
		}
	}
}

void BulletManager::setBulletListener(BulletListener *listener)
{
	mBulletListener = listener;
}

void BulletManager::shoot(const CCPoint &fromPosition)
{
	SoundManager::sharedSoundManager()->playLaserSFX();

	Bullet *bullet = (Bullet*) mBulletList->objectAtIndex(mCurrentIndex);
	bullet->setPosition(fromPosition);
	bullet->setActive(true);

	mCurrentIndex++;
	if (mCurrentIndex >= MAX_BULLET)
	{
		mCurrentIndex = 0;
	}
}