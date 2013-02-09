#include "System.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "Foundation/Foundation.h"
#endif

bool System::mIsPad = false;

CCPoint System::PointMake(float x, float y)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	if (mIsPad)
	{
		return ccp(x*2+32, y*2+64);
	}
	else
#endif
		return ccp(x, y);
}

float System::GetRealSize(float size)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	if(mIsPad)
	{
		return size;
	}
	else
#endif
		return size/2;
}

bool System::isPad() 
{
	return mIsPad;
}
