#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "RuamTime.h"
#include "Transform.h"
namespace RuamEngine
{
    std::vector<Rigidbody*> PhysicsManager::s_rigidbodies = {};
    std::vector<BoxCollider*> PhysicsManager::s_boxColliders = {};

    void PhysicsManager::Update()
    {
        for (Rigidbody* rb : s_rigidbodies)
        {
            if (!rb->m_isKinematic && rb->m_useGravity) rb->m_velocity += rb->m_gravity*RuamTime::DeltaTime();

            // Crazy stuff I need to do

            rb->transform()->translate(rb->m_velocity*RuamTime::DeltaTime());
        }
    }

    void PhysicsManager::AddRigidbody(Rigidbody* rb)
    {
        s_rigidbodies.push_back(rb);
    }
    void PhysicsManager::AddBoxCollider(BoxCollider* box)
    {
        s_boxColliders.push_back(box);
    }
    void PhysicsManager::RemoveRigidbody(Rigidbody* rb)
    {
        auto it = std::find(s_rigidbodies.begin(), s_rigidbodies.end(), rb);
        if (it != s_rigidbodies.end()) s_rigidbodies.erase(it);
    }
    void PhysicsManager::RemoveBoxCollider(BoxCollider* box)
    {
        auto it = std::find(s_boxColliders.begin(), s_boxColliders.end(), box);
        if (it != s_boxColliders.end()) s_boxColliders.erase(it);
    }
}
