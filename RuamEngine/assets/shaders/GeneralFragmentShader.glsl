#version 330 core

out vec4 final_color;

in vec4 frag_vertexColor;

uniform vec4  u_albedoColor;
uniform float u_metallic;
uniform float u_roughness;
uniform float u_ambientOcclusion;
uniform float u_emissiveStrength;

//uniform sampler2D u_albedoMap;
//uniform sampler2D u_normalMap;
//uniform sampler2D u_metallicMap;
//uniform sampler2D u_roughnessMap;
//uniform sampler2D u_AOMap;
//uniform sampler2D u_emissiveMap;

void main()
{
    final_color = frag_vertexColor * u_albedoColor;
}
