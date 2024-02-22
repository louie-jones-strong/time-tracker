#include <windows.h>
#include <iostream>
#include <vector>
#include "src/EventCreators/FocusedWindowEventCreator.cpp"
#include "src/Stores/ConsoleStore.cpp"
#include "src/Stores/TableFileStore.cpp"

using namespace std;

vector<IEventCreator *> CreateEventCreators()
{
    // auto store = new ConsoleStore();
    auto store = new TableFileStore("tracked.tsv", "\t");

    vector<IEventCreator *> eventCreators;
    eventCreators.push_back(new FocusedWindowEventCreator(store));
    return eventCreators;
}

void UpdateEventCreators(vector<IEventCreator *> eventCreators)
{
    for (auto eventCreator : eventCreators)
    {
        eventCreator->Update();
    }
}

int main()
{
    printf("Time Tracker running...\n");

    printf("\n");
    auto eventCreators = CreateEventCreators();

    while (true)
    {
        UpdateEventCreators(eventCreators);
        Sleep(100);
    }

    return 0;
}
