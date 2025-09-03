#pragma once

#include <list>
#include <vector>
#include <memory>
#include <iterator>

#include <string>
#include <iostream>

#include "Object.hpp"

class Scene {
public:
    using SceneList = std::vector<Scene>;
    using ObjectPtr = std::shared_ptr<Object>;
    using ObjectPtrList = std::list<ObjectPtr>;

    Scene();
    Scene(const char* name);

	const unsigned int id() const;
	const std::string& name() const;

    ObjectPtr newObject(); //Maybe should need a name?
    ObjectPtr newObject(unsigned int idx);

    Object& getObjectByIdx(unsigned int idx) const; //FIX: return ObjectPtr
    Object& getObjectById(unsigned int id) const;

	ObjectPtrList& getObjects() const { return const_cast<ObjectPtrList&>(m_objects); }

    void deleteObjectByIdx(unsigned int idx);
    void deleteObjectById(unsigned int idx);

    std::string name() { return m_name; }

	void start();
	void update();

private:
    ObjectPtrList m_objects;
	const std::string m_name;
    const unsigned int m_id;
    static unsigned int s_id_count;

	static const std::string s_default_name;
};
