#pragma once

#include "Camera.h"
#include "Shader.h"
#include "OpenGlRelated.h"
//#include "Texture.h"

#include <glm/glm.hpp>
#include <vector>

namespace KineZ {
	struct Texture {
		unsigned int id;
		std::string type;
		std::string path;
	};

	class Mesh
	{
	public:
		struct Vertex
		{
			glm::vec3 position;
			glm::vec3 normal;
			glm::vec2 textureCoordinates;
		};
	private:
		std::vector<Mesh::Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		unsigned int id;
		unsigned int m_vbo;
		unsigned int m_ebo;
		glm::vec3 m_rotation;
		glm::mat4 m_transformationMatrix;
	public:
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		virtual void Render(const Shader& shader);

		void Rotate(float x, float y, float z);
		void Rotate(glm::vec3 rotation);
		void SetRotation(float x, float y, float z);
		void SetRotation(glm::vec3 rotation);
	};


	//To be defined in client
	void CreateMeshes();
}

