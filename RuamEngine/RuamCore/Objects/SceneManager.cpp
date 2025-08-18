#include "SceneManager.hpp"

SceneManager::SceneList SceneManager::s_scenes;
std::shared_ptr<Scene> SceneManager::s_active_scene = std::shared_ptr<Scene>(nullptr);

const SceneManager::SceneList& SceneManager::sceneList() {
	return s_scenes;
}

std::shared_ptr<Scene> SceneManager::activeScene() {
	return s_active_scene;
}

void SceneManager::setActiveScene(Scene& scene) {
	s_active_scene.reset(&scene);
}

void SceneManager::addScene(Scene& scene) {
	s_scenes.push_back(scene);
}
