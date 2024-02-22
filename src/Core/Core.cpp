#pragma once

#include <windows.h>
#include <iostream>
#include <vector>
#include "EventCreators/FocusedWindowEventCreator.cpp"
#include "Stores/ConsoleStore.cpp"
#include "Stores/TableFileStore.cpp"

namespace TimeTracker::Core
{
	class Core
	{
	private:
	protected:
	vector<IEventCreator *> EventCreators;
	public:
		Core();
		~Core();

		void Update();
		void Run();
	};

	Core::Core()
	{
		// auto store = new ConsoleStore();
		auto store = new TableFileStore("tracked.tsv", "\t");

		EventCreators.push_back(new FocusedWindowEventCreator(store));
	}

	Core::~Core()
	{

	}

	void Core::Run()
	{
		while (true)
		{
			Update();
			Sleep(100);
		}
	}

	void Core::Update()
	{
		for (auto eventCreator : EventCreators)
		{
			eventCreator->Update();
		}
	}
}
