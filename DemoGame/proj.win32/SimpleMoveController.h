#ifndef __SIMPLE_MOVE_CONTROLLER_H__
#define __SIMPLE_MOVE_CONTROLLER_H__

#include "cocos2d.h"
#include "Controller.h"

using namespace cocos2d;

class SimpleMoveController :
	public Controller
{
public:
	SimpleMoveController(void);
	~SimpleMoveController(void);
	
	static SimpleMoveController *controllerWithParentNode(CCNode *parent);

	bool init(CCNode *parent);

	virtual void update(float dt);

	void setSpeed(float speed);

private:

	float mSpeed;
};

#endif