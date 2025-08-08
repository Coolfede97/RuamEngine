#pragma once

#include <list>
#include <vector>
#include <memory>
#include <iterator>

#include "Object.hpp"

class Scene {
public:
    using SceneList = std::vector<Scene>;

    Scene();

    Object& newObject();
    Object& newObject(unsigned int idx);

    Object& getObjectByIdx(unsigned int idx) const;
    Object& getObjectById(unsigned int id) const;

    void deleteObjectByIdx(unsigned int idx);
    void deleteObjectById(unsigned int idx);

	void Start();
	void Update();

private:
    std::list<std::shared_ptr<Object>> m_objects;
    const unsigned int m_id;

    static unsigned int s_id_count;
};
