#include "App.h"

#define WIDTH 800
#define HEIGHT 600

float pos[] =
{
	-0.5f , -0.5f , 0.0f,
	 0.5f , -0.5f , 0.0f,
	-0.5f ,  0.5f , 0.0f,
	 0.5f , 0.5f , 0.0f,
};

float colors[] =
{
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.5f,
};


GLushort ind[] =
{
	0, 1, 3,
	0, 2, 3
};



App::App()
{
	_window.create(WIDTH, HEIGHT, "Engine");
}


App::~App()
{
}


void App::run()
{
	std::cout << glGetString(GL_VERSION) << std::endl;
	
	VertexArray vao;
	Buffer* positionBuffer = new Buffer(pos, 4 * 3, 3);
	Buffer* colorBuffer = new Buffer(colors, 4 * 3, 3);
	IndexBuffer indexBuffer(ind, 6);

	vao.addBuffer(positionBuffer, 0);
	vao.addBuffer(colorBuffer, 1);

	Shader _shader("source/shader/vertex.vs", "source/shader/fragment.fs");
	_shader.use();


	while (!_window.Closed())
	{
		_window.Clear();

		_shader.use();
		vao.bind();
		indexBuffer.bind();

		glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_SHORT, 0);

		indexBuffer.bind();
		vao.unbind();

		_window.Update();
		
		//if (_window.isKeyPressed(GLFW_KEY_A))  std::cout << "pressed" << std::endl;
		//if (_window.isMouseKeyPressed(GLFW_MOUSE_BUTTON_LEFT)) std::cout << "pressed" << std::endl;
		//_window.getMousePos(xpos, ypos);
		//std::cout << xpos << " " << ypos << std::endl;

	}

	_window.Terminate();
}


