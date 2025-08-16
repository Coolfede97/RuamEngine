#include "Vertex.h"


std::array<Vertex, 4> Vertex::CreateQuad(float x, float y, Vec4 color)
{
	float size = 1.0f;
	float half = size / 2;
	Vertex v0;
	v0.position = { x - half, y - half, 0.0f };
	v0.color = new Vec4(0.49f, 0.55f, 0.52f, 1.0f);
	Vertex v1;
	v1.position = { x + half, y - half, 0.0f };
	v1.color = new Vec4(0.49f, 0.55f, 0.52f, 1.0f);
	Vertex v2;
	v2.position = { x + half, y + half, 0.0f };
	v2.color = new Vec4(0.49f, 0.55f, 0.52f, 1.0f);
	Vertex v3;
	v3.position = { x - half, y + half, 0.0f };
	v3.color = new Vec4(0.49f, 0.55f, 0.52f, 1.0f);
	return { v0, v1, v2, v3 };
}

std::array<VertexWithTex, 4> VertexWithTex::CreateQuad(float x, float y, float texID)
{
	float size = 1.0f;
	float half = size/2;

	VertexWithTex v0;
	v0.position = { x - half, y - half, 0.0f };
	v0.texCoords = { 0.0f, 0.0f };
	v0.texId = texID;

	VertexWithTex v1;
	v1.position = { x + half, y - half, 0.0f };
	v1.texCoords = { 1.0f, 0.0f };
	v1.texId = texID;

	VertexWithTex v2;
	v2.position = { x + half, y + half, 0.0f };
	v2.texCoords = { 1.0f, 1.0f };
	v2.texId = texID;

	VertexWithTex v3;
	v3.position = { x - half, y + half, 0.0f };
	v3.texCoords = { 0.0f, 1.0f };
	v3.texId = texID;

	return { v0, v1, v2, v3 };
}
