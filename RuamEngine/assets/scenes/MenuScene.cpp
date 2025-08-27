#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"
#include "../components/Counter.h"

SceneManager::ScenePtr CreateMenuScene()
{
	Scene menuScene("Menu Scene");
	Object& manager = menuScene.newObject();
	manager.addComponent<Manager>();
	manager.addComponent<Counter>();
	return std::make_unique<Scene>(menuScene);
}

