#ifndef __KEYBOARD_CONTROLLER_H__
#define __KEYBOARD_CONTROLLER_H__

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "Controller.h"

class KeyboardController :
	public Controller
{
public:
	KeyboardController(void);
	~KeyboardController(void);

	static KeyboardController *controllerWithParentNode(CCNode *parent);

	bool init(CCNode *parent);

	virtual void update(float dt);

private:
	float mMovingSpeed;

	bool mFireKeyDown;

};
#endif

#endif