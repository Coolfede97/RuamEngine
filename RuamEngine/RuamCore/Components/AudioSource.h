#pragma once

#include "Object.hpp"
#include "Wave.hpp"

class AudioSource : public Component {
public:
	using Component::Component;

    void start();
    void update();

protected:
	AL::Source source;
	AL::Buffer buffer;
};
