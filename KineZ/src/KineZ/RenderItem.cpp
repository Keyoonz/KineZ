#include "RenderItem.h"


#include "utils/DoubleLinkedList.h"
//For KineZ Only
KINEZ_API KineZ::DoubleLinkedList<KineZ::RenderItem*> k_renderItems;

#include <iostream>
#include <glm/gtx/string_cast.hpp>

KineZ::RenderItem::RenderItem()
	: id(0), m_vbo(0), m_ebo(0), m_transformationMatrix(glm::mat4(1.0f)), m_rotation(60.0f,30.0f,30.0f)
{
	m_transformationMatrix = glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_transformationMatrix = glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));


	float vertices[24] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
	};

	int indices[36] = {
		0, 1, 2,
		0, 2, 3,
		1, 2, 5,
		5, 2, 6,
		6, 2, 7,
		7, 3, 2,
		3, 4, 7,
		3, 4, 0,
		0, 1, 4,
		4, 5, 1,
		4, 5, 6,
		4, 6, 7
	};


	glGenVertexArrays(1, &id);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	glBindVertexArray(id);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void KineZ::RenderItem::render(const KineZ::Shader& shader)
{
	shader.SendMatrix4f(m_transformationMatrix, "transformationMatrix");
	shader.Bind();
	glBindVertexArray(id);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}

void KineZ::RenderItem::addRenderItems(RenderItem* item)
{
	k_renderItems.push_back(item);
}

void KineZ::RenderItem::Rotate(float x, float y, float z)
{
	m_rotation += glm::vec3(x, y, z);
	m_transformationMatrix = glm::mat4(1.0f);
	m_transformationMatrix = glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_transformationMatrix = glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

void KineZ::RenderItem::Rotate(glm::vec3 rotation)
{
	m_rotation += rotation;
	m_transformationMatrix = glm::mat4(1.0f);
	m_transformationMatrix = glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_transformationMatrix = glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

void KineZ::RenderItem::SetRotation(float x, float y, float z)
{
	m_rotation = glm::vec3(x, y, z);
	m_transformationMatrix = glm::mat4(1.0f);
	m_transformationMatrix = glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_transformationMatrix = glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

void KineZ::RenderItem::SetRotation(glm::vec3 rotation)
{
	m_rotation = rotation;
	m_transformationMatrix = glm::mat4(1.0f);
	m_transformationMatrix = glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_transformationMatrix = glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_transformationMatrix = glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

