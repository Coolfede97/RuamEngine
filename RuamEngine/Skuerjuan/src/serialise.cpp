#include "serialise.hpp"

SceneManager::ScenePtr SceneA() {
	SceneManager::ScenePtr s = std::make_shared<Scene>("SceneA");

	return s;
}

void createA() {
	int s = SceneManager::AddScene(1, SceneA);
	SceneManager::SetActiveScene(s);
}