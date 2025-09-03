#pragma once

#include <cstdint>
#include <type_traits>
#include <algorithm>
#include <iostream>
#include <vector>

#include "glm/glm.hpp"
#include "AL/al.h"

namespace AL {
using ALerror = ALenum;

class Buffer;

class Source {
public:
	~Source();

	ALerror generate();
	
	ALerror setParam(ALenum param, ALfloat v);
	ALerror setParam(ALenum param, glm::vec3& v);
	ALerror setParam(ALenum param, ALint v);

	ALerror bind(const Buffer& buf);
	ALerror bind(ALuint buf);

	ALerror get(ALenum param, ALint* out);

	ALerror play();

	ALint state();

	void destroy();

	ALuint id() const;
private:
	ALuint m_id;
	ALint m_state;
};

class Buffer {
public:
	~Buffer();
	ALerror generate();
	ALerror setData(ALenum format, char* data, ALsizei size, ALuint freq);
	ALerror setData(ALenum format, std::vector<char> data, ALuint freq);

	void destroy();

	ALuint id() const;


private:
	ALuint m_id;
};

ALerror GetError();

}
