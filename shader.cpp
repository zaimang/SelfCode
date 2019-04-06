#include "shader.h"

Shader::Shader(const GLchar * vertexPath, const GLchar *fragPath)
{
	int vsFileSize = 0, fsFileSize = 0;
	const GLchar* vertexStr = LoadFileContent(vertexPath, vsFileSize);
	const GLchar* fragStr = LoadFileContent(fragPath, fsFileSize);

	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];
	
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexStr, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		printf("±àÒë¶¥µã×ÅÉ«Æ÷´íÎó£º%s", infoLog);
	}
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragStr, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		printf("±àÒëÆ¬¶Î×ÅÉ«Æ÷´íÎó£º%s", infoLog);
	}

	this->mProgram = glCreateProgram();
	glAttachShader(this->mProgram, vertex);
	glAttachShader(this->mProgram, fragment);
	glLinkProgram(this->mProgram);
	glGetProgramiv(this->mProgram, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->mProgram, 512, NULL, infoLog);
		printf("±àÒë×ÅÉ«Æ÷³ÌÐò´íÎó£º%s", infoLog);
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::Use()
{
	glUseProgram(this->mProgram);
}
