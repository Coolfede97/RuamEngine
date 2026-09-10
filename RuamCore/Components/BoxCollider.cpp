#include "BoxCollider.h"
#include "Component.h"
#include "PhysicsManager.h"
#include "Entity.h"

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
    DEF_REGISTER_COMPONENT(BoxCollider);
}
