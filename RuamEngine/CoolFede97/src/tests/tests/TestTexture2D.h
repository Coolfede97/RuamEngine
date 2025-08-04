#pragma once

#include "Test.h"
#include "GLM/glm.hpp"

namespace test
{
	class TestTexture2D : public Test
	{
	public:
		TestTexture2D();
		~TestTexture2D();
		
		void Update() override;
		void Render() override;
		void ImGuiRender() override;
	private:
		glm::vec4 m_ClearColor;
	};
}
