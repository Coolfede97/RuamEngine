#include "Manager.h"

#include <iostream>

void Manager::imGuiRender()
{
	std::cout << "Hola" << "\n";
	for (Scene& scene : SceneManager::sceneList())
	{
		if (ImGui::Button(scene.getName()))
		{
			SceneManager::setActiveScene(scene);
		}
	}
}
