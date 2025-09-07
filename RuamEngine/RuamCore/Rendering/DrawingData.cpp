#include "DrawingData.h"

namespace RuamEngine
{
	void DrawingData::Flush()
	{
		m_vertexBuffer->Flush();
		m_indexBuffer->Flush();
	}

	DrawingData::DrawingData()
	{
	}

}


