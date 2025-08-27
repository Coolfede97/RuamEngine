#include "SceneManager.hpp"

SceneManager::SceneList SceneManager::s_scenes;
SceneManager::ScenePtr SceneManager::s_active_scene = nullptr;

const SceneManager::SceneList& SceneManager::sceneList() {
	return s_scenes;
}

void SceneManager::setActiveScene(unsigned int id) {
	s_active_scene = s_scenes[id]();
	s_active_scene->start();
}

unsigned int SceneManager::addScene(unsigned int id, SceneCreator scene) {
	s_scenes.insert({id, scene});
	return id;
}

SceneManager::ScenePtr SceneManager::emptyScene() {
	return std::make_unique<Scene>();
}

/* Active scene interface */

bool SceneManager::nullScene() {
	return s_active_scene == nullptr;
}

/* calls active scene's start */
void SceneManager::start() {
	s_active_scene->start();
}

/* Updates active scene */
void SceneManager::update() {
	s_active_scene->update();
}

const unsigned int SceneManager::id() {
	return s_active_scene->id();
}

const std::string& SceneManager::name() {
	return s_active_scene->name();
}

Object& SceneManager::newObject() {
	return s_active_scene->newObject();
}
Object& SceneManager::newObject(unsigned int idx) {
	return s_active_scene->newObject(idx);
}

Object& SceneManager::getObjectByIdx(unsigned int idx) {
	return s_active_scene->getObjectByIdx(idx);
}

Object& SceneManager::getObjectById(unsigned int id) {
	return s_active_scene->getObjectById(id);
}

void SceneManager::deleteObjectByIdx(unsigned int idx) {
	s_active_scene->deleteObjectByIdx(idx);
}

void SceneManager::deleteObjectById(unsigned int id) {
	s_active_scene->deleteObjectById(id);
}
