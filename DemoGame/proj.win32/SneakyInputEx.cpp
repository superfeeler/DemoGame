#include "SneakyInputEx.h"
#include "SneakyInput\SneakyButtonSkinnedBase.h"
#include "SneakyInput\SneakyButton.h"
#include "SneakyInput\SneakyJoystickSkinnedBase.h"
#include "SneakyInput\SneakyJoystick.h"


SneakyJoystickSkinnedBase *SneakyInputEx::joystickSkinnedBase(CCRect padRect, const char* bgSprite,	const char* thumbSprite) 
{
	SneakyJoystickSkinnedBase *joystickBase = new SneakyJoystickSkinnedBase();
	if(joystickBase)
	{
		joystickBase->autorelease();
		joystickBase->init();
		joystickBase->setBackgroundSprite(CCSprite::createWithSpriteFrameName(bgSprite));
		joystickBase->setThumbSprite(CCSprite::createWithSpriteFrameName(thumbSprite));
		

		SneakyJoystick *joystick = new SneakyJoystick();
		
		if (joystick)
		{
			joystick->autorelease();
			joystick->initWithRect(padRect);
			joystick->setAutoCenter(true);
			joystick->setHasDeadzone(true);
			joystick->setDeadRadius(10);
			
			joystickBase->setJoystick(joystick);
			return joystickBase;
		}
		joystickBase->release();
	}
	return NULL;
}

SneakyButtonSkinnedBase *SneakyInputEx::buttonSkinnedBase(CCRect btnRect, const char *upSprite, const char *downSprite)
{
	SneakyButtonSkinnedBase *buttonBase = new SneakyButtonSkinnedBase();
	if (buttonBase)
	{
		buttonBase->autorelease();
		buttonBase->init();
		buttonBase->setDefaultSprite(CCSprite::createWithSpriteFrameName(upSprite));
		buttonBase->setActivatedSprite(CCSprite::createWithSpriteFrameName(downSprite));
		buttonBase->setPressSprite(CCSprite::createWithSpriteFrameName(downSprite));

		SneakyButton *button = new SneakyButton();
		if (button)
		{
			button->autorelease();
			button->initWithRect(btnRect);
			button->setIsToggleable(false);
			button->setIsHoldable(true);

			buttonBase->setButton(button);
			return buttonBase;
		}
		buttonBase->release();
	}
	return NULL;
}