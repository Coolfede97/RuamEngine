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
	SceneManager::ScenePtr s = std::make_shared<Scene>("Sample Scene");
	//Object& obj = s->newObject();
	Object& obj = s->newObject();
	
	obj.addComponent<TestComponent>();
	return s;
}

int main() {
	int s = SceneManager::AddScene(1, SampleScene);
	SceneManager::SetActiveScene(s);
	std::cout << "wawa\n";
	SceneManager::ActiveScene()->start();
	while(true) {
		SceneManager::ActiveScene()->update();
	}
}
