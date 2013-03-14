#include "Controller.h"

Controller::Controller()
{
	mListener = NULL;
}

Controller::~Controller()
{

}


bool Controller::init()
{
	bool bRet = false;
	do
	{
		this->scheduleUpdate();
		bRet = true;
	} while (0);
	return bRet;
}

void Controller::setControllerListener(ControllerListener *listener)
{
	mListener = listener;
}
