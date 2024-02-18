#pragma once
#include <vector>
#include "../Event/Event.cpp"

class IStore
{
private:
protected:
public:
	virtual void AddEvent(Event *event) = 0;
	virtual void AddEvents(std::vector<Event *> events) = 0;
};