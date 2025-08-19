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
		std::cout << "Hola" << "\n";
		for (const Scene& scene : SceneManager::sceneList()) 
		{
			if (ImGui::Button(scene.name().c_str()))
			{
				SceneManager::setActiveScene(const_cast<Scene&>(scene));
			}
		}
	};
};

class Counter : public Component {
public:
	using Component::Component;
	void start() {
		std::cout << "Inici\n";
	}

	void update() {
		std::cout << "hello\n";
	}
};
