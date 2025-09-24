#pragma once

#include "RenderingCore.h"
#include "Vertex.h"

namespace RuamEngine
{	
	class VertexBuffer
	{
	private:
		unsigned int m_RendererID;
		unsigned int m_maxSize = 0;
		unsigned int m_currentSize = 0;
		unsigned int m_usage = GL_STATIC_DRAW;
	public:
		std::vector<Vertex> m_vertexData = {};

		VertexBuffer(unsigned int maxSize, unsigned int usage);
		~VertexBuffer();

		// Should be used for buffers from the renderer batch
		void AddBatchData(const std::vector<Vertex> data, unsigned int size);

		// Shouldn't be used when using batch rendering
		void SetSubData(const void* data, unsigned int offset, unsigned int size);
	
		// Shouldn't be used when using batch rendering
		void SetData(const void* data);
	
		// Puts the data from m_vertexData into the actual buffer
		void SubmitData();

		void Flush();

		void Bind() const; 
		void Unbind() const;
		unsigned int GetID() const { return m_RendererID; }
		unsigned int GetCurrentSize() const { return m_currentSize; }
		unsigned int GetMaxSize() const { return m_maxSize; }

	};

	using VertexBufferPtr = std::shared_ptr<VertexBuffer>;
}

