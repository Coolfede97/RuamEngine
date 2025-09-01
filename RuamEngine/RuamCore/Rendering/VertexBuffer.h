#pragma once

#include "RenderingCore.h"

class VertexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_size;
public:

	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	// Should be used for buffers from the renderer batch
	void AddBatchData(const void* data, unsigned int size);

	// Shouldn't be used when using batch rendering
	void SetSubData(const void* data, unsigned int offset, unsigned int size);
	
	// Shouldn't be used when using batch rendering
	void SetData(const void* data, unsigned int size, GLenum usage);

	void Bind() const; 
	void Unbind() const;
	unsigned int GetID() const { return m_RendererID; }
	unsigned int GetSize() const { return m_size; }
};

using VertexBufferPtr = std::shared_ptr<VertexBuffer>;
