#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <iostream>

#define MAX_KEYS	   1024
#define MAX_MOUSE_KEYS 32

class Window
{
private:
	GLFWwindow * _window;

	const char * _title;
	int _screen_width;
	int _screen_height;
	bool _closed;

	bool _keys[MAX_KEYS];
	bool _mouse_keys[MAX_MOUSE_KEYS];
	double _mX, _mY;
public:
	Window();
	~Window();
	void create(const int&, const int&, const char *);
	
	bool Closed() const;
	void Terminate() const;
	void Update() const;
	void Clear() const;
   
	bool isKeyPressed(unsigned int keycode) const ;
	bool isMouseKeyPressed(unsigned int keycode) const ;
	void getMousePos(double& xp, double& yp) const;
private:
	friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend static void mousekey_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void mousepos_callback(GLFWwindow* window, double xpos, double ypos);
};


