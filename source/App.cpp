#include "App.h"

#define WIDTH 800
#define HEIGHT 600

float pos[] =
{
	4, 3, 0,
	12, 3, 0,
	4, 6, 0,
	12, 6, 0,
	4, 6, 0,
	4, 3, 0
};

float colors[] =
{
	0.15f, 0.26f, 0.7f,
	0.15f, 0.26f, 0.7f,
	0.15f, 0.26f, 0.7f,
	0.15f, 0.26f, 0.7f,
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

App* App::getInstance()
{
	if (!instance)
		instance = new App();

	return instance;
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

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader shader("source/shader/vertex.vs", "source/shader/fragment.fs");
	shader.use();
	shader.setMat4("pr_matrix", ortho);
	//shader.setMat4("ml_matrix", glm::translate(glm::mat4() , glm::vec3(4, 3, 0)));
	shader.setVec2("light_pos", glm::vec2(10.0f, 3.0f));
	shader.setVec4("colour", glm::vec4(0.2f, 0.3f, 0.8f, 1.0f));


	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	double xpos, ypos;
	while (!_window.Closed())
	{
		_window.Clear();

		shader.use();
		vao.bind();
		indexBuffer.bind();

		glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_SHORT, 0);

		indexBuffer.bind();
		vao.unbind();

		_window.Update();
		
		//if (_window.isKeyPressed(GLFW_KEY_A))  std::cout << "pressed" << std::endl;
		//if (_window.isMouseKeyPressed(GLFW_MOUSE_BUTTON_LEFT)) std::cout << "pressed" << std::endl;
		_window.getMousePos(xpos, ypos);
		shader.setVec2("light_pos", glm::vec2((float)(xpos * 16.0f / 800.0f), (float)(9.0f - ypos* 9.0f / 600.0f)));
		std::cout << xpos << " " << ypos << std::endl;

	}

	_window.Terminate();
}


