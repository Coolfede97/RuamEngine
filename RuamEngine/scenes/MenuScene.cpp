#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"

std::shared_ptr<Scene> CreateMenuScene()
{
	Scene menuScene("Menu Scene");
	Object& manager = menuScene.newObject();
	manager.addComponent<Manager>();
	return std::make_shared<Scene>(menuScene);
}

