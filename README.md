# C++ Wrapper for GLFW Library

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
![screenshot](https://github.com/user-attachments/assets/a9be9e5c-d9f5-4fc4-afa1-fa11b55c9b28)

## API overview

```cpp
class WindowGLFW
{
public:
  	bool Create();

	template<typename RenderProcedure>
	requires std::is_invocable_v<RenderProcedure>
	void Process(RenderProcedure&& render_procedure)
	{
		while(!ShouldClose())
		{
			render_procedure();
			
			// Doing default GLFW stuff: catching window events
			// and swapping window buffers
			PollEvents();
			SwapBuffers();
		}
	}
	
	bool ShouldClose() const noexcept;
	Size GetSize() const noexcept;
	Position GetPosition() const noexcept;
	std::string_view GetTitle() const noexcept;
	std::string_view GetClipboard() const noexcept;
	
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
