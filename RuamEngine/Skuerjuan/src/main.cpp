#include "Serial.hpp"

using sm = SceneManager;

void createA() {

}

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

void main_serial() {
	Scene s("SceneA");
	int id = SceneManager::AddScene(&s);
	SceneManager::SetActiveScene(id);

	Scene* scene = sm::ActiveScene();
	Object* o = scene->newObject();
	std::string name = "My Object";
	o->setName(name);
	Object* o2 = scene->newObject();
	name = "Hola";
	o2->setName(name);
	Serial::serialise(scene);
}

int main() {
	auto s = Serial::deserialise("SceneA.json");
	s->getObjectById(0)->addComponent<TestComponent>();
	s->start();
	sm::RemoveScene(s->id());
}