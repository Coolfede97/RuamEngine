#pragma once

#include "Test.h"

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
	};
}