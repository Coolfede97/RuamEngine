#pragma once

#include <Component.hpp>

class Manager : public BaseRenderer
{
	void update() override
	{
		BaseRenderer::update();
	}
	void render() 
	{
		for (const Scene& scene : SceneManager::sceneList())
		{
			if (ImGui::Button(scene.name().c_str()))
			{
				SceneManager::setActiveScene(const_cast<Scene&>(scene));
			}
		}
	};
	void start() {};
};