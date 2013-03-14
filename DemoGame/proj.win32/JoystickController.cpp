#include "JoystickController.h"
#include "SneakyInput\SneakyJoystick.h"
#include "SneakyInput\SneakyJoystickSkinnedBase.h"
#include "SneakyInput\SneakyButton.h"
#include "SneakyInput\SneakyButtonSkinnedBase.h"

#include "JoystickController.h"

#include "SneakyInputEx.h"
#include "System.h"
#include "Constants.h"

JoystickController::JoystickController(void)
{
}


JoystickController::~JoystickController(void)
{
}

JoystickController *JoystickController::controllerWithParentNode(CCNode* parent) 
{
	JoystickController *controller = new JoystickController();
	if (controller && controller->init(parent))
	{
		controller->autorelease();
		return controller;
	}
	else
	{
		CC_SAFE_DELETE(controller);
		return NULL;
	}
}


bool JoystickController::init(CCNode* parent)
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Controller::init());
		
		SneakyJoystickSkinnedBase *joystickBase = SneakyInputEx::joystickSkinnedBase(CCRect(0, 0, 64, 64), "circleBig.png", "circleSmall.png");
		if (joystickBase)
		{
			joystickBase->setPosition(System::PointMake(48, 48));
			mJoystick = joystickBase->getJoystick();
			parent->addChild(joystickBase);
		}

		SneakyButtonSkinnedBase *buttonBase = SneakyInputEx::buttonSkinnedBase(CCRect(0,0,100,100), "buttonBlue.png", "buttonOrange.png");

		if (buttonBase)
		{
			buttonBase->setPosition(System::PointMake(ANDROID_G7_WIDTH-48, 32));

			mButton = buttonBase->getButton();
			parent->addChild(buttonBase);
		}
		
		mButtonDown = false;
		bRet = true;

	} while (0);
	return bRet;
}


void JoystickController::update(float dt)
{
	if (mListener)
	{
		CCPoint scaledV = ccpMult(mJoystick->getVelocity(), ANDROID_G7_HEIGHT);

		mListener->updatePosition(dt, scaledV.x, scaledV.y);
		
		if (mButton->getIsActive())
		{
			if (!mButtonDown)
			{
				mButtonDown = true;
				mListener->firePrimary();
			}
		}
		else
		{
			mButtonDown = false;
		}
	}
}