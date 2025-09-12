#pragma once

#include "Scene.hpp"
#include <unordered_map>

class SceneManager {
public:
	using ScenePtr = std::unique_ptr<Scene>;
    using SceneList = std::vector<Scene*>;

	SceneManager() = delete;

	static const SceneList& sceneList();

	static void SetActiveScene(unsigned int id);
	static Scene* ActiveScene();

	/* Returns idx */
	static unsigned int AddScene(Scene* scene);

	static ScenePtr EmptyScene();

private:
	static SceneList s_scenes;
	static Scene* s_active_scene;
};
