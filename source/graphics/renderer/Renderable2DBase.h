 /*
 *	Every object that is renderable in a 2D scene
 *	will be inherited from this interface.
 */

#pragma once

#include <glad\glad.h>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>

#include "buffers\buffer.h"
#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"

#include <memory>



class Renderable2DBase
{
protected:
	glm::vec3 _position;
	glm::vec2 _size;
	glm::vec4 _colour;

	std::shared_ptr<VertexArray>	_vertexArray;
	std::shared_ptr<IndexBuffer>	_indexBuffer;
	
protected:
	Renderable2DBase(glm::vec4 position, glm::vec3 size, glm::vec4 colour);
	
};