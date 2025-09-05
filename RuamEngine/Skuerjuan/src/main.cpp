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
	sm::ScenePtr scene = Serial::deserialise("sceneA.json");
	return 0;
}