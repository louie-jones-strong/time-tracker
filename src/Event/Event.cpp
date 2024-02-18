#pragma once
#include <string>

using namespace std;

class Event
{
private:
protected:
public:
	int Version;

	time_t StartTime;
	time_t EndTime;

	string Name = "";

	// string Description;
	// categories
	// status
	// location
	// participants
	// recurrence
	// links

	Event();
};

Event::Event()
{
	Version = 1;
	StartTime = time(0);
	EndTime = time(0);
}