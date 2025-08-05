#pragma once

#include <vector>
#include <memory>

#include "Component.hpp"

class Object {
public:
    using ComponentVector = std::vector<std::shared_ptr<Component>>;

    const ComponentVector& getComponents() const;

    template<class Comp>
    Comp& addComponent() {
        Comp comp = new Comp;
        m_components.push_back(comp);
        return comp;
    }

    template<class Comp>
    Comp& getComponent() {
        for (auto comp : m_components) {
            if (dynamic_cast<Comp>(*comp.get()) != nullptr) {

            }
        }
    }

private:
    unsigned int m_id;
    std::vector<std::shared_ptr<Component>> m_components;

    static unsigned int s_id_count;
};
