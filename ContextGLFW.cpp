#include "ContextGLFW.h"
#include <GLFW/glfw3.h>

ContextGLFW::ContextGLFW()
{
	glfwInit();
}

ContextGLFW::~ContextGLFW()
{
	glfwTerminate();
}