#include "SceneManager.hpp"

SceneManager::SceneList SceneManager::s_scenes;
SceneManager::ScenePtr SceneManager::s_active_scene = nullptr;

const SceneManager::SceneList& SceneManager::sceneList() {
	return s_scenes;
}

void SceneManager::SetActiveScene(unsigned int id) {
	s_active_scene = s_scenes[id]();
	s_active_scene->start();
}

SceneManager::ScenePtr SceneManager::ActiveScene() {
	return s_active_scene;
}

unsigned int SceneManager::AddScene(unsigned int id, SceneCreator scene) {
	s_scenes.insert({id, scene});
	return id;
}

SceneManager::ScenePtr SceneManager::EmptyScene() {
	return std::make_shared<Scene>();
}
