#include "RuamTime.h"

namespace ruamTime
{
	Time::Time()
		: m_lastFrame(0.0f), m_currentFrame(0.0f)
	{

	}

	Time::~Time()
	{

	}

	void Time::Update()
	{
		m_lastFrame = m_currentFrame;
		m_currentFrame = glfwGetTime();
	}
}

