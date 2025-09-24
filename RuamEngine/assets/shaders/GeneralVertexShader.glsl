#version 330 core

layout(location = 0) in vec4 vertex_pos;
layout(location = 1) in vec4 vertex_color;

//uniform vec4 u_albedoColor;
//uniform float u_metallic;
//uniform float u_roughness;
//uniform float u_ambientOcclusion;
//uniform float u_emissiveStrength;
//
//uniform sampler2D u_albedoMap;
//uniform sampler2D u_normalMap;
//uniform sampler2D u_metallicMap;
//uniform sampler2D u_roughnessMap;
//uniform sampler2D u_AOMap;
//uniform sampler2D u_emissiveMap;
 
uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec4 frag_color;

void main()
{
	gl_Position = u_projection * u_view * u_model * vertex_pos;
	frag_color = vertex_color;
};