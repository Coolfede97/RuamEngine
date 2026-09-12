#include "BoxCollider.h"
#include "Component.h"
#include "GizmosManager.h"
#include "PhysicsManager.h"
#include "Entity.h"
#include "Transform.h"

namespace RuamEngine
{
    BoxCollider::BoxCollider(unsigned int entityId) : Component(entityId), m_center(0,0,0), m_halfSize(0.5, 0.5, 0.5)
    {
        PhysicsManager::AddBoxCollider(this);
    }
    BoxCollider::BoxCollider(nlohmann::json boxColliderData, const unsigned int entityId) : Component(entityId),
    m_center(0, 0, 0), m_halfSize(0.5, 0.5, 0.5)
    {
        if (boxColliderData.contains("m_center")) m_center = boxColliderData["m_center"].get<glm::vec3>();
        if (boxColliderData.contains("m_halfSize")) m_halfSize = boxColliderData["m_halfSize"].get<glm::vec3>();
    }

    BoxCollider::~BoxCollider()
    {
        PhysicsManager::RemoveBoxCollider(this);
    }

    void BoxCollider::renderUpdate()
    {
        m_vertices.clear();
        glm::vec3 boxCenter = transform()->position() + m_center;
        glm::vec3 boxScale = transform()->scale();
        glm::vec3 halfX = glm::vec3(m_halfSize.x * boxScale.x, 0, 0);
        glm::vec3 halfY = glm::vec3(0, m_halfSize.y * boxScale.y, 0);
        glm::vec3 halfZ = glm::vec3(0, 0, m_halfSize.z * boxScale.z);

        m_vertices.push_back({boxCenter - m_halfSize});
        m_vertices.push_back({boxCenter + halfX - halfY - halfZ});
        m_vertices.push_back({boxCenter + halfX - halfY + halfZ});
        m_vertices.push_back({boxCenter - halfX - halfY + halfZ});
        m_vertices.push_back({boxCenter - halfX + halfY - halfZ});
        m_vertices.push_back({boxCenter + halfX + halfY - halfZ});
        m_vertices.push_back({boxCenter + m_halfSize});
        m_vertices.push_back({boxCenter - halfX + halfY + halfZ});

        GizmosManager::PushColliderGizmo(m_vertices, m_indices);
    }

    DEF_REGISTER_COMPONENT(BoxCollider);
}
