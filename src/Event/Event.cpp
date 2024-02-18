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

	string TimeToString(time_t time)
	{
		string output = asctime(localtime(&time));

		// remove the newline
		output.pop_back();

		return output;
	}
};

Event::Event()
{
	Version = 1;
	StartTime = time(0);
	EndTime = time(0);
}