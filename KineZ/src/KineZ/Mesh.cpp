#include "Mesh.h"

#include <glm/gtx/string_cast.hpp>
#include <iostream>

KineZ::Mesh::Mesh(std::vector<Vertex> vertices,
                  std::vector<unsigned int> indices,
                  std::vector<Texture> textures)
    : id(0), m_vbo(0), m_ebo(0), m_transformationMatrix(glm::mat4(1.0f)),
      m_rotation(60.0f, 30.0f, 30.0f) {
  m_transformationMatrix =
      glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x),
                  glm::vec3(1.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y),
                  glm::vec3(0.0f, 1.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z),
                  glm::vec3(0.0f, 0.0f, 1.0f));
  m_transformationMatrix =
      glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));

  this->vertices = vertices;
  this->indices = indices;
  this->textures = textures;

  glGenVertexArrays(1, &id);
  glGenBuffers(1, &m_vbo);
  glGenBuffers(1, &m_ebo);

  glBindVertexArray(id);

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
               &indices[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, position));
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, normal));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, textureCoordinates));
  glEnableVertexAttribArray(2);

  glBindVertexArray(0);
}

void KineZ::Mesh::Render(const KineZ::Shader &shader) {
  shader.Bind();
  shader.SendMatrix4f(m_transformationMatrix, "transformationMatrix");
  unsigned int diffuseNr = 1;
  unsigned int specularNr = 1;
  unsigned int normalNr = 1;
  unsigned int heightNr = 1;
  for (int i = 0; i < textures.size(); i++) {
    glActiveTexture(GL_TEXTURE0 + i);

    std::string number;
    std::string name = textures[i].type;
    if (name == "texture_diffuse")
      number = std::to_string(diffuseNr++);
    else if (name == "texture_specular")
      number = std::to_string(specularNr++);
    else if (name == "texture_normal")
      number = std::to_string(normalNr++);
    else if (name == "texture_height")
      number = std::to_string(heightNr++);

    shader.SendInt(i, (name + number).c_str());
    glBindTexture(GL_TEXTURE_2D, textures[i].id);
  }
  glBindVertexArray(id);
  glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()),
                 GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);

  glActiveTexture(GL_TEXTURE0);
  Shader::Unbind();
}

void KineZ::Mesh::Rotate(float x, float y, float z) {
  m_rotation += glm::vec3(x, y, z);
  m_transformationMatrix = glm::mat4(1.0f);
  m_transformationMatrix =
      glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x),
                  glm::vec3(1.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y),
                  glm::vec3(0.0f, 1.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z),
                  glm::vec3(0.0f, 0.0f, 1.0f));
  m_transformationMatrix =
      glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

void KineZ::Mesh::Rotate(glm::vec3 rotation) {
  m_rotation += rotation;
  m_transformationMatrix = glm::mat4(1.0f);
  m_transformationMatrix =
      glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x),
                  glm::vec3(1.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y),
                  glm::vec3(0.0f, 1.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z),
                  glm::vec3(0.0f, 0.0f, 1.0f));
  m_transformationMatrix =
      glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

void KineZ::Mesh::SetRotation(float x, float y, float z) {
  m_rotation = glm::vec3(x, y, z);
  m_transformationMatrix = glm::mat4(1.0f);
  m_transformationMatrix =
      glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x),
                  glm::vec3(1.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y),
                  glm::vec3(0.0f, 1.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z),
                  glm::vec3(0.0f, 0.0f, 1.0f));
  m_transformationMatrix =
      glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}

void KineZ::Mesh::SetRotation(glm::vec3 rotation) {
  m_rotation = rotation;
  m_transformationMatrix = glm::mat4(1.0f);
  m_transformationMatrix =
      glm::translate(m_transformationMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.x),
                  glm::vec3(1.0f, 0.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.y),
                  glm::vec3(0.0f, 1.0f, 0.0f));
  m_transformationMatrix =
      glm::rotate(m_transformationMatrix, glm::radians(m_rotation.z),
                  glm::vec3(0.0f, 0.0f, 1.0f));
  m_transformationMatrix =
      glm::scale(m_transformationMatrix, glm::vec3(100.0f, 100.0f, 100.0f));
}
