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
            rb->transform()->translate(0, -9.8 * RuamTime::DeltaTime() * rb->m_gravityForce, 0);
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
