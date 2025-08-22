#pragma once

#include "RendererCore.h"

class VertexBuffer
{
private:
	unsigned int m_RendererID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void SetData(unsigned int offset, const void* data);

	void Bind() const; 
	void Unbind() const;
	unsigned int GetID() const { return m_RendererID; }
};
