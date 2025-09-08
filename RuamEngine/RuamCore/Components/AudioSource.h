#pragma once

#include "AudioSystem.hpp"
#include "Object.hpp"

class AudioSource : public Component {
public:
	using Component::Component;

    void start();
    void update();

protected:
	AL::Source m_source;
	AL::Buffer m_buffer;
	std::string m_audio_path;
};
