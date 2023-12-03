#pragma once

#include "OpenGlRelated.h"
#include "Core.h"
#include "string"

namespace KineZ {
	class KINEZ_API Shader {
	private:
		unsigned int m_id;
	private:
		std::string ParseShader(const char* path);
		unsigned int CreateShader(const char* source, const unsigned int shaderType);
	public:
		Shader(const char* vertexSource, const char* fragmentSource);
		~Shader();

		void Bind();
		static void Unbind();
	};
}