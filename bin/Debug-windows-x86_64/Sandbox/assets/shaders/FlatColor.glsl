#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_Position;
out vec4 v_Color;

void main()
{
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
	v_Color = vec4(1.0, 0.0, 1.0, 0.5);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;			

in vec4 v_Color;

void main()
{
	color = u_Color;
}