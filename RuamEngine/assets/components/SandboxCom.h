#pragma once

#include <Component.hpp>
#include "Renderer.h"
#include "Vertex.h"
#include "VertexBuffer.h"
using namespace RuamEngine;

class SandboxCom : public BaseRenderer
{
	using BaseRenderer::BaseRenderer;
	
	// It's called in update
	void render()
	{
		
	};
	void start() 
	{
		auto quad = Vertex::CreateQuad(0, 0);
		Renderer::m_state.m_vertexBuffer->SetData(0, &quad);
	};
};