#include "DrawingData.h"

namespace RuamEngine
{

	void DrawingData::SubmitBatchData()
	{
		std::cout << "SubmitBatchData called\n";
		if (m_vertexBuffer->GetCurrentSize() > 0)
		{
			m_vertexBuffer->SubmitData();
		}
		if (m_indexBuffer->GetCurrentSize() > 0)
		{
			m_indexBuffer->SubmitData();
		}
		m_vertexArray->AddBuffer(*m_vertexBuffer, *m_layout);
	}

	void DrawingData::AddBatchData(const std::vector<Vertex> vertices, unsigned int vertexDataSize, const std::vector<unsigned int> indices, unsigned int indexDataSize)
	{
		std::cout << "AddBatchData called\n";
		if (m_vertexBuffer->GetCurrentSize() + vertexDataSize > m_vertexBuffer->GetMaxSize() 
			||
			m_indexBuffer->GetCurrentSize() + indexDataSize > m_indexBuffer->GetMaxSize())
			Renderer::EndBatch(*this);

		m_vertexBuffer->AddBatchData(vertices, vertexDataSize);
		m_indexBuffer->AddBatchData(indices, indexDataSize);
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


