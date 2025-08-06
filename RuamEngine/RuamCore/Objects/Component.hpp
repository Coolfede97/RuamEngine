#pragma once

class Component {
public:
    Component(unsigned int obj_id) : m_object_id(obj_id) {};
    virtual void Start() = 0;
    virtual void Update() = 0;
protected:
    unsigned int m_object_id;
};
