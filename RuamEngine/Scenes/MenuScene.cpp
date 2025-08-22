#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../assets/components/Manager.h"

std::shared_ptr<Scene> CreateMenuScene()
{
	SceneManager::ScenePtr menuScene = std::make_shared<Scene>("Menu Scene");
	Object& manager = menuScene->newObject();
	manager.addComponent<Manager>();
	return std::make_shared<Scene>(menuScene);
}
