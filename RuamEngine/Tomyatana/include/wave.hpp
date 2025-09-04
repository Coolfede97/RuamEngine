#pragma once

#include <cstdint>
#include <stdexcept>

#include "al-wrapper.h"

#include "dr_wav.h"

/*
* Everithing from (this spec)[https://mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html]
*/

class format_error : public std::runtime_error {
	format_error(char const* const msg) throw();
	char const* what() const throw();
};

class Wave {
public:
	Wave(const char* filename);
	Wave(const std::string& filename);
	~Wave();

	uint16_t openal_fmt() const;
	int16_t* data();
	drwav_uint64 size() const;
	uint32_t rate() const;
	uint32_t channels() const;

private:
	drwav m_wav;
	int16_t* m_data;
	uint32_t m_channels;
	uint32_t m_sample_rate;
	drwav_uint64 m_total_samples;
};
