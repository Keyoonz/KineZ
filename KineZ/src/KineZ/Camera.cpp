#include "Camera.h"

KineZ::Camera::Camera(float x, float y, int width, int height, float rotation)
	: m_position(x, y, -1.0f), m_width(width), m_height(height), m_rotation(rotation), m_viewMatrix(glm::translate(glm::mat4(), m_position) * glm::rotate(glm::mat4(), rotation, glm::vec3(0.0f, 0.0f, 1.0f))), m_projectionMatrix(glm::ortho((float)-width / 2, (float)width / 2, (float)-height / 2, (float)height / 2, -1.0f, 1.0f))
{

}

KineZ::Camera::~Camera()
{
}

int KineZ::Camera::getX()
{
	return m_position.x;
}

int KineZ::Camera::getY()
{
	return m_position.y;
}

int KineZ::Camera::getWidth()
{
	return m_width;
}

int KineZ::Camera::getHeight()
{
	return m_height;
}

void KineZ::Camera::Move(float x, float y)
{
	m_position += glm::vec3(x, y, -1.0f);
	m_viewMatrix = glm::translate(glm::mat4(), m_position) * glm::rotate(glm::mat4(), m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
}

void KineZ::Camera::SetPosition(float x, float y)
{
	m_position = glm::vec3(x, y, -1.0f);
	m_viewMatrix = glm::translate(glm::mat4(), m_position) * glm::rotate(glm::mat4(), m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));

}

void KineZ::Camera::Inflate(float x, float y)
{
	m_width += x;
	m_height += y;
	m_projectionMatrix = glm::ortho((float)-m_width / 2, (float)m_width / 2, (float)-m_height / 2, (float)m_height / 2, -1.0f, 1.0f);
}

void KineZ::Camera::Resize(int width, int height)
{
	m_width = width;
	m_height = height;
	m_projectionMatrix = glm::ortho((float)-m_width / 2, (float)m_width / 2, (float)-m_height / 2, (float)m_height / 2, -1.0f, 1.0f);
}

void KineZ::Camera::Rotate(float angle)
{
	m_rotation += angle;
	m_viewMatrix = glm::translate(glm::mat4(), m_position) * glm::rotate(glm::mat4(), m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
}

void KineZ::Camera::SetRotation(float angle)
{
	m_rotation = angle;
	m_viewMatrix = glm::translate(glm::mat4(), m_position) * glm::rotate(glm::mat4(), m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
}

const glm::mat4* const KineZ::Camera::GetViewMatrix()
{
	return &m_viewMatrix;
}

const glm::mat4* const KineZ::Camera::GetProjectionMatrix()
{
	return &m_projectionMatrix;
}

void KineZ::Camera::SetupRender()
{
	
}





