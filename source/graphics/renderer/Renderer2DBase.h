#pragma once

#include "buffers\buffer.h"
#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"

#include "Renderable2DBase.h"

class Renderer2DBase
{
protected:

	void submit(Renderable2DBase* object) = 0;
	void flush(Renderable2DBase* object) = 0;
};