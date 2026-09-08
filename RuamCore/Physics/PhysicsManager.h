#pragma once

#include "Rigidbody.h"
#include "BoxCollider.h"

#include <vector>

namespace RuamEngine
{
    class PhysicsManager
    {
        static std::vector<Rigidbody*> s_rigidbodies;
        static std::vector<BoxCollider*> s_boxColliders;

    public:
        static void AddRigidbody(Rigidbody* rb);
        static void AddBoxCollider(BoxCollider* box);

        static void RemoveRigidbody(Rigidbody* rb);
        static void RemoveBoxCollider(BoxCollider* box);

        static void Update();
    };
}
