#pragma once

class Component {
public:
    Component(unsigned int obj_id) : m_object_id(obj_id) {};
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void imguiRender() = 0;
protected:
    unsigned int m_object_id;
};
