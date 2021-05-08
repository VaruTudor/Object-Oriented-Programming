#pragma once
#include "Service.h"

class UI
{
private:
	Service service;


public:
	UI(const Service& service) : service(service) {};

	void run();

private:

	void list_all_ui();
};

