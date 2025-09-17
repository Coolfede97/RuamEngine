#pragma once

#include "glm/glm.hpp"
#include <iostream>

#if defined(_WIN32)
#define ASSERT(x) do {if(!(x)) __debugbreak();} while(false)
#endif
#ifdef linux
#include <csignal>
#include <cstdio>
#define ASSERT(x) do {if(!(x)) { fprintf(stderr, #x " (%s:%d)\n", __FILE__, __LINE__); raise(SIGTRAP);}} while (false)
#endif

inline std::ostream& operator<<(std::ostream& os, const glm::vec3& vec) {
	return os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ')';
}
