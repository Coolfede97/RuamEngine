#pragma once

#include "Component.h"
#include "Vec3.h"
#include "nlohmann/json.hpp"

namespace RuamEngine
{
    class Rigidbody : public Component
    {

    public:
        glm::vec3 m_velocity;
        float m_mass;
        bool m_useGravity;
        bool m_isKinematic;
        float m_gravityForce;
        std::vector<FieldInfo> fields() override
		{
		    return
      		{
                makeFieldInfo<float>("m_gravityForce", m_gravityForce)
      		};
		}
        Rigidbody(unsigned int entityId);
        Rigidbody(nlohmann::json rigidbodyData, const unsigned int entityId);
        ~Rigidbody();

        DECL_REGISTER_COMPONENT(Rigidbody)
    };
}
