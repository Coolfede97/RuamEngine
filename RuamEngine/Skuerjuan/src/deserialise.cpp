#include "serialisetest.cpp"

int main() {
	Scene scene = Scene::deserialise("anashe.txt");
	scene.start();
	while (true) {
		scene.update();
	}
}