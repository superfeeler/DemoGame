#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"

using namespace cocos2d;

//interface
class ControllerListener
{
public:
	virtual void updatePosition(float dt, float xDelta, float yDelta) = 0;
	virtual void firePrimary() = 0;
	virtual void fireSecondary() = 0;
};

class Controller : public CCNode
{
public:
	Controller(void);
	~Controller(void);

	virtual bool init();

	void setControllerListener(ControllerListener *listener);

protected:

	ControllerListener *mListener;

};

#endif