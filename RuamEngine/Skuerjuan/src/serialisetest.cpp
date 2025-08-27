#include "../../RuamCore/Objects/SceneManager.hpp"
#include <iostream>

class TestComponent : public Component {
public:
	using Component::Component;
	void start() {
		std::cout << "TestComponent started on object " << std::endl;
	}
	void update() {
		std::cout << "TestComponent updated on object " << std::endl;
	}
};

SceneManager::ScenePtr SampleScene() {
	Scene s("Sample Scene");
	Object& obj = s.newObject();
	
	obj.addComponent<TestComponent>();
	return std::make_unique<Scene>(s);
}

int main() {
	int s = SceneManager::addScene(1, SampleScene);
	SceneManager::setActiveScene(s);
	std::cout << "wawa\n";
	SceneManager::start();
	while(true) {
		SceneManager::update();
	}
}
