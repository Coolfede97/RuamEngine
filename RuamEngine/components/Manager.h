#pragma once

#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "imgui.h"

class Manager : public Component
{
	public:
	Manager(unsigned int obj_id) : Component(obj_id) {}
	void start() override { /* implementación */ }
	void update() override { /* implementación */ }
	void imGuiRender() override {}
};