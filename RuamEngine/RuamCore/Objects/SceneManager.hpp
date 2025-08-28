#pragma once

#include "Scene.hpp"
#include <unordered_map>

class SceneManager {
public:
	using ScenePtr = std::shared_ptr<Scene>;
	using SceneCreator = ScenePtr (*)();
    using SceneList = std::unordered_map<unsigned int, SceneCreator>;

	SceneManager() = delete;

	static const SceneList& sceneList();

	static void SetActiveScene(unsigned int id);
	static ScenePtr ActiveScene();

	/* Returns idx */
	static unsigned int AddScene(unsigned int id, SceneCreator scene);

	static ScenePtr EmptyScene();

	template<char* Name, class Comp>
	ScenePtr SceneCreate() {
		ScenePtr scene = std::make_shared<Scene>(Name);
		scene->newObject().addComponent<Comp>();
	}

private:
	static SceneList s_scenes;
	static ScenePtr s_active_scene;
};
