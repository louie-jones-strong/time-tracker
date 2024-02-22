#include <windows.h>
#include <iostream>
#include <vector>
#include "IStore.h"

using namespace std;


namespace TimeTracker::Core
{
	class ConsoleStore : public IStore
	{
	private:
	protected:
	public:
		ConsoleStore();
		~ConsoleStore();

		void AddEvent(Event *event);
		void AddEvents(std::vector<Event *> events);
	};

	ConsoleStore::ConsoleStore()
	{
	}

	ConsoleStore::~ConsoleStore()
	{
	}

	void ConsoleStore::AddEvent(Event *event)
	{
		auto startTime = ctime(&event->StartTime);
		cout << startTime << " " << event->Name << endl;
	}

	void ConsoleStore::AddEvents(std::vector<Event *> events)
	{
		for (auto event : events)
		{
			AddEvent(event);
		}
	}
}