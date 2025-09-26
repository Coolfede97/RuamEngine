#include "TestComponent.hpp"

using sm = SceneManager;

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
	auto c = o->addComponent<TestComponent>().get();
	c->setSecret(42);
	Serial::serialise(scene);
}

int main() {
	main_serial();
}