#include "RuamTime.h"

RuamTime::RuamTime()
	: m_lastFrame(0.0f), m_currentFrame(0.0f)
{

}

RuamTime::~RuamTime()
{

}

void RuamTime::Update()
{
	m_lastFrame = m_currentFrame;
	m_currentFrame = glfwGetTime();
}

