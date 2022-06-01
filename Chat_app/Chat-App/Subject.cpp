#include "Subject.h"

void Subject::unregisterObserver(Observer* observer) {
	auto observerIterator = std::find(begin(observers), end(observers), observer);
	if (observerIterator != end(observers)) {
		observers.erase(observerIterator);
	}
}

void Subject::registerObserver(Observer* observer) {
	observers.push_back(observer);
}

void Subject::notify() {
	for (auto& observer : observers) {
		observer->update();
	}
}