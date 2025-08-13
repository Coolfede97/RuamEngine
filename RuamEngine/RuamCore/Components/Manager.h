#pragma once

#include <Component.hpp>

class Manager : public Component
{
	void update() override;
	void render() override;
	void imguiRender() override;

	// Heredado v�a Component
	void start() override;
};