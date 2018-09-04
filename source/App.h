#pragma once

#include "graphics\display\window.h"
#include "graphics\renderer\buffers\buffer.h"
#include "graphics\renderer\buffers\vertexarray.h"
#include "graphics\renderer\buffers\indexbuffer.h"
#include "graphics\Shader.h"

#include <iostream>

class App
{
private:
	Window _window;
public:
	App();
	~App();

	void run();

};

