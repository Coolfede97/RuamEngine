#pragma once

#include "RenderingCore.h"

namespace RuamEngine
{
	class IndexBuffer
	{
	private:
		unsigned int m_RendererID;
		unsigned int m_maxSize = 0;
		unsigned int m_currentSize = 0;
		unsigned int m_usage = GL_STATIC_DRAW;
		std::vector<unsigned int> m_indexData = {};

	public:
		IndexBuffer(unsigned int maxCount, unsigned int usage);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;
		void AddBatchData(const std::vector<unsigned int> data, unsigned int size);
		void SetSubData(const unsigned int* data, unsigned int offset, unsigned int size);
		void SetData(const unsigned int* data);

		// Puts the data from m_indexData into the actual buffer
		void SubmitData();
	
		void Flush();
		unsigned int GetIndexCount() const { return m_currentSize/sizeof(unsigned int); }
		unsigned int GetCurrentSize() const { return m_currentSize; }
		unsigned int GetMaxSize() const { return m_maxSize; }
	};

	using IndexBufferPtr = std::shared_ptr<IndexBuffer>;
}
