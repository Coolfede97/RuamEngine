#pragma once

#include "GLFW/glfw3.h"

namespace ruamTime
{
	class Time
	{
	private:
		static double m_currentFrame;
		static double m_lastFrame;
	public:
		static void Update();
		static double DeltaTime() { return m_currentFrame - m_lastFrame; }
	};
}

