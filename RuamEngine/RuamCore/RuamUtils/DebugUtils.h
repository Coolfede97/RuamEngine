#pragma once

#if defined(_WIN32)
#define ASSERT(x) do {if(!(x)) __debugbreak();} while(false)
#endif
#ifdef linux
#include <csignal>
#include <cstdio>
#define ASSERT(x) do {if(!(x)) { fprintf(stderr, #x " (%s:%d)\n", __FILE__, __LINE__); raise(SIGTRAP);}} while (false)
#endif
