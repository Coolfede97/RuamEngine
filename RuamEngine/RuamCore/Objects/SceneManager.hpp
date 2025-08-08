#pragma once

#include "Scene.hpp"

class SceneManager {
public:
    using SceneList = std::vector<Scene>;

	static const SceneList& sceneList();
	static std::weak_ptr<Scene> activeScene();

	static void setActiveScene(Scene& scene);

	static void addScene(Scene& scene);

private:
	static SceneList s_scenes;
	static std::shared_ptr<Scene> s_active_scene;
};
