#pragma once

#include <vector>
#include <memory>
#include <map>
#include <typeindex>

#include "Component.hpp"

class Object {
public:
    Object() : m_id(s_id_count++) {}
    using ComponentVector = std::vector<std::shared_ptr<Component>>;

    template<class Comp>
    Comp& addComponent() {
        Comp comp = new Comp;
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
        return dynamic_cast<Comp*>(pair->second[0].get());
    }

private:
    unsigned int m_id;
    static unsigned int s_id_count;

    std::map<std::type_index, ComponentVector> m_components;
};
