// #include "imgui/imgui.h"
// #include "imgui/backends/imgui_impl_win32.h"
// #include "imgui/backends/imgui_impl_dx11.h"

#include "../Core/Core.cpp"
using namespace TimeTracker;

namespace TimeTracker::GUI
{
	class Gui
	{
	private:
	protected:
		void Update();
		Core::Core *Core;
	public:
		Gui();
		~Gui();
		void Run();
	};

	Gui::Gui()
	{
		Core = new Core::Core();
	}

	Gui::~Gui()
	{
	}

	void Gui::Run()
	{
		while (true)
		{
			Update();
			Core->Update();
		}
	}

	void Gui::Update()
	{
	}
}