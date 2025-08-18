#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"

static Scene CreateMenuScene()
{
	Scene scene;
	scene.setName("Menu Scene");
	Object& manager = scene.newObject();
	manager.m_name = "Manager";
	manager.addComponent<Manager>();
	return scene;
}