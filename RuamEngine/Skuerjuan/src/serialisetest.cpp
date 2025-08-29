#include "SceneManager.hpp"

class TestComponent : public Component {
public:
	using Component::Component;
	void start() {
		std::cout << "TestComponent started on object " << std::endl;
	}
	void update() {
		//
	}
};

SceneManager::ScenePtr SceneA() {
	SceneManager::ScenePtr s = std::make_shared<Scene>("SceneA");

	return s;
}

void createA() {
	int s = SceneManager::AddScene(1, SceneA);
	SceneManager::SetActiveScene(s);
	SceneManager::ScenePtr scene = SceneManager::ActiveScene();

	Object& obj = scene->newObject();
	obj.addComponent<TestComponent>();

	scene->serialise("anashe.txt");

	scene->start();
	while (true) {
		scene->update();
}