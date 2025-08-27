#include "Scene.hpp"

unsigned int Scene::s_id_count = 0;
const std::string Scene::s_default_name = "Sample Scene";

Scene::Scene() : m_id(s_id_count++), m_name(s_default_name) {}

Scene::Scene(const char* name) : m_id(s_id_count++), m_name(name) {}

const unsigned int Scene::id() const {
	return m_id;
}

const std::string& Scene::name() const {
	return m_name;
}

Object& Scene::newObject() {
    std::shared_ptr<Object> obj = std::make_shared<Object>();
    m_objects.push_back(obj);
    return *obj.get();
}

Object& Scene::newObject(unsigned int idx) {
    // Going to have to check this
    //assert(idx < m_objects.size());
    std::shared_ptr<Object> obj = std::make_shared<Object>();
    auto index = m_objects.cbegin();
    std::advance(index, idx);
    m_objects.insert(index, obj);
    return *obj.get();
}

Object& Scene::getObjectByIdx(unsigned int idx) const {
    auto iter = m_objects.begin();
    return *std::next(iter, idx)->get();
}

Object& Scene::getObjectById(unsigned int id) const {
    auto obj = m_objects.begin();
    while (obj->get()->id() != id) {
        std::advance(obj, 1);
    }
    return *obj->get();
}

void Scene::deleteObjectByIdx(unsigned int idx) {
    m_objects.erase(std::next(m_objects.begin(), idx));
}

void Scene::deleteObjectById(unsigned int id) {
	unsigned int i = 0;
	for (auto& obj : m_objects) {
		if (obj->id() == id) break;
		i++;
	}
	m_objects.erase(std::next(m_objects.begin(), i));
}

void Scene::start() {
	for (auto& obj : m_objects) {
		obj->start();
	}
}

void Scene::update() {
	for (auto& obj : m_objects) {
		obj->update();
	}
}
