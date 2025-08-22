#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"
#include "../components/Counter.h"

SceneManager::ScenePtr CreateTestScene()
{
	SceneManager::ScenePtr testScene = std::make_shared<Scene>("Test Scene");
	Object& manager = testScene->newObject();
	manager.addComponent<Counter>();
	manager.addComponent<Manager>();
	return testScene;
}
