#pragma once

#include "AL/alc.h"
#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

#define alcCall(function, dev, ...) (alcCallImpl(__FILE__, __LINE__, function, dev, __VA_ARGS__))

namespace ALC {
inline bool check_alc_errors(const std::string& filename, const std::uint_fast32_t line, ALCdevice* dev) {
	ALCenum error = alcGetError(dev);
	if (error == ALC_NO_ERROR) return true;

	std::cerr << "** ERROR ** (" << filename << ": " << line << ")\n";
	switch (error) {
	case ALC_INVALID_DEVICE:
		std::cerr << "ALC_INVALID_DEVICE\n";
		break;
	case ALC_INVALID_ENUM:
		std::cerr << "ALC_INVALID_ENUM\n";
		break;
	case ALC_INVALID_VALUE:
		std::cerr << "ALC_INVALID_VALUE\n";
		break;
	case ALC_INVALID_CONTEXT:
		std::cerr << "ALC_INVALID_CONTEXT\n";
		break;
	case ALC_OUT_OF_MEMORY:
		std::cerr << "OOM NO HOPE\n";
		break;
	default:
		std::cerr << "UNKNOWN ALC ERROR\n";
	}
	return false;
}

template<typename alcFunction, typename... Params>
auto alcCallImpl(
	const char* filename,
	const std::uint_fast32_t line,
	alcFunction fn,
	ALCdevice* dev,
	Params... params
) -> typename std::enable_if<std::is_same_v<void, decltype(fn(params...))>, bool> {
	fn(std::forward<Params>(params)...);
	return check_alc_errors(filename, line, dev);
}

template<typename alcFunction, typename ReturnType, typename... Params>
auto alcCallImpl(
	const char* filename,
	const std::uint_fast32_t line,
	alcFunction fn,
	ReturnType& ret,
	ALCdevice* dev,
	Params... params
) -> typename std::enable_if<!std::is_same_v<void, decltype(fn(params...))>, bool> {
	ret = fn(std::forward<Params>(params)...);
	return check_alc_errors(filename, line, dev);
}

inline bool get_devices(std::vector<std::string>& dev_v, ALCdevice* dev) {
	const ALCchar* devs;
	if (!alcCall(alcGetString, devs, dev, nullptr, ALC_DEVICE_SPECIFIER)) {

	}
}

}
