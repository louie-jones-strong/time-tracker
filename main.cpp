#include <windows.h>
#include <iostream>
#include <vector>
#include "src/EventCreators/FocusedWindowEventCreator.cpp"
#include "src/Stores/ConsoleStore.cpp"

using namespace std;

vector<IEventCreator *> CreateEventCreators()
{
    auto store = new ConsoleStore();

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
    printf("Welcome to Time Tracker!\n");

    printf("\n");
    auto eventCreators = CreateEventCreators();

    while (true)
    {
        UpdateEventCreators(eventCreators);
        Sleep(100);
    }

    return 0;
}
