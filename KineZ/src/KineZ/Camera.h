#pragma once

#include "Core.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "Shader.h"

#include "OpenGlRelated.h"

namespace KineZ {
	class KINEZ_API Camera
	{
	private:
		int m_width, m_height;
		glm::vec3 m_position;
		float m_rotation;
		glm::mat4 m_viewMatrix;
		glm::mat4 m_projectionMatrix;
	public:
		Camera(float x, float y, int width, int height, float rotation);
		~Camera();

		int getX();
		int getY();
		int getWidth();
		int getHeight();

		void Move(float x, float y);
		void SetPosition(float x, float y);
		void Inflate(float x, float y);
		void Resize(int width, int height);
		void Rotate(float angle);
		void SetRotation(float angle);

		const glm::mat4* const GetViewMatrix();
		const glm::mat4* const GetProjectionMatrix();

		void SetupRender(const Shader& shader);
	};
}

