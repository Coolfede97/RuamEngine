#pragma once

#include <Component.hpp>

class Manager : public Component
{
	void update() override;
	void render() override;
	void imguiRender() override;

	// Heredado vía Component
	void start() override;
};