#include "buffer.h"

Buffer::Buffer(GLfloat* data, GLsizei size, GLuint componentCnt)
	: _componentCount(componentCnt)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void Buffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}

void Buffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

