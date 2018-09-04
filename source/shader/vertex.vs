#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColors;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
	vertexColor = vec4(aColors, 1.0);
}