#include "wave.hpp"
#include "DebugUtils.h"

#include <iostream>

namespace WAVE {
void readWave(WaveInfo& wi, const std::string& filename) {
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
			return; // FIX: Read sub format ffs
		}
	}

	file.close();
	// FIX: Add proper assertion

}

WaveInfo::~WaveInfo() {
}

}

