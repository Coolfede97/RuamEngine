#include "Serial.hpp"

void to_json(json& j, const sm::ScenePtr& s) {

    std::vector<json> serialisedObjects;
    for (const auto& obj : s->getObjects()) {
		// Serialize each object and add it to the vector
    }

    j = json{
		{"id", s->id()},
        {"name", s->name()},
        {"objects", serialisedObjects}
    };
}

void to_json(json& j, const Scene::ObjectPtr o) {


    j = json{
        {"id", o->id()},
        {"name", o->name()}
	};
}

void from_json(const json& j, sm::ScenePtr& s) {

}

template<class Comp>
void to_json(json& j, Comp comp ) {

}
