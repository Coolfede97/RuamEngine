#include "Sandbox.h"

#include "Renderer.h"
#include "imgui.h"

namespace test
{

	Sandbox::Sandbox()
	{
		Start();
	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::Start()
	{
		auto quad = Vertex::CreateQuad(0.0f, 0.0f, 0.0f);
		Vertex vertices[4];
		memcpy(vertices, quad.data(), sizeof(Vertex) * 4);
		std::cout << vertices[0].position << "\n";
	}

	void Sandbox::Update()
	{

	}

	void Sandbox::Render()
	{
		
	}

	void Sandbox::ImGuiRender()
	{
	}

}