#pragma once

#include "Component.h"
#include "Vec3.h"

namespace RuamEngine
{
    class BoxCollider : public Component
    {
        using Component::Component;

    public:
        BoxCollider(unsigned int entityId);
        ~BoxCollider();

        Vec3 m_center;
        float m_halfSize;
    };
}
