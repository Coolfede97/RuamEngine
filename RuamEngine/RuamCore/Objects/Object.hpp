#pragma once

#include <vector>
#include <memory>
#include <map>
#include <typeindex>

#include "Component.hpp"
#include <string>

class Object {
public:
	Object() : m_id(s_id_count++), m_name(s_default_name) {}
	Object(std::string& name) : m_id(s_id_count++), m_name(name) {}

	using ComponentVector = std::vector<std::shared_ptr<Component>>;
	using ComponentList = std::map<std::type_index, ComponentVector>;

	template<class Comp>
	std::shared_ptr<Comp> addComponent() {
		std::shared_ptr<Comp> comp = std::make_shared<Comp>(m_id);
		const std::type_index tidx = typeid(Comp);
		if (m_components.count(tidx) > 0) {
			m_components[tidx].push_back(comp);
		} else {
			m_components.insert({tidx, ComponentVector()});
			m_components[tidx].push_back(comp);
		}
		return comp;
	}

	// Returns ptr because a ref can't be null
	// Returned pointer is non-owning
	// TODO: Find if there's a better way
	template<class Comp>
	Comp* getComponent() const {
		auto pair = m_components.find(typeid(Comp));
		if (pair == m_components.end()) {
			return nullptr;
		}
		if (pair->second.size() == 0) {
			return nullptr;
		}
		return dynamic_cast<Comp*>(pair->second.front().get());
	}

	template<class Comp>
	void removeComponent() {
		auto pair = m_components.find(typeid(Comp));
		if (pair == m_components.end()) return;
		if (pair->second.size() == 0) return;
		pair->second.pop_back();
	}

	unsigned int id() const;
	const std::string& name() const;
	void setName(std::string& newstr); 
	const ComponentList& getComponents() const;

	bool operator==(const Object& obj) {
		return this->m_id == obj.m_id;
	}

	void start();
	void update();

	void destroy();

private:
	unsigned int m_id;
	static unsigned int s_id_count;
    std::string m_name;

	ComponentList m_components;

	static const std::string s_default_name;
};
