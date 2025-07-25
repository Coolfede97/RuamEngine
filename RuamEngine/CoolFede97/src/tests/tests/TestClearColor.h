#pragma once

#include "Test.h"

namespace test
{
	class TestClearColor : public Test
	{
	public:
		TestClearColor();
		~TestClearColor();
		
		void Update() override;
		void Render() override;
		void ImGuiRender() override;
	private:
		float m_ClearColor[4];
	};
}