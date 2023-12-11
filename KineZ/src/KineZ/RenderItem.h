#pragma once

#include "Core.h"
#include "Camera.h"
#include "Shader.h"

#include "OpenGlRelated.h"
#include "glm/glm.hpp"

namespace KineZ {
	class KINEZ_API RenderItem
	{
	public:
		unsigned int id;
	private:
		unsigned int m_vbo;
		unsigned int m_ebo;
		glm::vec3 m_rotation;
		glm::mat4 m_transformationMatrix;
	public:
		RenderItem();
		virtual void render(const Shader& shader);
		static void addRenderItems(RenderItem* item);

		void Rotate(float x, float y, float z);
		void Rotate(glm::vec3 rotation);
		void SetRotation(float x, float y, float z);
		void SetRotation(glm::vec3 rotation);
	};


	//To be defined in client
	void CreateRenderItems();
}

