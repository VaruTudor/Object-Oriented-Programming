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

	void list_all_form_assistant_ui();

	void list_by_place_of_origin(std::string place_of_origin, int age);

	void list_filtered(int age);
};

