#include "al-wrapper.hpp"
#include "alc-wrapper.hpp"

#include "Wave.hpp"
#include <iostream>
#include <cstdio>
#include "glm/glm.hpp"

int main(int argc, char* argv[]) {
	int res;

	Wave wave(argv[1]);

	ALC::Device dev(nullptr);

	ALC::Context ctx(dev, nullptr);

	ALC::MakeContextCurrent(ctx);

	alListener3f(AL_POSITION, 0, 0, 0);
	alListener3f(AL_VELOCITY, 0, 0, 0);

	AL::Source source;
	source.generate();

	glm::vec3 sourcePos = {0, 0, 0};
	glm::vec3 sourceVel = {-2, 0, 0};

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
		i += 0.0001;
		std::cout << "Playing\n";
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
