#include "Scene.hpp"

std::vector<Scene> Scene::s_scenes;
std::shared_ptr<Scene> Scene::s_active_scene = nullptr;
unsigned int Scene::s_id_count = 0;

Scene::Scene() : m_id(s_id_count++) {
    if (s_active_scene == nullptr) {
        s_active_scene.reset(this);
    }
}

Scene::~Scene() {
    if (s_active_scene->m_id == this->m_id) {
        s_active_scene.reset();
    }
}

const Scene::SceneList& Scene::getScenes() const {
    return s_scenes;
};
const Scene* Scene::getActiveScene() const {
    return s_active_scene.get();
}

Object& Scene::newObject() {
    std::shared_ptr<Object> obj = std::make_shared<Object>(new Object);
    m_objects.push_back(obj);
    return *obj.get();
}

Object& Scene::newObject(unsigned int idx) {
    // Going to have to check this
    //assert(idx < m_objects.size());
    std::shared_ptr<Object> obj = std::make_shared<Object>(new Object);
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
    Object& obj = getObjectByIdx(idx);
    m_objects.remove(obj);
}

void deleteObjectById(unsigned int idx) {

}
