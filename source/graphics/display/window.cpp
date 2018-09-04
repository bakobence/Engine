#include "window.h"
/* 
bool Window::_keys[MAX_KEYS];
bool Window::_mouse_keys[MAX_MOUSE_KEYS];
double Window::_mX;
double Window::_mY;
*/


Window::Window()
{
	//Not sure what to do here, probably nothing.
}

Window::~Window()
{
	glfwTerminate();
}

void Window::create(const int & width, const int & height, const char * title) 
{
	/* init members */
	_screen_width = width;
	_screen_height = height;
	_title = title;
	_closed = false;
	for (int i = 0; i < MAX_KEYS; i++) _keys[i] = false;
	for (int i = 0; i < MAX_MOUSE_KEYS; i++) _mouse_keys[i] = false;

	if (!glfwInit())
	{
		std::cout << "GLFW::ERROR::GLFWINIT\n"
			      << "Terminating\n";
		_closed = true;
		glfwTerminate();
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_screen_width, _screen_height, _title, nullptr, nullptr);

	if (!_window)
	{
		std::cout << "GLFW::ERROR:CREATEWINDOW\n"
			      << "Terminating\n";
		_closed = true;
		glfwTerminate();
	}
	glfwMakeContextCurrent(_window);

	/* Giving the Window class the ability to use the GLFWwindow* object */
	glfwSetWindowUserPointer(_window, this);

	/* Setting up callbacks for input */
	glfwSetKeyCallback(_window, key_callback);
	glfwSetMouseButtonCallback(_window, mousekey_callback);
	glfwSetCursorPosCallback(_window, mousepos_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD::ERROR:GLADLOADER\n"
			      << "Teminating\n";
		_closed = true;
		glfwTerminate();
	}

	glViewport(0, 0, _screen_width, _screen_height);

	
}

bool Window::Closed() const
{
	return glfwWindowShouldClose(_window) == 1;
}

void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update() const
{
	glfwPollEvents();
	glfwSwapBuffers(_window);
}

void Window::Terminate() const
{
	glfwTerminate();
}

bool Window::isKeyPressed(unsigned int keycode) const
{
	if (keycode > MAX_KEYS)
		return false;
	else
		return _keys[keycode];
}

bool Window::isMouseKeyPressed(unsigned int keycode) const
{
	if (keycode > MAX_MOUSE_KEYS)
		return false;
	else
		return _mouse_keys[keycode];
}

void Window::getMousePos(double& xp, double& yp) const
{
	xp = _mX;
	yp = _mY;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->_keys[key] = action != GLFW_RELEASE;
}

void mousekey_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->_mouse_keys[button] = action != GLFW_RELEASE;
}

void mousepos_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->_mX = xpos;
	win->_mY = ypos;
}


