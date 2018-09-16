#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>

class Buffer
{
private:
	GLuint _bufferID;
	//for example the component count for a 3D position is 3 (XYZ)
	//for a color its 4 (RGBA) etc..
	GLuint _componentCount; 
	GLsizei _size;
public:
	Buffer(GLfloat* data, GLsizei size, GLuint componentCnt);
	~Buffer();

	void bind() const;
	void unbind() const;

	inline GLuint getComponentCount() const { return _componentCount;  }
};

