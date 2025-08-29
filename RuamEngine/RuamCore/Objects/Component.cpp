#include "Component.hpp"

unsigned int Component::s_id_count = 0;

bool Component::operator==(const Component& other) {
	return this->m_id == other.m_id;
}

unsigned int Component::id() {
	return m_id;
}
