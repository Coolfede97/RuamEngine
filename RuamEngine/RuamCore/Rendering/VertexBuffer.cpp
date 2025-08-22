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

void VertexBuffer::SetData(unsigned int offset, const void* data)
{
    glBufferSubData(GL_ARRAY_BUFFER, offset, maxVertexCount * vertexSize * sizeof(float), data);
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
