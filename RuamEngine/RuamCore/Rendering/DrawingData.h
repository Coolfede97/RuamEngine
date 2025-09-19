#pragma once
#include "RenderingCore.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "DrawingData.h"
#include "Shader.h"
#include "Renderer.h"

namespace RuamEngine
{
    // Data for current drawing
    class DrawingData
    {
    public:

        DrawingData();

        ShaderPtr m_shader = nullptr;
        VertexArrayPtr m_vertexArray = nullptr;
        VertexBufferPtr m_vertexBuffer = nullptr;
        VertexBufferLayoutPtr m_layout = nullptr;
        IndexBufferPtr m_indexBuffer = nullptr;
        //std::array<uint32_t, maxTextureSlots> textureSlots = {};

        // Which texture slot we can insert our new texture into
        //uint32_t textureSlotIndex = 1;

        void SubmitBatchData();
        bool AddBatchData(const std::vector<Vertex> vertices, unsigned int vertexDataSize, const std::vector<unsigned int> indices, unsigned int indexDataSize);
		void Flush();
    };
}
