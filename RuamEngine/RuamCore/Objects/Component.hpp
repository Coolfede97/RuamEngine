#pragma once

class Component {
public:
	Component(unsigned int obj_id) : m_object_id(obj_id) {};
    virtual void start() = 0;
    virtual void update() = 0;
protected:
    unsigned int m_object_id;
};

class BaseRenderer : public Component {
public:
	using Component::Component;

	virtual void render() = 0;

	void start() {};

	void update() {
		render();
	}
};
