#include "TestClearColor.h"

#include "Renderer.h"
#include "imgui.h"

namespace test
{

	TestClearColor::TestClearColor()
		: m_ClearColor{ 0.2f, 0.1f, 0.3f, 1.0f }
	{

	}

	TestClearColor::~TestClearColor()
	{

	}

	void TestClearColor::Update()
	{

	}

	void TestClearColor::Render()
	{
		GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void TestClearColor::ImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
	}

}