#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "buffer.h"

#include <vector>


class VertexArray {
private:
	GLuint _arrayID;
	std::vector<Buffer* > _buffers;
public:
	VertexArray();
	~VertexArray();

	void bind() const;
	void unbind() const;

	void addBuffer(Buffer* buffer, GLuint attribIndex);
};