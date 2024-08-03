#include "WindowGLFW.h"
#include <iostream>

WindowGLFW::WindowGLFW():
	handle_(nullptr) {};
			
WindowGLFW::WindowGLFW(const Attributes& attributes):
	attributes_(attributes) {};


void WindowGLFW::PollEvents()
{
	glfwPollEvents();
}

void WindowGLFW::SwapBuffers()
{
	glfwSwapBuffers(handle_);
}

void WindowGLFW::SetHint(int hint, int value)
{
	glfwInitHint(hint, value);
}

bool WindowGLFW::Create()
{
	glfwSetErrorCallback([](int error, const char* description) 
	{
		std::cerr << "[GLFW error] " << error << " " << description << std::endl;
	});
		
	GLFWmonitor* monitor = attributes_.FullScreenMode ? glfwGetPrimaryMonitor() : nullptr;
	handle_ = glfwCreateWindow(attributes_.width, attributes_.height, attributes_.title.data(), monitor, nullptr);
	
	glfwMakeContextCurrent(handle_);
	if(attributes_.VSync)
		glfwSwapInterval(1); 
	if(attributes_.Maximized)
		glfwMaximizeWindow(handle_);
	
	return handle_ != nullptr;
}

bool WindowGLFW::ShouldClose()
{
	return glfwWindowShouldClose(handle_);
}

WindowGLFW::Size WindowGLFW::GetSize()
{
	int width, height;
	glfwGetWindowSize(handle_, &width, &height);
	return { width, height };
}

WindowGLFW::Position WindowGLFW::GetPosition()
{
	int x, y;
	glfwGetWindowPos(handle_, &x, &y);
	return { x, y };
}

std::string_view WindowGLFW::GetTitle()
{
	return glfwGetWindowTitle(handle_);
}

std::string_view WindowGLFW::GetClipboard()
{
	return glfwGetClipboardString(handle_);
}

bool WindowGLFW::IsKeyPressed(int key)
{
	return glfwGetKey(handle_, key) == GLFW_PRESS;
}

bool WindowGLFW::IsMouseButtonPressed(int button)
{
	return glfwGetMouseButton(handle_, button) == GLFW_PRESS;
}

void WindowGLFW::Show()
{
	glfwShowWindow(handle_);
}

void WindowGLFW::Hide()
{
	glfwHideWindow(handle_);
}

void WindowGLFW::Close()
{
	glfwSetWindowShouldClose(handle_, 1);
}

void WindowGLFW::Maximize()
{
	glfwMaximizeWindow(handle_);
}

void WindowGLFW::Iconify()
{
	glfwIconifyWindow(handle_);
}

void WindowGLFW::Restore()
{
	glfwRestoreWindow(handle_);
}

void WindowGLFW::Focus()
{
	glfwFocusWindow(handle_);
}

void WindowGLFW::SetFullScreenMode()
{
	Size size = GetSize();
	glfwSetWindowMonitor(handle_, glfwGetPrimaryMonitor(), 
		GLFW_POSITION_X, GLFW_POSITION_Y, size.width, size.height, 0);
}

void WindowGLFW::SetWindowMode()
{
	Size size = GetSize();
	glfwSetWindowMonitor(handle_, 0, 
		GLFW_POSITION_X, GLFW_POSITION_Y, size.width, size.height, 0);
}

void WindowGLFW::SetSize(int width, int height)
{
	glfwSetWindowSize(handle_, width, height);
}

void WindowGLFW::SetPosition(int x, int y)
{
	glfwSetWindowPos(handle_, x, y);
}

void WindowGLFW::SetLimits(int min_width, int min_height, int max_width, int max_height)
{
	glfwSetWindowSizeLimits(handle_, min_width, min_height, max_width, max_height);
}

void WindowGLFW::SetTitle(std::string_view title)
{
	glfwSetWindowTitle(handle_, title.data());
}
