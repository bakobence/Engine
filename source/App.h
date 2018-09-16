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
	//Instance of the singleton
	static App* instance;
	//prevent construction
	App();


	//rest of the members
	Window _window;


public:
	//getting the instance of the singleton
	static App* getInstance();


	void run();

};

