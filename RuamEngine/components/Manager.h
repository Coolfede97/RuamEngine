#pragma once

#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "imgui.h"

class Manager : public Component
{
	public:
	Manager(unsigned int obj_id) : Component(obj_id) {}
	void start() override { /* implementaci�n */ }
	void update() override { /* implementaci�n */ }
	void imGuiRender() override {}
};