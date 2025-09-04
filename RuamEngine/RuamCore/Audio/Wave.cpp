#include "Wave.hpp"
#include <stdexcept>

Wave::Wave(const char* filename) {
	unsigned long long frames;
	m_data = drwav_open_file_and_read_pcm_frames_s16(filename, &m_channels, &m_sample_rate, &m_total_samples, nullptr);
}

Wave::Wave(const std::string& filename) : Wave(filename.c_str()) {};
Wave::~Wave() {
	drwav_uninit(&m_wav);
	drwav_free(m_data, nullptr);
}

drwav_uint64 Wave::size() const {
	return m_total_samples * m_channels * sizeof (int16_t);
}

int16_t* Wave::data() {
	return m_data;
}

uint32_t Wave::rate() const {
	return m_sample_rate;
}

uint32_t Wave::channels() const {
	return m_channels;
}

ALenum Wave::openal_fmt() const {
	return AL_FORMAT_STEREO16; // always interpeted as 16-bit
}

format_error::format_error(char const* const msg) throw() : std::runtime_error(msg) {}

char const* format_error::what() const throw() {
	return std::exception::what();
}
