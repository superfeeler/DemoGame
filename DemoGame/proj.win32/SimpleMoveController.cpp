#include "SimpleMoveController.h"


SimpleMoveController::SimpleMoveController(void)
{
}


SimpleMoveController::~SimpleMoveController(void)
{
}

SimpleMoveController *SimpleMoveController::controllerWithParentNode(CCNode *parent) 
{
	SimpleMoveController *controller = new SimpleMoveController();
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

bool SimpleMoveController::init(CCNode *parent) 
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(! Controller::init());
		
		mSpeed = 0;

		bRet = true;
	} while (0);
	return bRet;
}

void SimpleMoveController::update(float dt) 
{
	if (mListener)
	{
		mListener->updatePosition(dt, mSpeed, 0.0f);
	}
}

void SimpleMoveController::setSpeed(float speed)
{
	mSpeed = speed;
}

