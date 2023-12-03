#include "Shader.h"
#include "Logger.h"

#include <fstream>
#include <sstream>

#include <iostream>

std::string KineZ::Shader::ParseShader(const char* path)
{
	std::ifstream file;
	file.open(path);
	std::stringstream ss;
	std::string line;
	while (getline(file, line))
	{
		ss << line << "\n";
	}
	return ss.str();
}

unsigned int KineZ::Shader::CreateShader(const char* source, const unsigned int shaderType)
{
	extern Logger KZlogger;
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infolog[512];
		glGetShaderInfoLog(shader, 512, NULL, infolog);
		KZlogger.Error(infolog);
	}
	return shader;
}

KineZ::Shader::Shader(const char* vertexSource, const char* fragmentSource)
	:m_id(glCreateProgram())
{
	unsigned int vertexShader = CreateShader(ParseShader(vertexSource).c_str(), GL_VERTEX_SHADER);
	unsigned int fragmentShader = CreateShader(ParseShader(fragmentSource).c_str(), GL_FRAGMENT_SHADER);

	Bind();

	glAttachShader(m_id, vertexShader);
	glAttachShader(m_id, fragmentShader);

	glValidateProgram(m_id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	Shader::Unbind();
}

KineZ::Shader::~Shader()
{
	glDeleteProgram(m_id);
}

void KineZ::Shader::Bind()
{
	glUseProgram(m_id);
}

void KineZ::Shader::Unbind()
{
	glUseProgram(0);
}

