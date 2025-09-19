#pragma once

#include "Wave.hpp"
#include "al-wrapper.hpp"
#include "alc-wrapper.hpp"
#include "ThreadPool.h"

namespace AudioSystem {

static thread_pool pool(2);

void init();
void init(const char* device);

void shutdown();

ALC::Device device();
ALC::Context context();
} 
