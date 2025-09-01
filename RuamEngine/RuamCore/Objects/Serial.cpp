#include "Serial.hpp"

void to_json(json& j, const sm::ScenePtr& s) {

    std::vector<json> serializedObjects;
    for (const auto& obj : s->getObjects()) {
		// Serialize each object and add it to the vector
    }

    j = json{
        {"name", s->name()},
        {"objects", serializedObjects}
    };
}