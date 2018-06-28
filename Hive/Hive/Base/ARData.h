#pragma once
#include <basetsd.h>

class ARData
{
public:
	ARData(void);
	~ARData(void);
	void setData(unsigned char* bytes,SSIZE_T size);
	unsigned char* getBytes();
	SSIZE_T getSize();
	void cleanMemory();
private:
	unsigned char* _bytes;
	SSIZE_T _size;
	int readIndex;
};

