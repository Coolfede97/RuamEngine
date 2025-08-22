#include "RuamTime.h"

namespace ruamTime
{

	float Time::m_currentFrame = 0.0f;
	float Time::m_lastFrame = 0.0f;

	void Time::Update()
	{
		m_lastFrame = m_currentFrame;
		m_currentFrame = glfwGetTime();
	}
}

