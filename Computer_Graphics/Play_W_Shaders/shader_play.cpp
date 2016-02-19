#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <stdexcept>

using namespace std;

GLFWwindow* gWindow = NULL;

const glm::vec2 SCREEN_SIZE(800,600);

void AppMain(){

	if(!glfwInit())
		throw std::runtime_error("glfw fail");

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	gWindow = glfwCreateWindow((int)SCREEN_SIZE.x, (int)SCREEN_SIZE.y, "OpenGL Tutorial", NULL, NULL);
	if(!gWindow)
		throw std::runtime_error("glew init failed");

	glfwMakeContextCurrent(gWindow);

	
}


int main(int argc, char** argv){

	try{
		AppMain();
	}catch (const std::exception &e){
		std::cerr << "Error: " << e.what() << endl;
		return EXIT_FAILURE;
	}

	return 0;
}
