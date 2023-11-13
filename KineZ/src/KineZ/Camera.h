#pragma once

#include "Core.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"

namespace KineZ {
	class KINEZ_API Camera
	{
	private:
		int m_width, m_height;
		glm::vec3 m_position;
		glm::mat4 m_viewMatrix;
		glm::mat4 m_projectionMatrix;
	public:
		Camera(float x, float y, int width, int height);
		~Camera();

		int getX();
		int getY();
		int getWidth();
		int getHeight();

		void Move(float x, float y);
	};
}

