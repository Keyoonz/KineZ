#pragma once

#include "OpenGlRelated.h"
#include "string"
#include <glm/gtc/type_ptr.hpp>

namespace KineZ {
	struct ShaderPaths {
		const char* vertexPath;
		const char* fragmentPath;
	};

	class Shader {
	private:
		unsigned int m_id;
	private:
		void CreateShader(const char* source, const unsigned int shaderType);
		std::string ParseShader(const char* path);
	public:
		Shader(ShaderPaths shaderPaths);
		~Shader();

		void Bind() const;
		static void Unbind();

		void SendMatrix4f(const glm::mat4& matrix, const char* name) const;
		void SendInt(int& value, const char* name) const;
	};


	//To be defined in Client
	 ShaderPaths SetShaderPaths();
}