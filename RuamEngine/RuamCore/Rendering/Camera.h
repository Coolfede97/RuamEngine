#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera
{
private:

public:
	Camera();
	~Camera();

	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::vec3 m_up;

	float m_near_plane;
	float m_far_plane;
	float m_fov;
	float m_aspect_ratio;
	
	glm::mat4 GetProjectionMatrix() const { return glm::perspective(glm::radians(m_fov), m_aspect_ratio, m_near_plane, m_far_plane); }
	glm::mat4 GetViewMatrix() const { return glm::lookAt(m_position, m_position + m_direction, m_up); }
};
