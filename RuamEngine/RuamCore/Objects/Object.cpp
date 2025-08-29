#include "Object.hpp"

unsigned int Object::s_id_count = 0;
const std::string Object::s_default_name = "Object";

unsigned int Object::id() const {
	return m_id;
}

const std::string& Object::name() const {
	return m_name;
}

void Object::setName(std::string& name) {
	m_name = name;
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

void Object::destroy() {
	for (auto& comp_v : m_components) {
		for (auto& comp : comp_v.second) {
			delete &(*comp);
			comp.reset();
		}
		comp_v.second.clear();
	}
}
