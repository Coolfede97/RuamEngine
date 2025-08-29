#pragma once

class Component {
public:
    Component(unsigned int obj_id) : m_object_id(obj_id), m_id(s_id_count++) {};
    virtual void start() = 0;
    virtual void update() = 0;
	bool operator==(const Component& other);
	unsigned int id();
protected:
    const unsigned int m_object_id;
	const unsigned int m_id;
	static unsigned int s_id_count;
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
