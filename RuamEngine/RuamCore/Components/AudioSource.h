#pragma once

#include "AudioSystem.hpp"
#include "Object.hpp"

class AudioSource : public Component {
public:
	using Component::Component;

    void start();
    void update();

	void setAudioPath(const std::string& path);
	int status();

protected:
	AudioSystem::AL::Source m_source;
	AudioSystem::AL::Buffer m_buffer;
	std::string m_audio_path;
};
