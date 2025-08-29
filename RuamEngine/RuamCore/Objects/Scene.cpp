#include "Scene.hpp"
#include <fstream>

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
    m_objects.erase(std::next(m_objects.cbegin(), idx));
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

void Scene::serialise(char* filename) const {
	std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
	}

    file.write(reinterpret_cast<const char*>(this),
        sizeof(*this));
	std::cout << "Scene written to " << filename << std::endl;
	file.close();
}

Scene Scene::deserialise(char* filename) {
	Scene s;
	std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return s;
    }
    file.read(reinterpret_cast<char*>(&s),
		sizeof(s));
	file.close();
	return s;
}
