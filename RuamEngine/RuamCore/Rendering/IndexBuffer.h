#pragma once

#include "RenderingCore.h"

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_maxSize = 0;
	unsigned int m_currentSize = 0;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	void AddBatchData(const unsigned int* data, unsigned int size);
	void SetSubData(const unsigned int* data, unsigned int offset, unsigned int size);
	void SetData(const unsigned int* data, unsigned int size, GLenum usage);
	void Flush();
	unsigned int GetIndexCount() const { return m_currentSize/sizeof(unsigned int); }
	unsigned int GetCurrentSize() const { return m_currentSize; }
	unsigned int GetMaxSize() const { return m_maxSize; }
};

using IndexBufferPtr = std::shared_ptr<IndexBuffer>;
