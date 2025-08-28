#pragma once

#if defined(_WIN32)
#define ASSERT(x) do {if(!(x)) __debugbreak();} while(false)
#endif
#ifdef linux
#include <csignal>
#define ASSERT(x) do {if(!(x)) raise(SIGTRAP);} while (false)
#endif
