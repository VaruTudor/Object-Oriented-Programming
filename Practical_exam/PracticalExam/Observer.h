#pragma once

#include <vector>

/*
	Observer - Abstract class
	update method needs to be implemented by observers
*/
class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};


/*
	Observable or Subject - class that notifies changes in its state
	Derive from this class if you want to provide notifications
*/
class Observable
{
private:
	//Non-owning pointers to observer instances
	std::vector<Observer*> observers;
public:
	virtual ~Observable() {}

	void addObserver(Observer* obs)
	{
		observers.push_back(obs);
	}

	void notify()
	{
		for (auto obs : observers)
		{
			obs->update();
		}
	}
};