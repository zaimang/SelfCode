#pragma once
#ifndef SHADER_H
#define SHADER_H
//#include "GLH.h"
#include "utils.h"
//#include <GL/glew.h>
class Shader {
	GLuint mProgram;
public:
	Shader(const GLchar *vertexPath, const GLchar *fragPath);

	void Use();
};

#endif