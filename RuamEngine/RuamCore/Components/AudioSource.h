#pragma once

#include "AudioSystem.hpp"
#include "Object.hpp"

class AudioSource : public Component {
public:
	using Component::Component;

	AudioSource(const unsigned int obj_id, const std::string& audio_path);

    void start();
    void update();

	void setAudioPath(const std::string& path);
	int status();

	void load(const std::string& path, bool play = false);

	const AudioSystem::AL::Source& source() const;

	void play();
	void pause();
	void stop();
protected:
	void loadBuffer(std::unique_ptr<Wave>& wave, bool play = false);

	AudioSystem::AL::Source m_source;
	AudioSystem::AL::Buffer m_buffer;
	std::string m_audio_path;

	bool m_buffer_ready = false;

	std::unique_ptr<Wave> m_wave;
};
