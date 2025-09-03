#pragma once

#include <fstream>
#include <cstdint>
#include <memory>
#include <vector>

/*
* Everithing from (this spec)[https://mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html]
*/
namespace WAVE {

struct Chunk {
	uint32_t ckid;
	uint32_t cksize;
};

enum class Format : uint16_t {
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


struct Fmt : Chunk {
	Format wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
	uint16_t cbSize;
	// TODO: Finish implementing FmtExtension

	static const uint32_t fmt_magic = 0x20746d66; // Reversed because LE
	static const uint32_t min_size = 16;
};

struct Fact : Chunk {
	uint32_t dwSampleLength;
	static const uint32_t fact_magic = 0x63746661; // Reversed because LE
};

struct Data : Chunk {
	std::vector<char> samples;
	static const uint32_t data_magic = 0x61746164; // Reversed because LE
};

struct WaveInfo : Chunk {
	uint32_t waveid;

	Fmt format;
	Fact fact;
	Data data;
	
	static const uint32_t riff_magic = 0x46464952; // Reversed because LE
	static const uint32_t wave_magic = 0x45564157; // Reversed because LE
	
	~WaveInfo();

	uint32_t to_al_format() const ;
};

void readWave(WaveInfo& wi, const std::string& filename);


}
