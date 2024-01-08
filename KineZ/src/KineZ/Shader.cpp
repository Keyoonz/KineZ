#include "Shader.h"
#include "Logger.h"

#include <fstream>
#include <sstream>

#include <iostream>

std::string KineZ::Shader::ParseShader(const char* path)
{
	extern Logger KZlogger;
	std::string code;
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		file.open(path);
		std::stringstream stream;
		stream << file.rdbuf();
		file.close();
		code = stream.str();
	}
	catch (std::ifstream::failure e)
	{
		KZlogger.Error("Shader file not succesfully read.");
	}
	return code;
}

void KineZ::Shader::CreateShader(const char* source, unsigned int shader)
{
	extern Logger KZlogger;
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
}

KineZ::Shader::Shader(ShaderPaths shaderPaths)
	:m_id(0)
{
	extern Logger KZlogger;
	std::string vSource = ParseShader(shaderPaths.vertexPath);
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	std::string fSource = ParseShader(shaderPaths.fragmentPath);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	CreateShader(vSource.c_str(), vertexShader);
	CreateShader(fSource.c_str(), fragmentShader);

	m_id = glCreateProgram();
	glAttachShader(m_id, vertexShader);
	glAttachShader(m_id, fragmentShader);
	glLinkProgram(m_id);

	int success;
	glGetProgramiv(m_id, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(m_id, 512, NULL, infoLog);
		KZlogger.Error(infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

KineZ::Shader::~Shader()
{
	glDeleteProgram(m_id);
}

void KineZ::Shader::Bind() const
{
	glUseProgram(m_id);
}

void KineZ::Shader::Unbind()
{
	glUseProgram(0);
}

void KineZ::Shader::SendMatrix4f(const glm::mat4& matrix, const char* name) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void KineZ::Shader::SendInt(int& value, const char* name) const
{
	glUniform1i(glGetUniformLocation(m_id, name), value);
}

