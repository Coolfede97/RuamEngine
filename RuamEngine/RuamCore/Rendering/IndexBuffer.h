#pragma once

#include "RenderingCore.h"

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_indexCount;
	unsigned int m_size;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	void AddBatchData(unsigned int* data, unsigned int size);
	void SetData(unsigned int* data, unsigned int size, GLenum usage);
	void SetSubData(unsigned int* data, unsigned int offset, unsigned int size);
	void Flush();
	unsigned int GetIndexCount() const { return m_indexCount; }
	unsigned int GetSize() const { return m_size; }
};

using IndexBufferPtr = std::shared_ptr<IndexBuffer>;
