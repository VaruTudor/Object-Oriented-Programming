#pragma once

#include "Observer.h"
#include <vector>

class Subject {
private:
	std::vector<Observer*> observers;
public:
	void unregisterObserver(Observer* observer);
	void registerObserver(Observer* observer);
	void notify();
};