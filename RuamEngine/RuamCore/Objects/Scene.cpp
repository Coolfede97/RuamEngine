#include "Scene.hpp"

unsigned int Scene::s_id_count = 0;

Scene::Scene() : m_id(s_id_count++) {}

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
    while (obj->get()->getId() != id) {
        std::advance(obj, 1);
    }
    return *obj->get();
}

void Scene::deleteObjectByIdx(unsigned int idx) {
    m_objects.erase(std::next(m_objects.cbegin(), idx));
}

void Scene::Start() {
	for (auto& obj : m_objects) {
		obj->start();
	}
}

void Scene::Update() {
	for (auto& obj : m_objects) {
		obj->start();
	}
}

void Scene::Render() {
    for (auto& obj : m_objects) {
        obj->render();
    }
}

void Scene::ImGuiRender() {
    for (auto& obj : m_objects) {
        obj->imguiRender();
    }
}
