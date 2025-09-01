#include "Serial.hpp"

void to_json(json& j, const sm::ScenePtr& s) {
	j = json{
		{"name", s->name()},
		{"objects", s->objects}
	};
}