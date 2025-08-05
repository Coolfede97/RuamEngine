#version 330 core
out vec4 color;
        
uniform vec4 u_Color;
uniform sampler2D u_Texture;

in vec2 vo_texCoord;

void main()
{
vec4 texColor =  texture(u_Texture, vo_texCoord);
color = texColor;
};