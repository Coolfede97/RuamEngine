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

}

template<class Comp>
void to_json(json& j, Comp comp) {

}

void Serial::serialise(sm::ScenePtr s) {
    json j = s;
}