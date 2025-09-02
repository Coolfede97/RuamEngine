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

// Después hacer que si la data supera la capacidad del Buffer (por más que esté vacío), se actualice el buffer y que tire advertencia
void VertexBuffer::AddBatchData(const void* data, unsigned int size)
{
    if (m_size + size <= maxVertexSize * maxVertexCount) Renderer::EndBatch();

    Bind();
	SetSubData(data, m_size, size);
	m_size += size;
}

void VertexBuffer::SetSubData(const void* data, unsigned int offset, unsigned int size)
{
    ASSERT(offset + size <= maxVertexSize * maxVertexCount);

    Bind();

    GLCall(glBufferSubData(GL_ARRAY_BUFFER, offset, size, data));
}

void VertexBuffer::SetData(const void* data, unsigned int size, GLenum usage)
{
    Renderer::m_trianglesData.m_layout->Reset(); // Probablemente debería cambiarlo en el futuro
    Bind();
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, usage));
}

void VertexBuffer::Flush()
{
    m_size = 0;
	SetSubData(nullptr, 0, 0);
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
