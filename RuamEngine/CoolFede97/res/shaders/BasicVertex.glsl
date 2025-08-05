#version 330 core

layout(location = 0) in vec4 vertex_pos;
layout(location = 1) in vec2 vi_texCoord;

out vec2 vo_texCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
gl_Position = u_projection * u_view * u_model * vertex_pos;
vo_texCoord = vi_texCoord;
};