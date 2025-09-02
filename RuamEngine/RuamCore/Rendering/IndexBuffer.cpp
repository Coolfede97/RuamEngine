#include "Renderer.h"
#include "IndexBuffer.h"

using namespace RuamEngine;

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

// Problema que arreglar. Si se llama a EndBatch cuando se llega al límite del espacio del IndexBuffer
// y todavía no se puso la información en el Buffer, se va a intentar dibujar con la posible información
// faltante

void IndexBuffer::AddBatchData(unsigned int* data, unsigned int indexCount)
{
    if (m_indexCount + indexCount <= maxIndexCount) Renderer::EndBatch();

    Bind();
    SetSubData(data, m_indexCount, indexCount);
    m_indexCount += indexCount;
}

void IndexBuffer::SetData(unsigned int* data, unsigned int count, GLenum usage)
{
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, usage));
}

void IndexBuffer::SetSubData(unsigned int* data, unsigned int offset, unsigned int size)
{
    ASSERT(offset + size <= maxIndexCount * sizeof(unsigned int));

    Bind();

    GLCall(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, data));
}

void IndexBuffer::Flush()
{
    m_indexCount = 0;
    SetSubData(nullptr, 0, 0);
}