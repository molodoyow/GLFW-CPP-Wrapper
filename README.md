# RAII C++ Wrapper for GLFW Library

## Usage sample
```cpp
#include "WindowGLFW.h"

int main()
{
	const WindowGLFW::Attributes window_attributes
	{
		.width = 480,
		.height = 320,
		.title = "My Window",
	};
	WindowGLFW window(window_attributes);
	window.Create();
	window.Process([]()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	});
}
```
![capture](https://github.com/user-attachments/assets/fee3e10e-260c-405a-ae73-ec9a097ac268)

## API overview

```cpp
class WindowGLFW
{
public:
  	bool Create();

	template<typename RenderProcedure>
	void Process(RenderProcedure&& render_procedure)
	{
		while(!ShouldClose())
		{
			render_procedure();
			
			// Doing default GLFW stuff: catching window events
			//and swapping window buffers
			PollEvents();
			SwapBuffers();
		}
	}
	
	bool ShouldClose();
	Size GetSize();
	Position GetPosition();
	std::string_view GetTitle();
	std::string_view GetClipboard();
	
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
}
```
