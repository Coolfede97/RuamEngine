#include "Transform.h"

Transform::Transform(const unsigned int obj_id) : Component(obj_id), m_position(0, 0, 0) {}

Transform::Transform(const unsigned int obj_id, glm::vec3 pos) : Component(obj_id), m_position(pos) {}

void start() {};
void update() {};

void Transform::setPosition(glm::vec3 new_pos) {
	m_position = new_pos;
}

void Transform::setPosition(float x, float y, float z) {
	m_position = glm::vec3(x, y, z);
}

glm::vec3& Transform::position() {
	return m_position;
}
