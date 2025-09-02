#include "wave.hpp"
#include "DebugUtils.h"

using namespace WAVE;
#include <iostream>

WaveInfo::~WaveInfo() {
	delete[] wave_chunks;
}

void WAVE::readWave(WaveInfo& wi, const std::string& filename) {
	std::ifstream file(filename);
	file.read(reinterpret_cast<char*>(&wi.ckid), 4);
	file.read(reinterpret_cast<char*>(&wi.cksize), 4);
	file.read(reinterpret_cast<char*>(&wi.waveid), 4);
	file.close();
	// FIX: Add proper assertion
	ASSERT(wi.ckid == WaveInfo::riff_magic);
	ASSERT(wi.waveid == WaveInfo::wave_magic);
}
