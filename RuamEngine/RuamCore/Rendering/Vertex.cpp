#include "Vertex.h"

Vertex::Vertex()
	: position{0.0f, 0.0f, 0.0f},
	  color{1.0f, 1.0f, 1.0f, 1.0f},
	  texCoords{0.0f, 0.0f},
	  texId(0.0f)
{
}

Vertex::~Vertex()
{
}

std::array<Vertex, 4> Vertex::CreateQuad(float x, float y, float texID)
{
	float size = 1.0f;
	float half = size/2;

	Vertex v0;
	v0.position = { -half + x, -half + y, 0.0f };
	v0.color = { 0.2f, 0.2f, 0.27f, 1.0f };
	v0.texCoords = { 0.0f, 0.0f };
	v0.texId = texID;

	Vertex v1;
	v1.position = { half + x, -half + y, 0.0f };
	v1.color = { 0.2f, 0.2f, 0.27f, 1.0f };
	v1.texCoords = { 1.0f, 0.0f };
	v1.texId = texID;

	Vertex v2;
	v2.position = { half + x, half + y, 0.0f };
	v2.color = { 0.2f, 0.2f, 0.27f, 1.0f };
	v2.texCoords = { 1.0f, 1.0f };
	v2.texId = texID;

	Vertex v3;
	v3.position = { -half + x, half + y, 0.0f };
	v3.color = { 0.2f, 0.2f, 0.27f, 1.0f };
	v3.texCoords = { 0.0f, 1.0f };
	v3.texId = texID;

	return { v0, v1, v2, v3 };
}
