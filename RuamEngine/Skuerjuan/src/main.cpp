#include "serialise.hpp"

using sm = SceneManager;

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

void serial() {
	createA();
	SceneManager::ScenePtr scene = SceneManager::ActiveScene();
	Object& obj = scene->newObject();
	obj.addComponent<TestComponent>();

	scene->serialise("anashe.txt");
}

int main() {

	Scene scene = Scene::deserialise("anashe.txt");

	scene.start();
	while (true) {
		scene.update();
	}
}