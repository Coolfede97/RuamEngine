#pragma once

#include "Component.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "imgui.h"
#include "Manager.h"

#include <iostream>

class Counter : public Component {
public:
	int count = 0;
	using Component::Component;
	void start() {
		std::cout << "Inicio\n";
	}

	void update() {
		count++;
		std::cout << count << "\n";
		std::cout << object()->name() << "\n";
	}
};
