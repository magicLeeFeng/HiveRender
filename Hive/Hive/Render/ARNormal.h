/************************************************************************/
/* ·¨Ïß                                                                     */
/************************************************************************/
#pragma once

class ARVector3;

class ARNormal
{
public:
	ARNormal(void);
	explicit ARNormal(const ARVector3 &v);
	~ARNormal(void);
public:
	float x, y, z;
};

