#include "RuamTime.h"

namespace ruamTime
{

	double Time::m_currentFrame = 0.0f;
	double Time::m_lastFrame = 0.0f;

	void Time::Update()
	{
		m_lastFrame = m_currentFrame;
		m_currentFrame = glfwGetTime();
	}
}

