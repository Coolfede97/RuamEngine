#pragma once

#include "Wave.hpp"

namespace AudioSystem {
#include "al-wrapper.hpp"
#include "alc-wrapper.hpp"

void init();
void init(const char* device);

void shutdown();

ALC::Device device();
ALC::Context context();
} 
