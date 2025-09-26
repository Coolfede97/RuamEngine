#include "AudioSystem.hpp"

namespace AudioSystem {
static ALC::Device s_dev;
static ALC::Context s_ctx;

void init() {
	s_dev.open(nullptr);
	s_ctx.create(s_dev);
	ALC::MakeContextCurrent(s_ctx);
}

void init(const char* device) {
	s_dev.open(device);
	s_ctx.create(s_dev);
	ALC::MakeContextCurrent(s_ctx);
}

ALC::Device device();
void shutdown() {
	ALC::MakeContextCurrent(nullptr);
	s_ctx.destroy();
	s_dev.close();
}

ALC::Device device() {
	return s_dev;
}

ALC::Context context() {
	return s_ctx;
}
} 
