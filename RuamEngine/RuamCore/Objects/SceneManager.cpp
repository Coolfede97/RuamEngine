#include "SceneManager.hpp"

SceneManager::SceneList SceneManager::s_scenes;
Scene* SceneManager::s_active_scene = nullptr;

const SceneManager::SceneList& SceneManager::sceneList() {
	return s_scenes;
}

void SceneManager::SetActiveScene(const unsigned int id) {
	s_active_scene = s_scenes[id];
}

Scene* SceneManager::ActiveScene() {
	return s_active_scene;
}

unsigned int SceneManager::AddScene(Scene* scene) {
		s_scenes.push_back(scene);
	return s_scenes.size()-1;
}

Scene* SceneManager::CreateScene(const unsigned int id, const std::string& name) {
	Scene *s = new Scene(id, name);
	AddScene(s);
	return s;
}

void SceneManager::RemoveScene(const int id) {
	s_scenes.erase(s_scenes.begin() + id);
}

SceneManager::ScenePtr SceneManager::EmptyScene() {
	return std::move(std::make_unique<Scene>());
}
