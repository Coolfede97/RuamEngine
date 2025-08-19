#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"
#include "../components/Counter.h"

std::shared_ptr<Scene> CreateTestScene()
{
	Scene testScene("Test Scene");
	Object& manager = testScene.newObject();
	manager.addComponent<Counter>();
	manager.addComponent<Manager>();
	return std::make_shared<Scene>(testScene);
}