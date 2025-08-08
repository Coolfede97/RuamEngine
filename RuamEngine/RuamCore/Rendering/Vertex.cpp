#include "Vertex.h"


std::array<VertexWithTex, 4> VertexWithTex::CreateQuad(float x, float y, float texID)
{
	float size = 1.0f;
	float half = size/2;

	VertexWithTex v0;
	v0.position = { -half + x, -half + y, 0.0f };
	v0.texCoords = { 0.0f, 0.0f };
	v0.texId = texID;

	VertexWithTex v1;
	v1.position = { half + x, -half + y, 0.0f };
	v1.texCoords = { 1.0f, 0.0f };
	v1.texId = texID;

	VertexWithTex v2;
	v2.position = { half + x, half + y, 0.0f };
	v2.texCoords = { 1.0f, 1.0f };
	v2.texId = texID;

	VertexWithTex v3;
	v3.position = { -half + x, half + y, 0.0f };
	v3.texCoords = { 0.0f, 1.0f };
	v3.texId = texID;

	return { v0, v1, v2, v3 };
}
