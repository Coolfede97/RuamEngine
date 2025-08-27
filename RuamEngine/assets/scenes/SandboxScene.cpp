#include "Object.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "../components/Manager.h"
#include "../components/Counter.h"
#include "../components/SandboxCom.h"

SceneManager::ScenePtr CreateSandboxScene()
{
	Scene testScene("Sandbox Scene");
	Object& manager = testScene.newObject();
	manager.addComponent<SandboxCom>();
	manager.addComponent<Manager>();
	return std::make_unique<Scene>(testScene);
}
