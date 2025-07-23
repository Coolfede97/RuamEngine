#pragma once

#include "GLFW/glfw3.h"

class RuamTime
{
private:
	float m_currentFrame;
	float m_lastFrame;
public:
	RuamTime();
	~RuamTime();
	void Update();
	float DeltaTime() const { return m_currentFrame - m_lastFrame; }
};