#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextureCoords;

uniform mat4 u_View;
uniform mat4 u_Projection;
uniform mat4 u_Model;

out vec2 v_TextureCoords;

void main()
{
    v_TextureCoords = a_TextureCoords;
	gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;	

in vec2 v_TextureCoords;

uniform sampler2D u_Texture;

void main()
{
	color = texture(u_Texture, v_TextureCoords);
}