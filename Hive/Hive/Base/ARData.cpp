#include "ARData.h"
#include <fstream>

ARData::ARData(void)
{
	this->_bytes = nullptr;
	this->readIndex = 0;
}


ARData::~ARData(void)
{
}

void ARData::setData(unsigned char* bytes,SSIZE_T size)
{
	this->_bytes = bytes;
	this->_size = size;
}

unsigned char* ARData::getBytes()
{
	return this->_bytes;
}

SSIZE_T ARData::getSize()
{
	return this->_size;
}

void ARData::cleanMemory()
{
	if (this->_bytes != nullptr)
	{
		free(_bytes);
	}
}
