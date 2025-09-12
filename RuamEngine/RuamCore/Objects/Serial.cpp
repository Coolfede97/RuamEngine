#include "Serial.hpp"
#include <fstream>

void to_json(json& j, Scene* s) {

    json serialisedObjects = json::array();
    json o;
    for (Object* obj : s->getObjects()) {
        o = obj;
		serialisedObjects.push_back(o);
    }

    j = json{
		{"id", s->id()},
        {"name", s->name()},
        {"objects", serialisedObjects}
    };

	std::string filename = s->name() + ".json";
	std::ofstream file(filename);
	file << j.dump(4);
}

void to_json(json& j, Object* o) {

	json serialisedComponents = json::array();

    j = json{
        {"id", o->id()},
        {"name", o->name()},
		{"components", serialisedComponents}
	};
}

void from_json(const json& j, Scene* s) {
    std::cout << "hola";
}

void Serial::serialise(Scene* s) {
    json j = s;
}

Scene* Serial::deserialise(const std::string &filename) {
	return nullptr;
}

// sm::ScenePtr Serial::deserialise(const std::string& filename) {
//     std::ifstream file(filename);
//     json j;
//     file >> j;
// 	int id = j["id"];
// 	const std::string name = j["name"];
//     sm::AddScene(0, [id, name]() -> sm::ScenePtr { //send help
//         Scene s(id, name);
//         sm::ScenePtr scene = std::make_unique<Scene>(s);
//         return std::move(scene);
//     });
// 	sm::SetActiveScene(0);
// 	sm::ScenePtr scene = sm::ActiveScene();
//     scene = j;
// 	return scene;
// }
