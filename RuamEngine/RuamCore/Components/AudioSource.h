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

	void load(const std::string& path);

	const AudioSystem::AL::Source& source() const;

	void play();
	void pause();
	void stop();

	void setVolume(float vol);
	float volume();

protected:
	void loadBuffer(std::unique_ptr<Wave>& wave);

	AudioSystem::AL::Source m_source;
	AudioSystem::AL::Buffer m_buffer;
	std::string m_audio_path;
	std::unique_ptr<Wave> m_wave;
	float m_volume;

	std::atomic<bool> m_buffer_ready = false;
	std::condition_variable m_buf_wait;
	std::mutex m_mutex;
};
