#include "vertexarray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_arrayID);
}

VertexArray::~VertexArray()
{
	for (auto buffer : _buffers) delete buffer;
}

void VertexArray::bind() const
{
	glBindVertexArray(_arrayID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::addBuffer(Buffer * buffer, GLuint attribIndex)
{
	bind();
	buffer->bind();
	glVertexAttribPointer(attribIndex, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(attribIndex);
	buffer->unbind();
	unbind();
}