#pragma once

#include <iostream>
#include <Vec3.h>
#include <Vec4.h>
#include <Vec2.h>
#include <array>

#include "GLM/glm.hpp"

struct Vertex
{
	Vec3 position;  // x, y, z	
	Vec4* color;    // r, g, b, a
	static std::array<Vertex, 4> CreateQuad(float x = 0, float y = 0, Vec4 color = Vec4(0.49f, 0.55f, 0.52f, 1.0f));
};

struct VertexWithTex
{
	Vec3 position;  // x, y, z	
	Vec2 texCoords; // u, v
	float texId;
	static std::array<VertexWithTex, 4> CreateQuad(float x = 0, float y = 0, float texID = 0);
};
