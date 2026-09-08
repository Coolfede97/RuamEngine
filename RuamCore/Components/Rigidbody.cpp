#include "Rigidbody.h"
#include "Component.h"
#include "PhysicsManager.h"
#include "Entity.h"
#include "JsonConverters.h"

namespace RuamEngine
{
    Rigidbody::Rigidbody(unsigned int entityId) : Component(entityId),
    m_velocity(0,0,0), m_mass(1), m_isKinematic(false), m_useGravity(true), m_gravity(0, -1, 0)
    {
        PhysicsManager::AddRigidbody(this);
    }
    Rigidbody::Rigidbody(nlohmann::json rigidbodyData, const unsigned int entityId) : Component(entityId),
    m_velocity(0,0,0), m_mass(1), m_isKinematic(false), m_useGravity(true), m_gravity(0, -1, 0)
    {
        if (rigidbodyData.contains("m_velocity")) m_velocity = rigidbodyData["m_velocity"].get<glm::vec3>();
        if (rigidbodyData.contains("m_mass")) m_mass = rigidbodyData["m_mass"].get<float>();
        if (rigidbodyData.contains("m_isKinematic")) m_isKinematic = rigidbodyData["m_isKinematic"].get<bool>();
        if (rigidbodyData.contains("m_useGravity")) m_useGravity = rigidbodyData["m_useGravity"].get<bool>();
        if (rigidbodyData.contains("m_gravity")) m_gravity = rigidbodyData["m_gravity"].get<glm::vec3>();
    }
    Rigidbody::~Rigidbody()
    {
        PhysicsManager::RemoveRigidbody(this);
    }
    DEF_REGISTER_COMPONENT(Rigidbody);
}
