#include "cocos2d.h"

#include "System.h"
#include "GameManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Entity.h"
#include "Constants.h"
#include "SoundManager.h"

using namespace cocos2d;

MonsterManager::MonsterManager(void)
	:mMonsterList(NULL), mAttackingTarget(NULL), mCollisionListener(NULL)
{
}


MonsterManager::~MonsterManager(void)
{
	CC_SAFE_DELETE(mMonsterList);
}

MonsterManager *MonsterManager::initWithBatchNode(CCSpriteBatchNode *spriteBatch) 
{
	MonsterManager *manager = new MonsterManager();
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

bool MonsterManager::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
	do
	{
		CCNode *parentNode = spriteBatch->getParent();
		mMonsterList = new CCArray(MAX_MONSTER);
		mMonsterList->retain();

		for (int i = 0; i < MAX_MONSTER; i++)
		{
			Monster *monster = Monster::monsterWithBatchNode(spriteBatch);
			monster->setActive(false);

			mMonsterList->addObject(monster);

			parentNode->addChild(monster);
		}
		this->scheduleUpdate();
		mTimer = 0.0f;

		mCurrentIndex = 0;

		bRet = true;
	} while (0);
	return bRet;
}

void MonsterManager::update(float dt)
{
	mTimer += dt;

	if (mTimer > SPAWN_TIME)
	{
		mTimer = 0;

		float y = 20 + (float)(rand() % 380);

		Monster *monster = (Monster *) mMonsterList->objectAtIndex(mCurrentIndex);
		monster->setPosition(System::PointMake(RIGHT_LIMIT, y));
		monster->setActive(true);

		mCurrentIndex++;

		if (mCurrentIndex >= MAX_MONSTER)
		{
			mCurrentIndex = 0;
		}
	}

	if (mAttackingTarget)
	{
		CCObject *obj = NULL;

		//CCARRAY_FOREACH(mMonsterList, (CCObject *)obj)
		if(mMonsterList && mMonsterList->data->num > 0) {
			for(int i = 0; i < mMonsterList->data->num; i++)
			{
				{
					Monster *monster = (Monster *) mMonsterList->objectAtIndex(i);
					if (monster->isActive() && monster->collidedWith(mAttackingTarget))
					{
						SoundManager::sharedSoundManager()->playHitSFX();
						if (mCollisionListener)
						{
							mCollisionListener->CollisionDetected(monster, mAttackingTarget);
						}
					}
				}
			}
		}
	}
}

void MonsterManager::setAttackingTarget(Collidable *target)
{
	mAttackingTarget = target;
}

void MonsterManager::setCollisionListener(CollisionListener *listener)
{
	mCollisionListener = listener;
}

bool MonsterManager::collideWithBullet(Collidable *bullet)
{
	CCObject *obj = NULL;
	//CCARRAY_FOREACH(mMonsterList, (CCObject *)obj)
	if(mMonsterList && mMonsterList->data->num > 0) 
	{
		for (int i = 0; i < mMonsterList->data->num; i++)
		{
			Monster *monster = (Monster *)mMonsterList->objectAtIndex(i);
			if (monster->isActive() && monster->collidedWith(bullet))
			{
				CCNode *parent = this->getParent();
				CCParticleSystemQuad *m_emitter = (CCParticleSystemQuad *)parent->getChildByTag(TAB_PARTICLE);

				if (m_emitter && !m_emitter->isActive())
				{
					CCPoint pos = monster->getPosition();

					m_emitter->resetSystem();
					m_emitter->setPosition(pos);

				}
				monster->setActive(false);
				return true;
			}
		}
	}
	return false;
}