#include "ARBBox.h"
//#include <algorithm>

using namespace std;

ARBBox::ARBBox(void)
{
}

ARBBox::ARBBox(const ARPoint &p1,const ARPoint &p2)
{
	//this->pMin = ARPoint(min(p1.x,p2.x),min(p1.y,p2.y),min(p1.z,p2.z));
}


ARBBox::~ARBBox(void)
{
}

ARPoint ARBBox::lerp(float tx,float ty,float tz)
{
	return ARPoint();
}
