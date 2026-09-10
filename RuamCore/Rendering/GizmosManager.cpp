#include "GizmosManager.h"
#include "RenderingConstants.h"
#include "Vertex.h"
#include "VertexArray.h"

namespace RuamEngine
{
    SSBOUPtr<GizmoVertex> GizmosManager::s_colliderVertices = std::make_unique<SSBO<GizmoVertex>>(baseVertexCount, GL_DYNAMIC_STORAGE_BIT);
    SSBOUPtr<unsigned int> GizmosManager::s_colliderIndices = std::make_unique<SSBO<unsigned int>>(baseIndexCount, GL_DYNAMIC_STORAGE_BIT);
    VertexArrayUPtr GizmosManager::s_vertexArray = std::make_unique<VertexArray>();
    glm::vec4 GizmosManager::s_drawColor = glm::vec4(0, 1, 0, 1);
}
