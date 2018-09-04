#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>

class IndexBuffer
{
private:
	GLuint _bufferID;
	GLsizei	_count; // How many draw calls we have to make
public:
	IndexBuffer(GLushort* data, GLsizei count);

	void bind() const;
	void unbind() const;

	inline GLuint getCount() const { return _count; }

};

