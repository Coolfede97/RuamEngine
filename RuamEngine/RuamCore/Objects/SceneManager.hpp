#pragma once

#include "Scene.hpp"
#include <unordered_map>

class SceneManager {
public:
	using ScenePtr = std::unique_ptr<Scene>;
	using SceneCreator = ScenePtr (*)();
	using SceneList = std::unordered_map<unsigned int, SceneCreator>;

	SceneManager() = delete;

	static const SceneList& sceneList();

	static void setActiveScene(unsigned int id);

	/* Returns idx */
	static unsigned int addScene(unsigned int id, SceneCreator scene);

	static ScenePtr emptyScene();

	/* Active scene interface */

	static bool nullScene();

	/* calls active scene's start */
	static void start();

	/* Updates active scene */
	static void update();

	static const unsigned int id();
	static const std::string& name();

    static Object& newObject();
    static Object& newObject(unsigned int idx);

    static Object& getObjectByIdx(unsigned int idx);
    static Object& getObjectById(unsigned int id);

    static void deleteObjectByIdx(unsigned int idx);
    static void deleteObjectById(unsigned int id);

private:
	static SceneList s_scenes;
	static ScenePtr s_active_scene;
};
