#include "TestTexture2D.h"

#include "Renderer.h"
#include "imgui.h"

namespace test
{

	TestTexture2D::TestTexture2D()
		: m_ClearColor{ 0.2f, 0.1f, 0.3f, 1.0f }
	{

	}

	TestTexture2D::~TestTexture2D()
	{

	}

	void TestTexture2D::Update()
	{

	}

	void TestTexture2D::Render()
	{
		GLCall(glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void TestTexture2D::ImGuiRender()
	{
	}

}