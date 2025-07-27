#include "Test.h"

namespace test
{

	TestMenu::TestMenu(Test*& currentTestPointer)
		: m_CurrentTest(currentTestPointer)
	{

	}

	TestMenu::~TestMenu()
	{

	}

	void TestMenu::ImGuiRender()
	{
		for (auto& test : m_Tests)
		{
			if (ImGui::Button(test.first.c_str()))
			{
				m_CurrentTest = test.second();
			}
		}
	}

}