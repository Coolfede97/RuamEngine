#include "BoxCollider.h"
#include "PhysicsManager.h"

namespace RuamEngine
{
    BoxCollider::BoxCollider(unsigned int entityId) : Component(entityId), m_center(0,0,0), m_halfSize(0.5)
    {
        PhysicsManager::AddBoxCollider(this);
    }
    BoxCollider::~BoxCollider()
    {
        PhysicsManager::RemoveBoxCollider(this);
    }
}
