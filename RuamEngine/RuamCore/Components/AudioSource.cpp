#include "AudioSource.h"

AudioSource::AudioSource(const unsigned int object_id, const std::string& audio) 
	: m_audio_path(audio), Component(object_id) {

}

void AudioSource::start() {
	try {
		m_source.generate();
	} catch (AudioSystem::AL::al_error e) {
		std::cerr << "Error generating source, " << e.what() << '\n';
	}

	glm::vec3 zero(0, 0, 0);

	try {
		m_source.setParam(AL_PITCH, 1);
		m_source.setParam(AL_GAIN, 1);
		m_source.setParam(AL_POSITION, zero);
		m_source.setParam(AL_VELOCITY, zero);
		m_source.setParam(AL_LOOPING, AL_FALSE);
	} catch (AudioSystem::AL::al_error e) {
		std::cerr << "Error setting source parameters, " << e.what() << '\n';
	}


	try {
		m_buffer.generate();
	} catch (AudioSystem::AL::al_error e) {
		std::cerr << "Error generating buffer, " << e.what() << '\n';
	}

	load(m_audio_path);

	m_source.bind(m_buffer);

	play();
}

const AudioSystem::AL::Source& AudioSource::source() const {
	return m_source;
}

void AudioSource::load(const std::string& path) {
	m_audio_path = path;
	Wave wave(m_audio_path.c_str(), true);

	try {
		m_buffer.setData(wave.openal_fmt(), reinterpret_cast<char*>(wave.data()), wave.size(), wave.rate());
	} catch (AudioSystem::AL::al_error e) {
		std::cerr << "Error setting data, " << e.what() << '\n';
		std::cerr << "Wave:\n";
		std::cerr << "FMT: " << wave.openal_fmt() << '\n';
		std::cerr << "Size: " << wave.size() << '\n';
		std::cerr << "rate: " << wave.rate() << '\n';
	}
}

void AudioSource::play() {
	m_source.play();
}

void AudioSource::pause() {
	m_source.pause();
}

void AudioSource::stop() {
	m_source.stop();
}

void AudioSource::update() {
//	m_source.setParam(AL_POSITION, object()->transform().position()); FIX: NOT working
}

int AudioSource::status() {
	return m_source.state();
}

/*
int main(int argc, char* argv[]) {
	int res;

	Wave wave(argv[1], false);

	ALC::Device dev(nullptr);

	ALC::Context ctx(dev, nullptr);

	ALC::MakeContextCurrent(ctx);

	glm::vec3 listPos = {0, 0, 0};

	AL::Listener::setParam(AL_POSITION, listPos);
	AL::Listener::setParam(AL_VELOCITY, listPos);

	AL::Source source;
	source.generate();

	glm::vec3 sourcePos = {0, 0, 0};
	glm::vec3 sourceVel = {0, 0, 0};

	source.setParam(AL_PITCH, 1);
	source.setParam(AL_GAIN, 1);
	source.setParam(AL_POSITION, sourcePos);
	source.setParam(AL_VELOCITY, sourceVel);
	source.setParam(AL_LOOPING, AL_FALSE);

	AL::Buffer buf;
	buf.generate();
	res = buf.setData(wave.openal_fmt(), reinterpret_cast<char*>(wave.data()), wave.size(), wave.rate());
	if (res != 0) {
		std::cerr << "ERROR: COULD NOT SET DATA ";
		fprintf(stderr, "0x%x\n", res);
	}

	source.bind(buf);

	source.play();

	double i = 0;
	while (source.state() == AL_PLAYING) {
		i += 0.000001;
		sourceVel.x = std::sin(i/10);
		sourceVel.y = std::tan(i/10);
		sourceVel.z = std::cos(i/10);
		source.setParam(AL_POSITION, sourceVel);
	}
	std::cout << "Clearing\n";

	source.destroy();
	buf.destroy();
	ctx.destroy();
	dev.close();
}
*/
