#pragma once

#include <list>
#include <vector>
#include <memory>
#include <iterator>

#include <string>

#include "Object.hpp"

class Scene {
public:
    using SceneList = std::vector<Scene>;

    Scene();
    Scene(const char* name);

	const unsigned int id() const;
	const std::string& name() const;

    Object& newObject();
    Object& newObject(unsigned int idx);

    Object& getObjectByIdx(unsigned int idx) const;
    Object& getObjectById(unsigned int id) const;

    void deleteObjectByIdx(unsigned int idx);
    void deleteObjectById(unsigned int idx);

	void start();
	void update();
private:
    std::list<std::shared_ptr<Object>> m_objects;
	const std::string m_name;
    const unsigned int m_id;
    static unsigned int s_id_count;

	static const std::string s_default_name;
};
