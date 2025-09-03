#include "serialise.hpp"
#include "Serial.hpp"

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

int main() {
	createA();
	sm::ScenePtr scene = sm::ActiveScene();
	Scene::ObjectPtr o = scene->newObject();
	std::string name = "My Object";
	o->setName(name);
	Scene::ObjectPtr o2 = scene->newObject();
	name = "Hola";
	o2->setName(name);
	Serial::serialise(scene);
}