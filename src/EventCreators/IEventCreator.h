#pragma once
#include "../Stores/IStore.h"

class IEventCreator
{
private:
protected:
	IStore *Store;
	virtual void CreateEvent();

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

void IEventCreator::CreateEvent()
{
	// printf("Creating event\n");
}