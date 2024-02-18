#pragma once
#include "../Stores/IStore.h"

class IEventCreator
{
private:
protected:
	IStore *Store;
	virtual void StoreEvent(Event *event);

public:
	IEventCreator(IStore *store);

	~IEventCreator();

	virtual void Update() = 0;
};

IEventCreator::IEventCreator(IStore *store)
{
	Store = store;
}

IEventCreator::~IEventCreator()
{
}

void IEventCreator::StoreEvent(Event *event)
{
	Store->AddEvent(event);
}