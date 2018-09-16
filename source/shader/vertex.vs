#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColors;

out vec4 vertexColor;
out vec4 pos;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

void main()
{
    gl_Position = pr_matrix * vw_matrix * ml_matrix * vec4(aPos, 1.0);
	vertexColor = vec4(aColors, 1.0);
	pos = vec4(aPos, 1.0);
}