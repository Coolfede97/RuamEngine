#include "DrawingData.h"

namespace RuamEngine
{
	void DrawingData::Flush()
	{
		std::cout << "Flushing DrawingData <-|-|-|-|-|-\n";
		m_vertexBuffer->Flush();
		m_indexBuffer->Flush();
	}

	DrawingData::DrawingData()
	{
	}

}


