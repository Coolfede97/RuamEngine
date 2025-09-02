#include "DrawingData.h"

void RuamEngine::DrawingData::Flush()
{
	m_vertexBuffer->Flush();
	m_indexBuffer->Flush();
}

RuamEngine::DrawingData::DrawingData()
{
}


