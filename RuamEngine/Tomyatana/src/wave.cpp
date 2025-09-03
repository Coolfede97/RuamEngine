#include "wave.hpp"
#include "DebugUtils.h"

#include "al-wrapper.h"

#include <iostream>

namespace WAVE {
void readWave(WaveInfo& wi, const std::string& filename) {
	Chunk ck;

	std::ifstream file(filename);
	file.read(reinterpret_cast<char*>(&wi.ckid), 4);
	file.read(reinterpret_cast<char*>(&wi.cksize), 4);
	file.read(reinterpret_cast<char*>(&wi.waveid), 4);

	ASSERT(wi.ckid == WaveInfo::riff_magic);
	ASSERT(wi.waveid == WaveInfo::wave_magic);

	file.read(reinterpret_cast<char*>(&wi.format), Fmt::min_size + sizeof Fmt::cksize + sizeof Fmt::ckid);

	ASSERT(wi.format.ckid == Fmt::fmt_magic);
	ASSERT(wi.format.cksize > 0);
	ASSERT(wi.format.nChannels > 0);
	ASSERT(wi.format.nSamplesPerSec > 0);
	ASSERT(wi.format.nAvgBytesPerSec > 0);
	ASSERT(wi.format.nBlockAlign > 0);
	ASSERT(wi.format.wBitsPerSample > 0);

	if (wi.format.cksize - Fmt::min_size > 0) {
		file.read(reinterpret_cast<char*>(&wi.format.cbSize), 2);
		if (wi.format.cbSize > 0) {
			fprintf(stderr, "Extension currently unsupported\n");
			return; // FIX: Read sub format ffs
		}
	}

	if (wi.format.wFormatTag != Format::PCM) {
		fprintf(stderr, "Format %d currently unsupported\n", wi.format.wFormatTag);
		return;
	}

	file.read(reinterpret_cast<char*>(&ck), sizeof ck);
	if (ck.ckid == Fact::fact_magic) {
		wi.fact.cksize = ck.cksize;
		wi.fact.ckid = ck.ckid;
		file.read(reinterpret_cast<char*>(&wi.fact.dwSampleLength), sizeof wi.fact.dwSampleLength);
	}
	else if (ck.ckid == Data::data_magic) {
		wi.data.cksize = ck.cksize;
		wi.data.ckid = ck.ckid;
		wi.data.samples = std::vector<char>(wi.data.cksize);
		ASSERT(wi.data.samples.size() >= wi.data.cksize);
		fprintf(stderr, "SIZE: 0x%x\n", wi.data.cksize);
		file.read(wi.data.samples.data(), wi.data.cksize);
	} else {
		fprintf(stderr, "Unknown chunk: 0x%x\n", ck.ckid);
	}

	ASSERT(wi.data.ckid == Data::data_magic);
	ASSERT(wi.data.samples.size() > 0);

	file.close();
	// FIX: Add proper assertion

}

WaveInfo::~WaveInfo() {
}

uint32_t WaveInfo::to_al_format() const {
	bool stereo = format.nChannels > 1;

	switch (format.wBitsPerSample) {
	case 16:
		if (stereo)
			return AL_FORMAT_STEREO16;
		else
			return AL_FORMAT_MONO16;
	case 8:
		if (stereo)
			return AL_FORMAT_STEREO8;
		else
			return AL_FORMAT_MONO8;
	default:
		return -1;
	}
}

}

