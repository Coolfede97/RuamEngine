#pragma once

#include "RendererCore.h"

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_indexCount;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	void SetData(unsigned int size, unsigned int* data, GLenum usage);
	void SetSubData(unsigned int offset, unsigned int size, unsigned int* data);
	unsigned int GetIndexCount() const { return m_indexCount; }
};

using IndexBufferPtr = std::shared_ptr<IndexBuffer>;
