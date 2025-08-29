#pragma once

#include "AL/al.h"
#include <cstdint>
#include <type_traits>
#include <algorithm>
#include <iostream>

#define alCall(function, ...) (alCallImpl(__FILE__, __LINE__, function, __VA_ARGS__))

namespace AL {
inline bool check_al_errors(const std::string& filename, const std::uint32_t line) {
	ALenum error = alGetError();
	if (error == AL_NO_ERROR) return true;

	std::cerr << "** ERROR ** (" << filename << ": " << line << ")\n";
	switch (error) {
	case AL_INVALID_NAME:
		std::cerr << "AL_INVALID_NAME\n";
		break;
	case AL_INVALID_ENUM:
		std::cerr << "AL_INVALID_ENUM\n";
		break;
	case AL_INVALID_VALUE:
		std::cerr << "AL_INVALID_VALUE\n";
		break;
	case AL_INVALID_OPERATION:
		std::cerr << "AL_INVALID_OPERATION\n";
		break;
	case AL_OUT_OF_MEMORY:
		std::cerr << "OOM NO HOPE\n";
		break;
	default:
		std::cerr << "UNKNOWN ERROR\n";
	}

	return false;
}

template<typename alFunction, typename... Params>
auto alCallImpl(
	const char* filename,
	const std::uint_fast32_t line,
	alFunction fn,
	Params... params
) -> typename std::enable_if<!std::is_same_v<void, decltype(fn(params...))>, decltype(fn(params...))> {
	const auto ret = fn(std::forward<Params>(params)...);
	check_al_errors(filename, line);
	return ret;
}

template<typename alFunction, typename... Params>
auto alCallImpl(
	const char* filename,
	const std::uint_fast32_t line,
	alFunction fn,
	Params... params
) -> typename std::enable_if<std::is_same_v<void, decltype(fn(params...))>, bool> {
	fn(std::forward<Params>(params)...);
	return check_al_errors(filename, line);
}
}
