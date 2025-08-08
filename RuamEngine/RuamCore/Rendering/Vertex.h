#pragma once

#include <iostream>
#include <Vec3.h>
#include <Vec4.h>
#include <Vec2.h>
#include <array>

struct Vertex
{
	Vec3 position;  // x, y, z	
};

struct VertexWithTex : Vertex
{
	Vec2 texCoords; // u, v
	float texId;
	static std::array<VertexWithTex, 4> CreateQuad(float x = 0, float y = 0, float texID = 0);
};