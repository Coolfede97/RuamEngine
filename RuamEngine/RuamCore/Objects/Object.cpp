#include "Object.hpp"

unsigned int Object::s_id_count = 0;

Object::Object() : m_id(s_id_count++), m_name("Cool Object") {}

unsigned int Object::getId() const {
	return m_id;
}

const Object::ComponentList& Object::getComponents() {
	return m_components;
}

void Object::start() {
	for (auto& it : m_components) {
		for (auto& cmp : it.second) {
			cmp->start();
		}
	}
}

void Object::update() {
	for (auto& it : m_components) {
		for (auto& cmp : it.second) {
			cmp->update();
		}
	}
}

void Object::imGuiRender()
{
	for (auto& it : m_components) {
		for (auto& cmp : it.second) {
			cmp->imGuiRender();
		}
	}
}
