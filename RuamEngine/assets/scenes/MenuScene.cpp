#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"
#include "../components/Counter.h"

std::shared_ptr<Scene> CreateMenuScene()
{
	Scene menuScene("Menu Scene");
	Object& manager = menuScene.newObject();
	manager.addComponent<Manager>();
	manager.addComponent<Counter>();
	return std::make_shared<Scene>(menuScene);
}

