#include "Serial.hpp"
#include <fstream>

void to_json(json& j, Scene* s) {
    std::cout << "Serialising scene " << s->name() << std::endl;
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
    std::string filename = s->name() + ".json";
    std::cout << "Writing to " << filename << std::endl;
    std::ofstream file(filename);
    std::cout << j.dump(4) << std::endl;
    file << j.dump(4);
}

Scene* Serial::deserialise(const std::string &filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
    int id = j["id"];
    const std::string name = j["name"];
    Scene *s = sm::CreateScene(id, name);
    sm::SetActiveScene(id);

    for (const auto& obj : j["objects"]) {
        Object *o = s->newObject(obj["id"]);
        std::string objName = obj["name"];
        o->setName(objName);
    }
	return sm::ActiveScene();
}