#pragma once

#include <fstream>
#include <cstdint>

/*
* Everithing from (this spec)[https://mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html]
*/
namespace WAVE {

struct Chunk {
	uint32_t ckid;
	uint32_t cksize;
};

enum class Format {
	PCM		= 0x0001,
	Float	= 0x0003,
	ALaw	= 0x0006,
	MuLaw	= 0x0007,
	Ext		= 0x0007,
};

struct FmtExtension {
	uint16_t wValidBitsPerSample;
	uint32_t dwChannelMask;
	// TODO: Finish implementing SubFormat
};

struct WaveInfo : Chunk {
	uint32_t waveid;
	
	static const uint32_t riff_magic = 0x46464952; // Reversed because LE
	static const uint32_t wave_magic = 0x45564157; // Reversed because LE
	
	~WaveInfo();
};

struct Fmt : Chunk {
	Format wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
	uint16_t cbSize;
	// TODO: Finish implementing FmtExtension

	static const uint32_t fmt_magic = 0x20746d66;
};

struct Fact : Chunk {
	static const uint32_t fact_magic = ;
};

void readWave(WaveInfo& wi, const std::string& filename);


}
