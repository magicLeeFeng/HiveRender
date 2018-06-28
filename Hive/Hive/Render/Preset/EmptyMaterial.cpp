#include "EmptyMaterial.h"
#include <iostream>
#include <fstream>

EmptyMaterial::EmptyMaterial(void)
{
	this->createEmptyShader();
}


EmptyMaterial::~EmptyMaterial(void)
{
}

void EmptyMaterial::createEmptyShader()
{
	std::string vShader =  "";
		vShader += "void main() {\n";
		vShader += " gl_Position = ARMVP * ARPosition;\n";
		vShader += "}";

	std::string fShader =  "precision mediump float;\n";
		fShader += "uniform sampler2D s_texture;\n";
		fShader += "void main() {\n";
		fShader += " gl_FragColor = vec4(1,1,1,1);\n";
		fShader += "}";
	this->createShader(vShader.c_str(),fShader.c_str());
}