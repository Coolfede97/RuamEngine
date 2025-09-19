#pragma once

#include "Wave.hpp"
#include "al-wrapper.hpp"
#include "alc-wrapper.hpp"

namespace AudioSystem {

static std::thread worker;
static std::atomic<bool> free_worker = true;

void init();
void init(const char* device);

void shutdown();

ALC::Device device();
ALC::Context context();
} 
