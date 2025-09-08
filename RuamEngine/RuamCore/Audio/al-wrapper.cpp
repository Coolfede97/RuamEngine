#include "al-wrapper.hpp"
#include <iostream>

namespace AL {
using ALerror = ALenum;

ALerror Source::generate() {
	alGenSources(1, &m_id);
	return GetError();
}

ALerror Source::setParam(ALenum param, ALfloat v) {
	alSourcef(m_id, param, v);
	return GetError();
}

ALerror Source::setParam(ALenum param, glm::vec3& v) {
	alSource3f(m_id, param, v.x, v.y, v.z);
	return GetError();
}

ALerror Source::setParam(ALenum param, ALint v) {
	alSourcei(m_id, param, v);
	return GetError();
}

ALuint Source::id() const {
	return m_id;
}

ALerror Source::bind(const Buffer& buf) {
	return setParam(AL_BUFFER, static_cast<int>(buf.id()));
}

ALerror Source::bind(ALuint buf) {
	return setParam(AL_BUFFER, static_cast<int>(buf));
}

ALerror Source::play() {
	alSourcePlay(m_id);
	return GetError();
}

void Source::destroy() {
	alDeleteSources(1, &m_id);
}

Source::~Source() {
	destroy();
}

ALerror Source::get(ALenum param, ALint* out) {
	alGetSourcei(m_id, param, out);
	return GetError();
}

ALint Source::state() {
	int res;
	if ((res = get(AL_SOURCE_STATE, &m_state)) != 0) {
		// TODO: Add exception
	}
	return m_state;
}

//

ALerror GetError() {
	return alGetError();
}

ALerror Buffer::generate() {
	alGenBuffers(1, &m_id);
	return GetError();
}

ALuint Buffer::id() const {
	return m_id;
}

ALerror Buffer::setData(ALenum format, char* data, ALsizei size, ALuint freq) {
	alBufferData(m_id, format, data, size, freq);
	return GetError();
}

ALerror Buffer::setData(ALenum format, std::vector<char> data, ALuint freq) {
	alBufferData(m_id, format, data.data(), static_cast<ALsizei>(data.size()), freq);
	return GetError();
}

Buffer::~Buffer() {
	destroy();
}

void Buffer::destroy() {
	alDeleteBuffers(1, &m_id);
}

namespace Listener {
ALerror setParam(ALenum param, ALfloat v) {
	alListenerf(param, v);
	return GetError();
}

ALerror setParam(ALenum param, glm::vec3& v) {
	alListener3f(param, v.x, v.y, v.z);
	return GetError();
}

ALerror setParam(ALenum param, ALint v) {
	alListeneri(param, v);
	return GetError();
}
}

}
