#pragma once

#include "OpenGlRelated.h"
#include "stb_image.h"
#include "Logger.h"

namespace KineZ {
	class Texture
	{
	private:
		unsigned int m_id;
		int m_width, m_height;
	public:
		Texture(const char* path);
		~Texture();

		void Bind();
		static void Unbind();
	};
}
