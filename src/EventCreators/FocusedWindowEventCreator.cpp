#include <windows.h>
#include <iostream>
#include <vector>
#include "IEventCreator.h"

using namespace std;

class FocusedWindowEventCreator : public IEventCreator
{
private:
protected:
HWND LastFocusedWindow;
string LastTitle = "";

public:
	FocusedWindowEventCreator(IStore *store);
	void Update() override;
};

FocusedWindowEventCreator::FocusedWindowEventCreator(IStore *store) : IEventCreator(store)
{
	LastFocusedWindow = NULL;
	// printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %s\n",
	// 	   "Foreground", "IsIconic", "IsFocused", "right", "left", "top", "bottom", "width", "height", "Title");
}

string GetWindowData(HWND window)
{

	char title[256];
	RECT rect;

	GetWindowText(window, title, sizeof(title));
	GetWindowRect(window, &rect);

	auto isWindow = IsWindow(window);
	auto isWindowVisible = IsWindowVisible(window);
	auto isWindowEnabled = IsWindowEnabled(window);
	auto isTitleValid = (strlen(title) > 0);
	auto isForegroundWindow = (window == GetForegroundWindow());
	auto isIconic = IsIconic(window);
	bool isFocused = (GetFocus() == window);

	// if (!isWindow || !isWindowVisible || !isWindowEnabled || !isTitleValid)
	// {
	// 	return;
	// }

	signed int width = rect.right - rect.left;
	signed int height = rect.bottom - rect.top;

	// print the window data in a tabular format
	// printf("%-10s %-10s %-10s %-10d %-10d %-10d %-10d %-10d %-10d %s\n",
	// 	   isForegroundWindow ? "Yes" : "No",
	// 	   isIconic ? "Yes" : "No",
	// 	   isFocused ? "Yes" : "No",
	// 	   rect.right,
	// 	   rect.left,
	// 	   rect.top,
	// 	   rect.bottom,
	// 	   width,
	// 	   height,
	// 	   title);

	return title;
}

void FindWindows()
{
	HWND desktop = GetDesktopWindow();
	if (desktop == NULL)
	{
		printf("Error: %d\n", GetLastError());
		return;
	}

	// print the header
	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %s\n",
		   "Foreground", "IsIconic", "IsFocused", "right", "left", "top", "bottom", "width", "height", "Title");

	// loop through all child windows
	HWND child = GetWindow(desktop, GW_CHILD);
	while (child != NULL)
	{
		GetWindowData(child);
		child = GetWindow(child, GW_HWNDNEXT);
	}
}

void FocusedWindowEventCreator::Update()
{
	auto foreground = GetForegroundWindow();
	auto title = GetWindowData(foreground);
	if (title == LastTitle && foreground == LastFocusedWindow)
	{
		return;
	}

	auto event = new Event();
	event->Name = title;
	StoreEvent(event);

	LastTitle = title;
	LastFocusedWindow = foreground;
}