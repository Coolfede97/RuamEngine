#pragma once

#include "SceneManager.hpp"
#include "Scene.hpp"  
#include "nlohmann/json.hpp"

using sm = SceneManager;

using json = nlohmann::json; 

void to_json(json& j, const sm::ScenePtr s);
void from_json(const json& j, sm::ScenePtr s);

void to_json(json& j, const Scene::ObjectPtr o);
void from_json(const json& j, Scene::ObjectPtr o);

class Serial {
	public:
		static void serialise(sm::ScenePtr s);
};