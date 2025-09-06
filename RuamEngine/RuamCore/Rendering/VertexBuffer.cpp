#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

using namespace RuamEngine;

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &m_RendererID));
	if (data) m_currentSize = size;
	SetData(data, size, GL_DYNAMIC_DRAW);
}

VertexBuffer::~VertexBuffer() 
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

// Después hacer que si la data supera la capacidad del Buffer (por más que esté vacío), se actualice el buffer y que tire advertencia
void VertexBuffer::AddBatchData(const void* data, unsigned int size)
{
    if (m_currentSize + size > m_maxSize) Renderer::EndBatch();

    SetSubData(data, m_currentSize, size);
    m_currentSize += size;
}

void VertexBuffer::SetSubData(const void* data, unsigned int offset, unsigned int size)
{
    ASSERT(offset + size <= maxVertexSize * maxVertexCount);

    Bind();

    GLCall(glBufferSubData(GL_ARRAY_BUFFER, offset, size, data));
}

void VertexBuffer::SetData(const void* data, unsigned int size, GLenum usage)
{
    Renderer::m_basicDrawingData.m_layout->Reset(); // Probablemente debería cambiarlo en el futuro
    Bind();
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, usage));

	m_maxSize = size;
}

void VertexBuffer::Flush()
{
    SetData(nullptr, m_maxSize, GL_DYNAMIC_DRAW);
    m_currentSize = 0;
	//SetSubData(nullptr, 0, m_maxSize);
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
