#include "DrawingData.h"

namespace RuamEngine
}
	void DrawingData::Flush()
	{
		GLCall(glBufferData(GL_ARRAY_BUFFER, m_vertexBuffer->GetSize(), nullptr, GL_DYNAMIC_DRAW));
	}
{
