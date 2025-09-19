#include "DrawingData.h"

namespace RuamEngine
{

	void DrawingData::SubmitBatchData()
	{
		if (m_vertexBuffer->GetCurrentSize() > 0)
		{
			m_vertexBuffer->SubmitData();
		}
		if (m_indexBuffer->GetCurrentSize() > 0)
		{
			m_indexBuffer->SubmitData();
		}
	}

	bool DrawingData::AddBatchData(const std::vector<Vertex> vertices, unsigned int vertexDataSize, const std::vector<unsigned int> indices, unsigned int indexDataSize)
	{
		bool fullBatch = false;
		ASSERT(vertexDataSize <= m_vertexBuffer->GetMaxSize() || indexDataSize <= m_indexBuffer->GetMaxSize());
		
		if (m_vertexBuffer->GetCurrentSize() + vertexDataSize > m_vertexBuffer->GetMaxSize()
			||
			m_indexBuffer->GetCurrentSize() + indexDataSize > m_indexBuffer->GetMaxSize())
		{
			SubmitBatchData();
			Renderer::Draw(*this);
			Flush();
			fullBatch = true;
		}
		//std::cout << vertices.size() << "\n";
		m_vertexBuffer->AddBatchData(vertices, vertexDataSize);
		m_indexBuffer->AddBatchData(indices, indexDataSize);
		return fullBatch;
	}

	void DrawingData::Flush()
	{
		m_vertexBuffer->Flush();
		m_indexBuffer->Flush();
	}

	DrawingData::DrawingData()
	{
	}

}


