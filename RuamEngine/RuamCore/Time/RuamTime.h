#pragma once

#include "GLFW/glfw3.h"

namespace ruamTime
{
	class Time
	{
	private:
		float m_currentFrame;
		float m_lastFrame;
	public:
		Time();
		~Time();
		void Update();
		float DeltaTime() const { return m_currentFrame - m_lastFrame; }
	};
}

