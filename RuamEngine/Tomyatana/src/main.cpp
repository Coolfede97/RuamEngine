#include "al-wrapper.h"
#include "alc-wrapper.h"

#include "wave.hpp"
#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) {
	WAVE::WaveInfo wi;
	WAVE::readWave(wi, argv[1]);
	printf("ID: 0x%x\n", wi.ckid);
	printf("SIZE: 0x%x\n", wi.cksize);
	printf("WID: 0x%x\n", wi.waveid);
}
