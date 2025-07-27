#pragma once

#include <functional>
#include <imgui.h>
#include <string>

namespace test
{
	class Test
	{
	public:
		Test() {}
		virtual ~Test() {}

		virtual void Start() {}
		virtual void Update() {}
		virtual void Render() {}
		virtual void ImGuiRender() {}
	};

	class TestMenu : public Test
	{
	public:
		TestMenu(Test*& currentTestPointer);
		~TestMenu();

		void ImGuiRender() override;

		template<typename T>
		void RegisterTest(const std::string& name)
		{
			std::cout << "Registering test: " << name << "\n";
			m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
		}
	private:
		Test*& m_CurrentTest;
		std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;

	};
}