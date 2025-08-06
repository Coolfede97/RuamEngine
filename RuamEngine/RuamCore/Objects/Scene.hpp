#pragma once

#include <list>

class Scene {
public:
    Scene() : m_id(s_id_count++) {
    }
private:
    std::list<unsigned int> m_objects;
    unsigned int m_id;
    static unsigned int s_id_count;
};
