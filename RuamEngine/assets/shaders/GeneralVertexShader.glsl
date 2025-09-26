#version 330 core

layout(location = 0) in vec4 vertex_pos;
layout(location = 1) in vec4 vertex_color;
 
uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec4 frag_vertexColor;

void main()
{
	gl_Position = u_projection * u_view * u_model * vertex_pos;
	frag_vertexColor = vertex_color;
};