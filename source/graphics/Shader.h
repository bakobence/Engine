#pragma once

#include <glad\glad.h>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
	GLuint ID;
	const char * _vertexPath;
	const char * _fragmentPath;
public:

	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void use();

	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	void setVec2(std::string const& name, glm::vec2 value) const;
	void setVec3(std::string const& name, glm::vec3 value) const;
	void setVec4(std::string const& name, glm::vec4 value) const;

	void setMat4(const std::string &name, glm::mat4 value) const;


private:
	void checkCompileErrors(unsigned int shader, std::string type);

};

