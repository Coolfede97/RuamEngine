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
    using ObjectPtr = std::unique_ptr<Object>;
    using ObjectPtrList = std::list<ObjectPtr>;
    
    Scene() : m_id(s_id_count++), m_name(s_default_name) {}

    Scene(int id) : m_id(id), m_name(s_default_name) {}

    Scene(const std::string& name) : m_id(s_id_count++), m_name(name) {}

    Scene(int id, const std::string& name) : m_id(id), m_name(name) {}

	const unsigned int id() const;
	const std::string& name() const;

    ObjectPtr newObject(); //Maybe should need a name?
    ObjectPtr newObject(unsigned int idx);

    Object& getObjectByIdx(unsigned int idx) const; // FIX: return ObjectPtr
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
