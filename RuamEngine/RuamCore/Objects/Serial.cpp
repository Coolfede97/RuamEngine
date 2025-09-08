#include "Serial.hpp"
#include <fstream>

void to_json(json& j, const sm::ScenePtr s) {

    json serialisedObjects = json::array();
    json o;
    for (const auto& obj : s->getObjects()) {
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

void to_json(json& j, const Scene::ObjectPtr o) {

	json serialisedComponents = json::array();

    j = json{
        {"id", o->id()},
        {"name", o->name()},
		{"components", serialisedComponents}
	};
}

void from_json(const json& j, sm::ScenePtr s) {
    std::cout << "hola";
}

void Serial::serialise(sm::ScenePtr s) {
    json j = std::move(s);
}

sm::ScenePtr Serial::deserialise(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
	int id = j["id"];
	const std::string name = j["name"];
    sm::AddScene(0, [id, name]() -> sm::ScenePtr { //send help
        Scene s(id, name);
        sm::ScenePtr scene = std::make_unique<Scene>(s); 
        return std::move(scene); 
    });
	sm::SetActiveScene(0);
	sm::ScenePtr scene = sm::ActiveScene();
    scene = j;
	return scene;
}
