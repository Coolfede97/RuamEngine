#include "alc-wrapper.h"
#include <stdexcept>

namespace ALC {
Device::Device(const char* device_name) {
	m_device = alcOpenDevice(device_name);
	if (getError()) {
		throw std::runtime_error("Could not open device");
	}
}

Device::Device(std::nullptr_t) {
	m_device = alcOpenDevice(nullptr);
	if (getError()) {
		throw std::runtime_error("Could not open device");
	}
}

ALCdevice* Device::device() const {
	return m_device;
}

ALCerror Device::getError() {
	return alcGetError(m_device);
}

bool Device::close() {
	return alcCloseDevice(m_device);
}

Device::~Device() {
	close();
}

Context::Context(const Device& dev, ALCint* attr_list) {
	m_context = alcCreateContext(dev.device(), attr_list);
}

void Context::destroy() {
	if (alcGetCurrentContext() == m_context)
		MakeContextCurrent(nullptr);
	alcDestroyContext(m_context);
}

Context::~Context() {
	destroy();
}

ALCcontext* Context::context() const {
	return m_context;
}

Device Context::getDevice() const {
	return alcGetContextsDevice(m_context);
}

void GetDevices(std::vector<std::string>& devices);

bool MakeContextCurrent(Context& ctx) {
	return alcMakeContextCurrent(ctx.context());
}

bool MakeContextCurrent(std::nullptr_t) {
	return alcMakeContextCurrent(nullptr);
}

}
