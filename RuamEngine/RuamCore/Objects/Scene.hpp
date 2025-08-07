#pragma once

#include <list>
#include <vector>
#include <memory>
#include <iterator>

#include "Object.hpp"
#include "Component.hpp"

class Scene {
public:
    using SceneList = std::vector<Scene>;

    Scene();
    ~Scene();
    const SceneList& getScenes() const;
    // Non-owning reference
    const Scene* getActiveScene() const;

    Object& newObject();
    Object& newObject(unsigned int idx);

    Object& getObjectByIdx(unsigned int idx) const;
    Object& getObjectById(unsigned int id) const;

    void deleteObjectByIdx(unsigned int idx);
    void deleteObjectById(unsigned int idx);


private:
    std::list<std::shared_ptr<Object>> m_objects;
    unsigned int m_id;

    static unsigned int s_id_count;
    static SceneList s_scenes;
    static std::shared_ptr<Scene> s_active_scene;
};
