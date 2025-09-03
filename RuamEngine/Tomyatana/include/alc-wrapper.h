#pragma once

#include "AL/alc.h"
#include <string>
#include <cstdint>
#include <vector>
#include "DebugUtils.h"

#define ALCcall(dev, x) do {alcGetError(dev); x; ASSERT(alcGetError(dev) == ALC_NO_ERROR)} while(false)

namespace ALC {

using ALCerror = uint16_t;

class Device {
public:
	Device(const char* device_name);
	Device(std::nullptr_t);
	Device(ALCdevice* dev) : m_device(dev) {};
	~Device();
	ALCdevice* device() const;
	ALCerror getError();
	bool close();

private:
	ALCdevice* m_device;
};

class Context {
public:
	Context(const Device& dev, ALCint* attr_list);
	~Context();
	
	void destroy();
	ALCcontext* context() const;
	Device getDevice() const;
private:
	ALCcontext* m_context;
};

void GetDevices(std::vector<std::string>& devices);
bool MakeContextCurrent(Context& ctx);
bool MakeContextCurrent(std::nullptr_t);

}
