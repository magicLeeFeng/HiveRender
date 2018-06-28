#include "ARMatrix.h"
#include <string.h>
#include <iostream>
#include "ARVector.h"

/************************************************************************/
/* //¶þÎ¬¾ØÕó                                                                     */
/************************************************************************/
Mat2::Mat2()
{
}

Mat2::~Mat2()
{
}

/************************************************************************/
/* //ÈýÎ¬¾ØÕó                                                                     */
/************************************************************************/
Mat3::Mat3()
{
}

Mat3::~Mat3()
{
}


/************************************************************************/
/* //ËÄÎ¬¾ØÕó                                                                     */
/************************************************************************/
Mat4::Mat4(void)
{
	this->setUnit();
}

Mat4::Mat4(float _value[4][4])
{
	this->setUnit();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->value[i][j] = _value[i][j];
		}
	}
}

Mat4::~Mat4(void)
{
	
}

Mat4 Mat4::operator*(const Mat4 &m)
{
	float vRet[4][4] ={0.0f};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vRet[i][j] = 0.0f;
			for (int k = 0; k < 4; k++)
			{
				vRet[i][j] += this->value[i][k] * m.value[k][j];
			}
		}
	}
	return Mat4(vRet);
}

ARVector4 Mat4::operator*(const ARVector4 &v)
{
	float fTab[4] = {0};
	for (int j = 0 ;j< 4 ;j++)
	{
		for (int k = 0; k < 4; k++)
		{
			fTab[j] += this->value[j][k] * v.value[k];
		}
	}
	ARVector4 vRet(fTab[0],fTab[1],fTab[2],fTab[3]);
	return vRet;
}

void Mat4::setUnit()
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4; j++)
		{
			if (i == j)
			{
				this->value[i][j] = 1.0f;
			}else
			{
				this->value[i][j] = 0.0f;
			}
		}
	}	
}

void Mat4::setZero()
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4; j++)
		{
			this->value[i][j] = 0;
		}
	}	
}

void Mat4::setRotationX(float value)
{
	this->setUnit();
	this->value[1][1] = cos(value);
	this->value[1][2] = sin(value);
	this->value[2][1] = sin(value)*-1;
	this->value[2][2] = cos(value);
}

void Mat4::setRotationY(float value)
{
	this->setUnit();
	this->value[0][0] = cos(value);
	this->value[0][2] = sin(value)*-1;
	this->value[2][0] = sin(value);
	this->value[2][2] = cos(value);
}

void Mat4::setRotationZ(float value)
{
	this->setUnit();
	this->value[0][0] = cos(value);
	this->value[0][1] = sin(value);
	this->value[1][0] = sin(value)*-1;
	this->value[1][1] = cos(value);
}

void Mat4::setMove(float x,float y,float z)
{
	this->setUnit();
	this->value[3][0] = x;
	this->value[3][1] = y;
	this->value[3][2] = z;
}

void Mat4::setScale(float x,float y,float z)
{
	this->setUnit();
	this->value[0][0] = x;
	this->value[1][1] = y;
	this->value[2][2] = z;
}

void Mat4::print()
{
	printf("==== \n");
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4; j++)
		{
			std::printf("%f ",this->value[i][j]);
		}
		printf("\n");
	}

}
