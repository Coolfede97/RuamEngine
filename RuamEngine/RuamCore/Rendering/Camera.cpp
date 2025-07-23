#include "Camera.h"
Camera::Camera()
	: m_position(0.0f, 0.0f, 0.0f), m_direction(0.0f, 0.0f, -1.0f), m_up(0.0f, 1.0f, 0.0f),
	  m_near_plane(0.1f), m_far_plane(100.0f), m_fov(45.0f), m_aspect_ratio(800.0f/600.0f)
{

}

Camera::~Camera()
{

}

