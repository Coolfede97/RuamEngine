#pragma once

#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "imgui.h"

#include <iostream>

class Manager : public BaseRenderer {
public:
	using BaseRenderer::BaseRenderer;
	Manager(unsigned int obj_id) : BaseRenderer(obj_id) {};
	void render() {
		for (const Scene& scene : SceneManager::sceneList()) 
		{
			if (ImGui::Button(scene.name().c_str()))
			{
				SceneManager::setActiveScene(const_cast<Scene&>(scene));
			}
		}
	};
};


