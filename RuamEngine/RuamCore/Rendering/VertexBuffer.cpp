#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

using namespace RuamEngine;

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() 
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::AddBatchData(const void* data, unsigned int size)
{
    if (m_size + size <= maxVertexSize * maxVertexCount) Renderer::EndBatch();

    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	SetSubData(data, m_size, size);
	m_size += size;
}

void VertexBuffer::SetSubData(const void* data, unsigned int offset, unsigned int size)
{
    ASSERT(offset + size <= maxVertexSize * maxVertexCount);

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));

    GLCall(glBufferSubData(GL_ARRAY_BUFFER, offset, size, data));
}

void VertexBuffer::SetData(const void* data, unsigned int size, GLenum usage)
{
    Renderer::m_state.m_layout->Reset();
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, usage));
}


void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
