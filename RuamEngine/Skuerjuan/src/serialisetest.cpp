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

int main() {
	Scene s;
	SceneManager::addScene(s);
	SceneManager::setActiveScene(s);
	Object obj = s.newObject();
	
	obj.addComponent<TestComponent>();
	std::cout << "wawa" << std::endl;
	SceneManager::activeScene().lock()->start();
	while(true) {
		SceneManager::activeScene().lock()->update();
	}
}