#pragma once

#include "Vertex.h"
#include "SSBO.h"
#include "VertexArray.h"

namespace RuamEngine
{
    class GizmosManager
    {
    public:
        static VertexArrayUPtr s_vertexArray;
        static SSBOUPtr<GizmoVertex> s_colliderVertices;
        static SSBOUPtr<unsigned int> s_colliderIndices;

        static glm::vec4 s_drawColor;
    };
}
