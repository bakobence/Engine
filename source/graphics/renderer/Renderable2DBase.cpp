#include "Renderable2DBase.h"

Renderable2DBase::Renderable2DBase(glm::vec4 position, glm::vec3 size, glm::vec4 colour) :
	_position(position), _size(size), _colour(colour)
{
	_vertexArray = std::make_shared<VertexArray>();
	

	GLfloat vertices[] =
	{
		0,			0,			0,
		0,			position.y, 0,
		position.x, position.y, 0,
		position.x, 0,			0
	};

	GLfloat colours[] =
	{
		colour.x, colour.y, colour.z, colour.w,
		colour.x, colour.y, colour.z, colour.w,
		colour.x, colour.y, colour.z, colour.w,
		colour.x, colour.y, colour.z, colour.w,
	};

	_vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	_vertexArray->addBuffer(new Buffer(colours,  4 * 4, 4), 1);

	GLushort indicies[] = { 0, 1, 2, 2, 3, 0 };
	_indexBuffer = std::make_shared<IndexBuffer>(indicies, 6);




}