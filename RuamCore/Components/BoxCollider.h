#pragma once

#include "Component.h"
#include "SSBO.h"
#include "Vec3.h"
#include "Vertex.h"
#include "RenderingConstants.h"

namespace RuamEngine
{
    class BoxCollider : public Component
    {
        using Component::Component;

    public:
        BoxCollider(unsigned int entityId);
        BoxCollider(nlohmann::json boxColliderData, const unsigned int entityId);
        ~BoxCollider();

        glm::vec3 m_center;
        glm::vec3 m_halfSize;

        std::vector<FieldInfo> fields() override
        {
            return
            {
                makeFieldInfo<glm::vec3>("m_center", m_center),
                makeFieldInfo<glm::vec3>("m_halfSize", m_halfSize)
            };
        }

        DECL_REGISTER_COMPONENT(BoxCollider);
    };
}
