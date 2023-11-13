#include "Camera.h"

KineZ::Camera::Camera(float x, float y, int width, int height)
	: m_position(x, y, -1.0f), m_width(width), m_height(height), m_viewMatrix(glm::lookAt(m_position, m_position + glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0, 1, 0))), m_projectionMatrix(glm::ortho((float) - width / 2, (float) width / 2, (float) - height / 2, (float) height / 2, -1.0f, 1.0f))
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
	m_position += glm::vec3(x, y, 0.0f);
}
