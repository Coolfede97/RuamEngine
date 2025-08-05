#pragma once

#include <iostream>
#include <Vec3.h>
#include <Vec4.h>
#include <Vec2.h>
#include <array>

class Vertex
{
public:
	Vertex();
	~Vertex();

	Vec3 position;  // x, y, z	
	Vec4 color;     // r, g, b, a
	Vec2 texCoords; // u, v
	float texId;    // Texture ID

	static std::array<Vertex, 4> CreateQuad(float x = 0, float y = 0, float texID = 0);

private:
};