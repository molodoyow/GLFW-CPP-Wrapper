#ifndef H_WINDOWGLFW
#define H_WINDOWGLFW

#include "ContextGLFW.h"
//GLFW
#include <GLFW/glfw3.h>

//STL
#include <string_view>

class WindowGLFW
{
public:
	WindowGLFW();
	
	struct Size 
	{
		int width;
		int height;
	};
	
	struct Position
	{
		int x;
		int y;
	};
	
	struct Hint
	{
		int hint;
		int value;
	};
	
	struct Attributes
	{
		std::size_t width = 640;
		std::size_t height = 480;
		std::string_view title = "WindowGLFW";
		bool VSync = true;
		bool FullScreenMode = false;
		bool Maximized = false;
	};
	
	WindowGLFW(const Attributes& attributes);

	void PollEvents();
	void SwapBuffers();
	void SetHint(int hint, int value);
public:
	bool Create();		
	
	template<typename RenderProcedure>
	requires std::is_invocable_v<RenderProcedure>
	void Process(RenderProcedure&& render_procedure)
	{
		while(!ShouldClose())
		{
			render_procedure();
			
			// Doing default GLFW stuff: catching window events and swap window buffers
			PollEvents();
			SwapBuffers();
		}
	}
	
	bool ShouldClose() const noexcept;
	Size GetSize() const noexcept;
	Position GetPosition() const noexcept;
	std::string_view GetTitle() const noexcept;
	std::string_view GetClipboard() const noexcept;
	bool IsKeyPressed(int key);
	bool IsMouseButtonPressed(int button);
	
	void Show();
	void Hide();
	void Close();
	void Maximize();
	void Iconify();
	void Restore();
	void Focus();
	void SetFullScreenMode();
	void SetWindowMode();
	void SetSize(int width, int height);
	void SetPosition(int x, int y);
	void SetLimits(int min_width, int min_height, int max_width, int max_height);
	void SetTitle(std::string_view title);
	
	~WindowGLFW();
private:	
	Attributes attributes_;
	GLFWwindow* handle_;
	ContextGLFW context;
};
#endif
