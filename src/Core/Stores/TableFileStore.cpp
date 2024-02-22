#pragma once
#include <vector>
#include "../Event/Event.cpp"
#include "IStore.h"
#include <fstream>
using namespace std;

namespace TimeTracker::Core
{
	class TableFileStore : public IStore
	{
	private:
		string CreateRow(vector<string> columns);

	protected:
		string FilePath = "";
		string Separator = "";
		ofstream File;

	public:
		TableFileStore(string filePath, string separator);

		virtual void AddEvent(Event *event) override;
		virtual void AddEvents(std::vector<Event *> events) override;
	};

	TableFileStore::TableFileStore(string filePath, string separator)
	{
		FilePath = filePath;
		Separator = separator;

		// open the file
		File.open(FilePath, ios::out);

		// write the header
		auto headerLine = CreateRow({"Start Time", "End Time", "Name"});
		File << headerLine;
		File.close();
	}

	void TableFileStore::AddEvent(Event *event)
	{
		File.open(FilePath, ios::app);

		// write the event to the file
		auto startTime = event->TimeToString(event->StartTime);
		auto endTime = event->TimeToString(event->EndTime);

		auto row = CreateRow({startTime, endTime, event->Name});
		File << row;
		File.close();
	}

	void TableFileStore::AddEvents(std::vector<Event *> events)
	{
		for (auto event : events)
		{
			AddEvent(event);
		}
	}

	string TableFileStore::CreateRow(vector<string> columns)
	{
		auto length = columns.size();
		string row = "";
		for (size_t i = 0; i < length; i++)
		{
			row += columns[i];
			if (i < length - 1)
			{
				row += Separator;
			}
		}

		return row + "\n";
	}
}