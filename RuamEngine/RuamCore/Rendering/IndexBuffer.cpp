#include "Renderer.h"
#include "IndexBuffer.h"

using namespace RuamEngine;

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));
    GLCall(glGenBuffers(1, &m_RendererID));
    if (data) m_currentSize = count * sizeof(unsigned int);
	SetData(data, count * sizeof(unsigned int), GL_STATIC_DRAW);
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

void IndexBuffer::AddBatchData(const unsigned int* data, unsigned int size)
{
    
    if (m_currentSize + size > m_maxSize) Renderer::EndBatch();

    SetSubData(data, m_currentSize, size);
    m_currentSize += size;
}


// This function does not change the m_indexCount or m_size variables!
// You probably want to avoid using this function directly
void IndexBuffer::SetSubData(const unsigned int* data, unsigned int offset, unsigned int size)
{
    ASSERT(offset + size <= maxIndexCount * sizeof(unsigned int));

    Bind();

	GLCall(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, data));
}

// This function does not change the m_indexCount or m_size variables!
// You probably want to avoid using this function directly
void IndexBuffer::SetData(const unsigned int* data, unsigned int size, GLenum usage)
{
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage));
    m_maxSize = size;
}


void IndexBuffer::Flush()
{
    SetData(0, m_maxSize, GL_DYNAMIC_DRAW);
    m_currentSize = 0;
    //SetSubData(nullptr, 0, m_maxSize);
}